#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdio>

using namespace std;

//defining a RGB struct to color the pixel
struct Type_rgb {
       float r;
       float g;
       float b;
};

/* pixel variable contain the value of the color pixel in the picture.
   pattern is a predefine set of color for a particular value. */

struct Type_rgb pixels[841*1440], pattern[999];
//struct Type_rgb pixels[600 * 800], pattern[999];

/* function mandelbrotset find where the number is in mandelbrotset or not 
   and also assign a color to that coordinate with that iteration pattern. */

void mandelbrotset()
{
/* x0 :- is the real part of c value will range from -2.5 to 1.1.
   y0 :- is the imaginary part of c value will range from -1 to 1.1.
   x and y :- is the real and imaginary part of Zn.
   iteration :- is to keep control variable of the number of iteration
   max_iteration :- maximum number of iteration
   loc :- represent the location pixel of the current x,y coordinate. */
	
	float x0, y0, x, y, xtemp;
	int iteration, max_iteration, loc;
	
	loc = 0;
	printf("\nstart");

	for(float y0 = -1; y0 < 1.1; y0 = y0 + 0.0025) {
		for(float x0 = -2.5; x0 < 1.1; x0 = x0 + 0.0025) {
     			x = 0;
     			y = 0;
     			iteration = 0;
     			max_iteration = 1000;
	
			while(((x * x) + (y * y) < (2*2)) && iteration < max_iteration) {
		   		xtemp = (x * x) - (y * y) + x0;
		   		y = (2 * x * y) + y0;
		   		x = xtemp;
   				iteration = iteration + 1;
		   	}

			//beech wala color
			if(iteration >= 999) {
     				pixels[loc].r = 1;
		     		pixels[loc].g = 1;
		     		pixels[loc].b = 1;
			} else {
		     		pixels[loc].r = pattern[iteration].r;
		     		pixels[loc].g = pattern[iteration].g;
     				pixels[loc].b = pattern[iteration].b;
			}
			loc = loc + 1;
		}
	}
}

void Init()
{
/* Basic Opengl initialization.
   1440 = (-2.5 - 1.1)/0.0025
   here total x coordinate distance / no of division.
   840 = (-1 - 1.1)/0.0025 +1
   here total y coordinate distance / no of division. */

//  	glViewport(0, 0, 800, 600);
 	glViewport(0, 0, 1440, 841);	
   	glMatrixMode(GL_MODELVIEW);
   	glLoadIdentity();
   	glMatrixMode(GL_PROJECTION);
   	glLoadIdentity();
   	gluOrtho2D(0, 1440, 0, 841);
//   	gluOrtho2D(0, 800, 0, 600);

	int i;
   	float r, g, b;

/* Initializing all the pixels to white. */
   	for(i = 0; i < 841 * 1440; i++){
   	//for(i = 0; i < 600 * 800; i++){
		pixels[i].r = 1;
     	 	pixels[i].g = 1;
      		pixels[i].b = 1;
   	}

    	i = 0;

/* Initializing all the pattern color till 9*9*9 */
   	for(r = 0.1; r <= 0.9; r = r + 0.1) {
      		for(g = 0.1; g <= 0.9; g = g + 0.1) {
         		for(b = 0.1; b <= 0.9; b = b + 0.1){
            			pattern[i].r = b;
            			pattern[i].g = r;
			        pattern[i].b = g;
            			i++;
         		}
		}
	}

/* Initializing the rest of the pattern as 9*9*9 is 729.
   and we need up to 999 pattern as the loop bailout condition is 1000. */

   	for( ; i <= 999; i++){
      		pattern[i].r = 1;
      		pattern[i].g = 1;
      		pattern[i].b = 1;
   	}

   	mandelbrotset();
}

void onDisplay()
{
/* Clearing the initial buffer */
   	glClearColor(1, 1, 1, 0);
   	glClear(GL_COLOR_BUFFER_BIT);

/* Draw the complete Mandelbrot set picture. */
   	glDrawPixels(1440, 841, GL_RGB, GL_FLOAT, pixels);
   	//glDrawPixels(800, 600, GL_RGB, GL_FLOAT, pixels);
   	
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
/* Here basic Opengl initialization. */
    	glutInit(&argc, argv);
    	glutInitWindowSize (1440, 841);
    	//glutInitWindowSize (800, 600);
    	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    	//glutInitWindowPosition (100, 100);
    	glutInitWindowPosition (0, 0);
    	glutCreateWindow ("Mandelbrot");

    	Init ();
    	glutDisplayFunc(onDisplay);
    
    	glutMainLoop();

    	return 0;
}

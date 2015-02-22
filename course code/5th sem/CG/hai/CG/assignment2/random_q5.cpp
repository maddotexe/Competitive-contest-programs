#include <iostream> 
#include "GL/freeglut.h" 
#include "GL/gl.h" 
  
using namespace std; 
void iniit()
{
	glOrtho(0, 300, 0, 300, 0, 300);
}
  
void  renderFunction() 
{ 
    glClearColor(1.0, 1.0, 1.0, 1.0); 
    glClear(GL_COLOR_BUFFER_BIT); 
    glColor3f(0.0, 0.0, 0.0); 
     
          
   glPointSize(2);  
    glBegin(GL_POINTS); 
 	int ii = 0;     
   	 // using glvertex to draw a point 
   	 for (int i = 0; i < 100000; i++) { 
        	double x = (double)(rand() % 300); 
       		double y = (double) (rand() % 300); 
//    		glClearColor(0.0, 0.0, 0.0, 0.0); 
  //  		glClear(GL_COLOR_BUFFER_BIT); 
		if (x != 0 && x < 100) {
			glColor3f(0.0, 0.0, 0.5 + x/100);
		} else if (x < 200) {
			glColor3f(0.0,  0.5 + (x - 100)/100, 0.0);
		} else if (x < 300) {
			glColor3f( 0.5 + (x - 200)/100, 0.0, 0.0);
		} else {
			ii++;
//			glColor3f(0.0, 0.0, 0.0);
		}
        	glVertex2f(x, y); 
    	  } 
      
    glEnd(); 
    glFlush(); 
    cout << ii << endl;
} 
  
int main(int argc, char** argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE); 
    glutInitWindowSize(720, 720); 
    glutInitWindowPosition(0, 0); 
    glutCreateWindow(""); 
    iniit();
    glutDisplayFunc(renderFunction); 
    glutMainLoop(); 
  
    return 0; 
} 

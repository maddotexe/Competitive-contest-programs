#include <iostream>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <map>
#include <cmath>

#define PUSH glPushMatrix
#define POP glPopMatrix

#define inf 1000000

using namespace std;


void playit() 
{
	PUSH();
		double t = 3;
		int loop = 3;
		double r = 0.5;
		double dif = 0.28;
		while (loop--) {
			for (double x = 0; x <= 6.28; x += dif) {
				t += (t*0.03);
				glColor3f(r, 0, 0);
				r += 0.01;
				glPointSize(8-loop);
				glBegin(GL_POINTS);
					glVertex2f(t*sin(x), t*cos(x));
				glEnd();
				glFlush();
			}
			dif += 0.05;
		}
	POP();
	glutSwapBuffers();
}

void graphics() 
{ 
	glOrtho(-50, 50, -50, 50, -50, 50); 
	glClearColor(1, 1, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("hello world");
	graphics();
	glutDisplayFunc(playit);
	glutMainLoop();

	return 0;
}

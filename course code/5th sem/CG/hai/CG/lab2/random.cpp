#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"

using namespace std;

void renderFunction()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glOrtho(-1.0, 1.0, -1, 1.0, -1.0, 1.0);
		

	glBegin(GL_POINTS);
	
	// using glvertex to draw a point
	for (int i = 0; i < 10000; i++) {
		double x = (double)(rand() % 100)/100;
		double y = (double) (rand() % 100)/ 100;
		int sign1, sign2;
		sign1 = rand() % 1000;
		if (sign1 % 2 == 0) {
			sign1 = -1;
		} else {
			sign1 = 1;
		}
		sign2 = rand() % 1000;
		if (sign2 % 2 == 0) {
			sign2 = -1;
		} else {
			sign2 = 1;
		}
		glVertex2f(x*sign1, y*sign2);
	}
	
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(720, 720);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("");
	glutDisplayFunc(renderFunction);
	glutMainLoop();

	return 0;
}

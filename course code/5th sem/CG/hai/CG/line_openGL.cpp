#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"

using namespace std;

void renderFunction()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glBegin(GL_POINTS);

	float x1 = -1.0, y1 = -1.0;
	float x2 = 1.0, y2 = 1.0;
	float m = 1, c = 0;
	float x = x1, y = y1;


	while(x <= x2 && y <= y2) {
		glVertex2f(x, y);

		x = (x + 0.00001);
		y = (m*x + c + 0.00001);
	}

	float x3 = -1.0, y3 = 1.0;
	float x4 = 0.9, y4 = -0.9;

	float p = x3;
	float q = y3;

	while(p <= x4 && q >= y4) {
		glVertex2f(p, q);

		p += 0.0001;
		q = (m*(-p) + c - 0.00001);
	}
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1920, 720);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("");
	glutDisplayFunc(renderFunction);
	glutMainLoop();


	return 0;
}

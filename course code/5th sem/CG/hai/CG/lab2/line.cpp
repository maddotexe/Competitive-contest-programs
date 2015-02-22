#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <cmath>

using namespace std;

static void renderFunction()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glOrtho(-10.0, 10.0, -10, 10.0, -10.0, 10.0);
	glBegin(GL_POINTS);
	
	int np;
	float x1 = -.9, y1 = -.9;
	float x2 = 0.9, y2 = 0.9;
	float m = 1, c = 0;
	float x = x1, y = y1;
	float dx = fabs(x2 - x1);
//	cout << "enter number of points " << endl;
	np = 100000;
	dx /= np;
	for (int i = 0; i < np; i++) {
		glVertex2f(x, y);
		x = (x + dx);
		y = (m*x + c );
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

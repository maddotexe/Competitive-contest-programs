#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"


using namespace std;

namespace {
	float x[10], y[10];
	int np;
}

float fabs(float x)
{
	if (x > 0)
		return x;
	return -x;
}


void renderFunction()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);

	glBegin(GL_POLYGON);
		for (int i = 0; i < np; i++) {
			glVertex2f(x[i], y[i]);
		}
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	cout << "Enter points" << endl;
	cin >> np;
	for (int i = 0; i < np; i++) {
		cin >> x[i] >> y[i];
	}
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("");
	glutDisplayFunc(renderFunction);
	glutMainLoop();

	return 0;
}

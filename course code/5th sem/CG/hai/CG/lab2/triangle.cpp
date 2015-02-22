#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"

using namespace std;

void renderFunction()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glOrtho(-10.0, 10.0, -10, 10.0, -10.0, 10.0);
	glBegin(GL_POINTS);

	float x1 = -.9, y1 = -.9;
	float x2 = 0.9, y2 = 0.9;
	float m = 1, c = 0;
	float x = x1, y = y1;


	while(x <= x2 && y <= y2) {
		glVertex2f(x, y);

		x = (x + 0.00001);
		y = (m*x + c + 0.00001);
	}

	float x3 = -.9, y3 = -.9;
	float x4 = 0.9, y4 = 0.9;

	float p = -x3;
	float q = y3;

	while( q <= y4) {
		glVertex2f(p, q);

		//p += 0.0001;
		q = (q + 0.00001);
	}
	
	q = y3;
	p = x3;
	while( p <= x4) {
		glVertex2f(p, q);

		//p += 0.0001;
		p = (p + 0.00001);
	}
	cout << "wer" << endl;
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

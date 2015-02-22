#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"

using namespace std;

void print(float x1, float y1, float x2, float y2)
{

	float m = (y2 - y1)/ (x2 - x1), c = m * x1 - y1;
	float x, y;
	if (x1 < x2) {
		x = x1;
		y = y1;
		while(x <= x2 && y <= y2) {
			glVertex2f(x, y);
			x = (x + 0.00001);
			y = (m*x + c + 0.00001);
		}
	} else {
		x = x2;
		y = y2;
		while(x <= x1 && y <= y1) {
			glVertex2f(x, y);
			x = (x + 0.00001);
			y = (m*x + c + 0.00001);
		}
	}

}

static void renderFunction()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glOrtho(-10.0, 10.0, -10, 10.0, -10.0, 10.0);
	glBegin(GL_POINTS);
	
	float x1, x2, y1, y2;	
	y1 = x1 = -1.0;
	x2 = y2 = 1.0;
	print(x1, y1, x1, 1.0);

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

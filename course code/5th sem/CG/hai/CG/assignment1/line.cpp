#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"


using namespace std;

namespace {
	float x2, y2;
	float x1, y1;
	float dx, dy;
	float m;
	float c;
	int np = 100000;
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
//	glPointSize(10);

	glBegin(GL_POINTS);
	float x,y;
	dx = fabs(x1 - x2);
	dx /= np;
	
	
	// consider str line case
	if (x2 - x1 != 0) {
		m = (y2 - y1)/(x2 - x1);
	} else {
		m = (y2 - y1);
		m *= 100;
	}

	//consider end points
	if (x1 > x2) {
		x = x2;
		y = y2;
	} else {
		x = x1;
		y = y1;
	}
	
	for (int i = 0; i < np; i++) {
		glVertex2f(x, y);
		x += dx;
		y += m*dx;
	}
	
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	cout << "Enter points" << endl;
	cin >> x1 >> y1 >> x2 >> y2;	
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("");
	glutDisplayFunc(renderFunction);
	glutMainLoop();

	return 0;
}

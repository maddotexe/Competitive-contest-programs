#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"

using namespace std;

namespace {
	double x0, y0;
	double x1, y1;
	double dx, dy;
	double steps;
	double x, y;
	double p0;
	//cin >> x0 >> y0 >> x1 >> y1;
}

double fabs(double x)
{
	if (x > 0) {
		return x;
	}
	return -x;
}
void static renderFunction()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
	glBegin(GL_POINTS);
		x = x0;
		y = y0;
		dx = (x1 - x0);
		dy = (y1 - y0);
		p0 = 2 * dy - 2 *dx;
		steps = dx * 1000;
		for (int i = 0; i < steps; i++) {
			if (p0 < 0) {
				x = x + 0.001;
				glVertex2f( x, y);
				p0 = p0 + 2 * dy;
			} else {
				x = x + 0.001;
				y = y + 0.001;
				glVertex2f( x, y);
				p0 = p0 + 2 * dy - 2*dx; 
			}
		}
		glVertex2f(x1, y1);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	cout << "enter the points" << endl;
	cin >> x0 >> y0 >> x1 >> y1;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(720, 720);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("");
	glutDisplayFunc(renderFunction);
	glutMainLoop();


	return 0;
}

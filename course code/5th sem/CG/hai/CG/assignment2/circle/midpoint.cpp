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
	double r;
	double xend;
	//cin >> x0 >> y0 >> x1 >> y1;
}

void haha()
{
	glOrtho(-50.0, 50.0, -50.0, 50.0, -50.0, 50.0);
}

double fabs(double x)
{
	if (x > 0) {
		return x;
	}
	return -x;
}
void  renderFunction()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
//	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
	glBegin(GL_POINTS);
		x = 0;
		y = r;
		p0 = 1 - r;
		glVertex2f(x0, y0);
		glVertex2f(x, y);
		while (x <= y) {
			x = x + 0.001;
			if (p0 < 0) {
				p0 = p0 + 2 * x  + 1;
			} else {
				y = y -  0.001;
				p0 = p0 + 2 * x + 1  - 2* y;
			}
			glVertex2f(x0 + x, y0 + y);
			glVertex2f(x0 - x, y + y0);
			glVertex2f(x0 + x, y0 - y);
			glVertex2f(x0 - x, y0 - y);
			glVertex2f(x0 + y, y0 + x);
			glVertex2f(x0 - y, y0 + x);
			glVertex2f(x0 + y, y0 - x);
			glVertex2f(x0 - y, y0 - x);
			
		}
		
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	cout << "enter the centre, radius" << endl;
	cin >> x0 >> y0 >> r;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(720, 720);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("");
	haha();
	glutDisplayFunc(renderFunction);
	glutMainLoop();


	return 0;
}

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
	double px, py, p;
	double rx, ry;
	double xend;
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
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
	glBegin(GL_POINTS);
		x = 0;
		y = ry;
		px = 0;
		py = 2 * ry * ry * y;
		 
		// region 1: 
		p = ry * ry - (rx * rx * ry) + 0.25 * rx * rx;		
		
		while (px <= py) {
			x = x + 0.001;
			if (p  > 0) {
				p = p + ry * 2 + px;
			} else {
				y = y -  0.001;
				py = py - rx * 2;
				p = p  + ry * ry + px - py;
			}
			glVertex2f(x0 + x, y0 + y);
			glVertex2f(x0 - x, y + y0);
			glVertex2f(x0 + x, y0 - y);
			glVertex2f(x0 - x, y0 - y);
		}
		// region 2 :
		p = ry * ry * (x + 0.5) * (x + 0.5) + rx * rx * (y-1) * (y-1) - rx * rx * ry * ry;
		while (y > 0) {
			y = y - 0.01;
			py = py - rx * 2;
			if (p > 0) {
				p = p + rx * rx - py;
			} else {
				x = x + 0.01;
				px = px + rx * 2 ;
				p = p + rx * rx - py + px;
			}
			glVertex2f(x0 + x, y0 + y);
			glVertex2f(x0 - x, y + y0);
			glVertex2f(x0 + x, y0 - y);
			glVertex2f(x0 - x, y0 - y);
			
		}
		
		cout << x << " " << y << endl;
		glVertex2f(1, 0);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	cout << "enter the centre, radius" << endl;
	cin >> x0 >> y0 >> rx >> ry;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(720, 720);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("");
	glutDisplayFunc(renderFunction);
	glutMainLoop();


	return 0;
}

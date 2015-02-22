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

void haha()
{

	glOrtho(-15.0, 15.0, -15.0, 15.0, -15.0, 15.0);
}

void  renderFunction()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
//	glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
	glBegin(GL_POINTS);
		if (x0 < x1) {
			x = x0;
			y = y0;
			xend = x1;
		} else {
			x = x1;
			y = y1;
			xend = x0;
		}
		dx = fabs(x1 - x0);
		dy = fabs(y1 - y0);
		p0 = 2 * dy - 2 *dx;
		int count1 = 0, count2 = 0, val = (dx * 1000) / 50;
		glVertex2f(x, y);
		while (x < xend) {
			x = x + 0.001;
			if (p0 < 0) {
				p0 = p0 + 2 * dy;
			} else {
				p0 = p0 + 2 * dy - 2* dx;
				y = y + 0.001;
			}
			if (count1 < val && count2 < val) {
				glVertex2f(x,y);
				count1++;	
			} else if (count1 == val && count2 < val) {
				count2++;
			} else if (count1 == val && count2 == val) {
				count1 = 0;
				count2 = 0;
			} 
			
		}
		cout << xend << endl;
		glVertex2f(x, y);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	cout << "enter the points" << endl;
	cin >> x0 >> y0 >> x1 >> y1;

	//haha();
	
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

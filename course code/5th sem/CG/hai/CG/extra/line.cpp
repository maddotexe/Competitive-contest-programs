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
	glColor3f(1.0, 0.0, 0.0);
	glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
	glBegin(GL_POINTS);
		x = x0;
		y = y0;
		
		int stp;
		if (fabs(x1 - x0) >= fabs(y1 - y0)) { // m < 1
			dx = 1;
			dy = (y1 - y0)/ (x1 - x0);
			dx /= 1000;
			dy /= 1000;
			stp = fabs(x1 - x0)*1000;
		} else {

			dx = (x1 - x0)/ (y1 - y0);
			dy = 1;
			dx /= 1000;
			dy /= 1000;
			stp = fabs(y1-y0)*1000;
		}
		//dx = s(dx);
		//dy = fabs(dy);	
		glVertex2f(x0, y0);
		cout << dx << " " << dy << endl;
		for (int i = 0; i < stp; i++) {
			x += dx;
			y += dy;
			glVertex2f(x, y);
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

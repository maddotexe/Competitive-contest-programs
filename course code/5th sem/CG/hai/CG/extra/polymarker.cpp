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

void barChart()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glOrtho(0.0, 500, 0.0, 500, 0, 500);
	
	GLint month, k;
	glColor3f(1.0, 1.0, 1.0);
	GLubyte label[12] = {'j', 'a', 'n', 'f', 'e', 'b', 'm', 'a', 'r', 'a', 'p', 'r'};
	GLint dataValue[4] = {410, 320, 240, 140};

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINE_STRIP);
	for (k = 0; k < 4; k++) {
		glVertex2i(20+ k * 50, dataValue[k]);
	}
	glEnd();
	
	glColor3f(1.0, 0.0, 0.0);
	int xr = 20, yr = 150;	
	for (k = 0; k < 4; k++) {
		glRasterPos2i(xr + k * 50, dataValue[k] - 4);
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '*');
	}
	glColor3f(0.0, 0.0, 0.0);
	for (month = 0; month < 4; month++) {
		glRasterPos2i (xr, yr);
		for (k = 3  * month; k < 3 *month + 3; k++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, label[k]);
		}
		xr += 50;
	}
	glFlush();
}


void static renderFunction()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glOrtho(0.0, 500, 0.0, 500, 0, 500);
	glBegin(GL_LINE_STRIP);
		barChart();	
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
//	cout << "enter the points" << endl;
//	cin >> x0 >> y0 >> x1 >> y1;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(720, 720);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("");
	glutDisplayFunc(barChart);
	glutMainLoop();


	return 0;
}

#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <cmath>
using namespace std;

namespace {
	int o_size = 100;
	double x_one, y_one;
	double x_two, y_two;
	double dx, dy;
	double steps;
	double x, y;
	double p0;
	double xend;
};

double fabs(double x)
{
	if (x < 0) {
		return -x;
	}
	return x;
}

void ResizeFunction(int Width, int Height)
{
	glOrtho(-o_size, o_size, -o_size, o_size, -o_size, o_size);
	glViewport(0, 0, Width, Height);
}

void rotate(double &x, double &y, double theta)
{
	double xx = x * cos(theta) - y * sin(theta);
	double yy = x * sin(theta) + y * cos(theta);
	y = yy;
	x = xx;
}

void draw_axis()
{
	glPointSize(3);
	glBegin(GL_POINTS);
	for (float i = -o_size; i < o_size; i = i + 0.5) {
		glVertex2f(i, 0);
		glVertex2f(0, i);
	}
	glEnd();
}	

void static RenderFunction(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	
	draw_axis();
	glPointSize(10);
	// code actual here
	glBegin(GL_POINTS);
		if (x_one < x_two) {
			x = x_one;
			y = y_one;
			xend = x_two;
		} else {
			x = x_two;
			y = y_two;
			xend = x_one;
		}
		dx = fabs(x_two - x_one);
		dy = fabs(y_two - y_one);
		p0 = 2 * dy - 2 *dx;
		
		glVertex2f(x, y);
		while (x < xend) {
			x = x + 0.01;
			if (p0 < 0) {
				p0 = p0 + 2 * dy;
			} else {
				p0 = p0 + 2 * dy - 2* dx;
				y = y + 0.01;
			}
			glVertex2f(x, y);
			double X = x, Y = y;

			rotate(X, Y, 0.875);
			glVertex2f(X, Y);
		}
		
		glVertex2f(x, y);

	glEnd();
	// code ends here
	cout << "end" << endl;
	glutSwapBuffers();
//	glutPostRedisplay();
	glFlush();
}


int main(int argc, char** argv)
{
	cout << "enter end points\n"; 
	cin >> x_one >> y_one >> x_two >> y_two;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("");
	glutReshapeFunc(ResizeFunction);
	glutDisplayFunc(RenderFunction);
	glutMainLoop();


	return 0;
}

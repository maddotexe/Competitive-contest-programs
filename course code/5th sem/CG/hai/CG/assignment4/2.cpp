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
	glPointSize(3);
	// code actual here
	glBegin(GL_POINTS);
		for (double t = 5 *-3.14, r = 1; t <= 5 * 3.14; t+= 0.1, r += .5) {
			x = r * sin(t);
			y = r * cos(t);
			glVertex2f(x, y);
		}

	glEnd();
	// code ends here
	cout << "end" << endl;
	glutSwapBuffers();
//	glutPostRedisplay();
	glFlush();
}


int main(int argc, char** argv)
{

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

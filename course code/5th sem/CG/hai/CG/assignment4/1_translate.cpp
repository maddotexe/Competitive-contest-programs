#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"

using namespace std;

namespace {
	int o_size = 100;
	double x0, y0;
	double x1, y1;
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

void translate(double &x, double &y, double tx, double ty)
{
	x += tx;
	y += ty;
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

			translate(X, Y, 50, 50);
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
	cin >> x0 >> y0 >> x1 >> y1;

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

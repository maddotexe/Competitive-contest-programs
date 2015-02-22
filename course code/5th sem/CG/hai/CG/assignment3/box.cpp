#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <cmath>

using namespace std;

namespace {
	int o_size = 100;
	double x1, x2, y2, y3, c, m;
	int  mat[200][200];
	double sigma;
};

void ResizeFunction(int Width, int Height)
{
	glOrtho(-o_size, o_size, -o_size, o_size, -o_size, o_size);
	glViewport(0, 0, Width, Height);
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

double dist(double a, double b)
{
	double Y = m * a + c;
	double distance = (1.0/sqrt(1+m*m)) * (abs(b-m*a-c));
	return distance;
}


double area(double x, double y)
{
	double sign = y - m * x2 - c;
	if (dist(x, y) >= 2) {
		return 0;
	}
	double h,b;
	if (sign > 0) {
		double y1 = m * (x + 1) - c;
		double x1 = ((y-1)-c)/m;
		h = y1 - y - 1;
		b = x + 1 - x1;
	} else {
		double y1 = m * (x - 1) - c;
		double x1 = ((y+1) - c)/m;
		h = y + 1 - y1;
		b = x1 - x - 1;
	}
	double area = h * b / 2;
	return (fabs(area));
}
void static RenderFunction(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	
	draw_axis();
	glPointSize(2);
	// code actual here
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 200; j++) {
			if (mat[i][j] >= 4 ) {
				glColor3f(1, 1, 1);
			} else if (mat[i][j] >= 2) {
				glColor3f(0.3, 0.3, 0.3);
			} else if (mat[i][j] >= 0.5) {
				glColor3f(0.1, 0.1, 0.1);
			} else {
				continue;
			}
			glBegin(GL_POINTS);
				glVertex2f(i, j);
			glEnd();
			glFlush();
		}
	}
	// code ends here
	cout << "end" << endl;
	glutSwapBuffers();
//	glutPostRedisplay();
	glFlush();
}


int main(int argc, char** argv)
{
	cout << "Enter the cordinates " << endl;
	cin >> x1 >> y3 >> x2 >> y2; 
	m = (y2 - y3) / (x2 - x1);
	c = y3 - m * x1;
	for (int i = 0; i < 200; i ++) {
		for (int j = 0; j < 200; j++) {
			mat[i][j] = -1;
		}
	}
	for (int i = x1; i < x2; i++) {
		for (int j = y3; j < y2; j++) {
			mat[i][j] = area(i, j);
		}
	}

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

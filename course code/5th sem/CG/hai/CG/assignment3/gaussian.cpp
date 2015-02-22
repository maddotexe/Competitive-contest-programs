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
	double distance = (double)pow(2.73, abs(b - Y) / sigma);
	return distance;
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
			if (mat[i][j] == 1) {
				glColor3f(1, 1, 1);
			} else if (mat[i][j] == 2) {
				glColor3f(0.3, 0.3, 0.3);
			} else if (mat[i][j] == 3) {
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
	cin >> x1 >> y3 >> x2 >> y2 >> sigma;
	m = (y2 - y3) / (x2 - x1);
	c = y3 - m * x1;
	for (int i = 0; i < 200; i ++) {
		for (int j = 0; j < 200; j++) {
			mat[i][j] = -1;
		}
	}
	for (int i = x1; i < x2; i++) {
		for (int j = y3; j < y2; j++) {
			mat[i][j] = dist(i, j);
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

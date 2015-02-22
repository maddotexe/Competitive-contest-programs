#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <cmath>
#include <climits>

using namespace std;

void renderFunction()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glOrtho(-2.0, 2.0, -2, 2.0, -2.0, 2.0);
//	glPointSize(10);		

	glBegin(GL_POINTS);
	
	// using glvertex to draw a point
	for (double i = -1; i <= 1; i += 0.01) {
		for (double j = -1; j <= 1; j+= 0.01) {
			for (double k = -1; k <= 1; k+= 0.01) {
				double l = i*i + j*j + k*k;
				if (l >= 0.95 && l <= 1.05) {
					glVertex3f(, j ,k);
				}
			}
		}
	}

	
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1920, 720);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("");
	glutDisplayFunc(renderFunction);
	glutMainLoop();

	return 0;
}

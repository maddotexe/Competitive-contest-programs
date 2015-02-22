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
	glOrtho(-1.0, 1.0, -1, 1.0, -1.0, 1.0);
//	glPointSize(10);		

	glBegin(GL_POINTS);
	
	// using glvertex to draw a point
	for (int i = 0; i < 100000; i++) {
		double x = (double)(rand() % 10);
		double y;
		y = (0.7077f/ 3.14f) * expf(-1.0f*(x*x)/2.0f);
//		y /= 100;
		glVertex2f(x/100, y/100);
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

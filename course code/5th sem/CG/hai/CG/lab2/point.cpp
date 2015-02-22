#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"

using namespace std;

void renderFunction()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glOrtho(-10.0, 10.0, -10, 10.0, -10.0, 10.0);
	glPointSize(10);		

	glBegin(GL_POINTS);
	
	// using glvertex to draw a point
	float x = 1.0;
	float y = 1.0;
	glVertex2f(x, y);
	
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

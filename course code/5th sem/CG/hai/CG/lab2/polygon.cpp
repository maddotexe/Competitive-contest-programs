#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <cmath>

using namespace std;
float x[] = {  0, 2, 0,-4, 3};
float y[] = {  5, 1, -1, -2, 0};
static void renderFunction()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
	glBegin(GL_POLYGON);

	for (int i = 0; i < 5; i++) 
	{
		glVertex2f(x[i]/10, y[i]/10);	
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

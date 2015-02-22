#include <iostream>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <map>

#define inf 1000000

using namespace std;

void init() { 
	glOrtho(-100, 100, -100, 100, -100, 100); 
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
}

void func1() 
{
	glBegin(GL_LINE_LOOP);
	glVertex2f(0, 50);
	glVertex2f(-30, 25);
	glVertex2f(-15, -20);
	glVertex2f(15, -20);
	glVertex2f(30, 25);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(0, 50);
	glVertex2f(15, -20);
	glVertex2f(-15, -20);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glVertex2f(30, 25);
	glVertex2f(-15, -20);
	glVertex2f(-30, 25);
	glEnd();
	glFlush();

	glBegin(GL_LINE_LOOP);
	glVertex2f(-30, 25);
	glVertex2f(30, 25);
	glVertex2f(15, -20);
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("hello world");
	init();
	glutDisplayFunc(func1);
	glutMainLoop();

	return 0;
}

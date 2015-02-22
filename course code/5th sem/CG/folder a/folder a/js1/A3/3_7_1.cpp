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
	glVertex2f(-50, 0);
	glVertex2f(0, 86.60);
	glVertex2f(50, 0);
	glEnd();
	glFlush();

	glColor3f(0, 1, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-10.5, 17);
	glVertex2f(12.5, 18.7);
	glVertex2f(-3, 43.3);
	glEnd();
	glFlush();

	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(0, 86.6);
	glVertex2f(-3, 43.3);
	glEnd();
	glFlush();

	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(0, 86.6);
	glVertex2f(-10.5, 17);
	glEnd();
	glFlush();
	
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(0, 86.6);
	glVertex2f(-3, 43.3);
	glEnd();
	glFlush();
	
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(-50, 0);
	glVertex2f(-10.5, 17);
	glEnd();
	glFlush();
	
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(-50, 0);
	glVertex2f(12.5, 18.7);
	glEnd();
	glFlush();
	
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(50, 0);
	glVertex2f(12.5, 18.7);
	glEnd();
	glFlush();
	
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(50, 0);
	glVertex2f(-3, 43.3);
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

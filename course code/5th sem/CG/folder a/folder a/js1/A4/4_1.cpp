#include <iostream>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <map>

#define inf 1000000
#define GLV glVertex2f

using namespace std;

typedef double dbl;

void ROTATE(dbl x, bool b)
{
	glPushMatrix();
	if (b) {
		glRotatef(x, 0, 0, 1);
	}
	glBegin(GL_LINE_LOOP);
		GLV(0, 0);
		GLV(0, 20);
		GLV(20, 20);
		GLV(20, 0);
	glEnd();
	
	glFlush();
	glPopMatrix();
}

void graphics() 
{ 
	glOrtho(-50, 50, -50, 50, -50, 50); 
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
}

void TRANSLATION(dbl x, dbl y, bool b)
{
	glPushMatrix();
	if (b) {
		glTranslatef(x, y, 0);
	}
	glBegin(GL_LINE_LOOP);
		GLV(0, 0);
		GLV(0, 20);
		GLV(20, 20);
		GLV(20, 0);
	glEnd();
	
	glFlush();
	glPopMatrix();
}

void scales(dbl x, dbl y, bool b)
{
	glPushMatrix();
	if (b) {
		glScaled(2, 2, 1);
	}
	glBegin(GL_LINE_LOOP);
		GLV(0, 0);
		GLV(0, 20);
		GLV(20, 20);
		GLV(20, 0);
	glEnd();
	
	glFlush();
	glPopMatrix();
}

void playit() 
{
	TRANSLATION(10, 10, true);
	TRANSLATION(10, 10, false);
	ROTATE(30, true);
	scales(2, 2, true);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("hello world");
	graphics();
	glutDisplayFunc(playit);
	glutMainLoop();

	return 0;
}

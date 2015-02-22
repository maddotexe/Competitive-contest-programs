#include <GL/gl.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

using namespace std;

double x, y, z, angle = 0;

void graphics()
{
	glOrtho(-100, 100, -100, 100, -100, 100);
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glScaled(1.5, 1.5, 1);
}

void fan()
{
	glColor3f(0, 0, 0);
	glPushMatrix();
		int k = (int)angle;
		glRotatef(angle, (int)x, (int)y, (int)z);
		angle = ((int)(angle + 10)) % 360;
		glBegin(GL_LINE_LOOP);
			glVertex2f(-3, 0);
			glVertex2f(3, 0);
			glVertex2f(0, 5);
		glEnd();

		glBegin(GL_LINE_LOOP);
			glVertex2f(-3, 0);
			glVertex2f(3, 0);
			glVertex2f(6, -25);
			glVertex2f(-6, -25);
		glEnd();

		glBegin(GL_LINE_LOOP);
			glVertex2f(0, 5);
			glVertex2f(3, 0);
			glVertex2f(29, 12);
			glVertex2f(23, 21);
		glEnd();

		glBegin(GL_LINE_LOOP);
			glVertex2f(0, 5);
			glVertex2f(-3, 0);
			glVertex2f(-29, 12);
			glVertex2f(-23, 21);
		glEnd();
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

void function_call()
{
	glClear(GL_COLOR_BUFFER_BIT);
	fan();
}

void looping()
{
	sleep(1);
	glutPostRedisplay();
}

void take()
{
	cin >> x >> y >> z;
}

int main(int argc, char **argv)
{
	take();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Trafalgar Law : Propeller");
	graphics();
	glutDisplayFunc(function_call);
	glutIdleFunc(looping);
	glutMainLoop();

	return 0;
}

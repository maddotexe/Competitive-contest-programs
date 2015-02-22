#include <GL/gl.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

#define PUSH glPushMatrix
#define POP glPopMatrix

using namespace std;

namespace {
	double cr = 0, X = 0, Y = 0;
}

bool check(double a, double b, string c)
{
	if (c == "<") {
		if (a < b) {
			return true;
		} else {
			return false;
		}
	} else if (c == "<=") {
		if (a <= b) {
			return true;
		} else {
			return false;
		}
	} else if (c == ">") {
		if (a > b) {
			return true;
		} else {
			return false;
		}
	} else if (c == ">=") {
		if (a >= b) {
			return true;
		} else {
			return false;
		}
	}
}

void TABLE()
{
	PUSH();
		glTranslatef(-X, Y, 0);
		glColor3f(0.7, 0.3, 0.3);
		glRectf(-90, 0, -80, 70);
		glRectf(-20, 0, -10, 70);
		glRectf(-90, 70, -10, 80);
	
		glColor3f(0, 1, 0);
		glRectf(-60, 80, -40, 90);
		if (check(cr, 12, ">=")) {
			if (check(cr, 45, "<=")) {
				X += 0.05;
			}
		}
	POP();
}

void CHAIR()
{
	glColor3f(0, 0, 1);
	PUSH();	
		glRotatef(cr, 0, 0, 1);
		glRectf(0, 0, 10, 40);
		glRectf(0, 40, 30, 50);
		glRectf(30, 0, 40, 100);
	POP();
	if (cr <= 45)
	if (check(cr, 12, "<")) {
		cr += 0.2;
	} else {
		cr += 0.12;
	}
}

void BALLS()
{
	glColor3f(1, 1, 0);
	PUSH();
		glTranslatef(-47-X, 93, 0);
		glutSolidSphere(5, 20, 20);
	POP();
	glColor3f(1, 0, 0);
	PUSH();
		glTranslatef(-53-X, 93, 0);
		glutSolidSphere(5, 20, 20);
	POP();
	
	if (check(cr, 12, ">=")) {
		if (check(cr, 45, "<=")) {
			X += 0.05;
		}
	}
}

void function_call()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	BALLS();
	TABLE();
	CHAIR();
	glFlush();
	glutSwapBuffers();
}

void looping()
{
	glutPostRedisplay();
}

void graphics()
{
	glOrtho(-100, 100, -100, 100, -100, 100);
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_DOUBLE);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Assignment");
	graphics();
	glutDisplayFunc(function_call);
	glutIdleFunc(looping);
	glutMainLoop();

	return 0;
}

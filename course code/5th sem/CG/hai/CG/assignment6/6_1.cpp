#include <GL/gl.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <cstdio>

using namespace std;

double y = 0, x = 0, rotate = 0;

void take()
{
	cin >> x >> y;
}

void function_call()
{
	glPushMatrix();
		glRotatef(rotate, 0, 0, 1);
		rotate += 10;
		glColor3f(0, 1, 1);
		glutSolidSphere(50, 18, 18);
		glColor3f(0, 0, 0);
		glutWireSphere(50, 18, 18);
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

void graphics()
{
	glOrtho(-100, 100, -100, 100, -100, 100);
	glClearColor(1, 1, 1, 0);
	glShadeModel(GL_FLAT);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(x, 0, 0, 1);
	glRotatef(y, 0, 1, 0);
}

void looping()
{
	sleep(1);
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	take();
	rotate = atoi(argv[3]);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Assignment");
	graphics();
	glutDisplayFunc(function_call);
	glutIdleFunc(looping);

	
	glClearColor(1, 1, 1, 1);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glutMainLoop();

	return 0;
}

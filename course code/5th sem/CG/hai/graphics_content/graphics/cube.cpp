#include <GL/glut.h>
#include <iostream>

using namespace std;

int r = 0;

void init()
{
	glOrtho(-100, 100, -100, 100, -100, 100);
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.3, 0.3, 0.3);
}

void func1()
{
	glRotatef(r, 0, 1, 0);
	r += 10;
	glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 50, 0);
		glVertex3f(50, 50, 0);
		glVertex3f(50, 0, 0);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 50);
		glVertex3f(0, 50, 50);
		glVertex3f(0, 50, 0);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 50);
		glVertex3f(50, 0, 50);
		glVertex3f(50, 0, 0);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(50, 0, 0);
		glVertex3f(50, 50, 0);
		glVertex3f(50, 50, 50);
		glVertex3f(50, 0, 50);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(0, 50, 0);
		glVertex3f(0, 50, 50);
		glVertex3f(50, 50, 50);
		glVertex3f(50, 50, 0);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(0, 0, 50);
		glVertex3f(50, 0, 50);
		glVertex3f(50, 50, 50);
		glVertex3f(0, 50, 50);
	glEnd();
	glFlush();
	glutSwapBuffers();
}

void start()
{
	sleep(1);
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_SINGLE);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("cube");
	init();
	glutDisplayFunc(func1);
	glutIdleFunc(start);
	glutMainLoop();

	return 0;
}


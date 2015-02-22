#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"

using namespace std;

namespace {
	int o_size = 200;
	double chair_rotate = 0;
	double X = 0, Y = 0;
	double TT = 0;
};

void ResizeFunction(int Width, int Height)
{
	glOrtho(-o_size, o_size, -o_size, o_size, -o_size, o_size);
	glViewport(0, 0, Width, Height);
}

void draw_axis()
{
	glPointSize(3);
	glBegin(GL_POINTS);
	for (float i = -o_size; i < o_size; i = i + 0.5) {
		glVertex2f(i, 0);
		glVertex2f(0, i);
	}
	glEnd();
}	

void draw_table()
{
	glPushMatrix();
		glTranslatef(-X, Y, 0);
		glColor3f(0.5, 0.5, 0);
		glRectf(-90, 0, -80, 70);
		glRectf(-20, 0, -10, 70);
		glRectf(-90, 70, -10, 80);

		glColor3f(0, 1, 0);
		glRectf(-60, 80, -40, 90);
		if (chair_rotate >= 10 && chair_rotate <= 45) {
			X += 0.09;
		}
	glPopMatrix();
}

void draw_chair()
{
	glColor3f(0, 0, 1);
	glPushMatrix();
		glRotatef(chair_rotate, 0, 0, 1);
		glRectf(0, 0, 10, 40);
		glRectf(0, 40, 30, 50);
		glRectf(30, 0, 40, 100);
	glPopMatrix();

	if (chair_rotate <= 15) {
		chair_rotate += 0.2;
	} else if (chair_rotate <= 45) {
		chair_rotate += 0.12;
	}
}

void draw_balls()
{
	glColor3f(1, 1, 0);
	glPushMatrix();
		glTranslatef(-47-TT, 93, 0);
		glutSolidSphere(5, 20, 20);
	glPopMatrix();
	glColor3f(0, 0, 1);
	glPushMatrix();
		glTranslatef(-53-TT, 93, 0);
		glutSolidSphere(5, 20, 20);
	glPopMatrix();
	
	if (chair_rotate >= 12 && chair_rotate <= 45) {
		TT += 0.07;
//		X += 0.05;
	}
}



void static RenderFunction(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);

	draw_balls();
	draw_table();
	draw_chair();	
	glutSwapBuffers();
	glFlush();
}

void animation()
{
	if (chair_rotate > 45) {
		chair_rotate = 0;
		X = 0;
		Y = 0;
		TT = 0;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("");
	glutReshapeFunc(ResizeFunction);
	glutDisplayFunc(RenderFunction);
	glutIdleFunc(animation);
	glutMainLoop();


	return 0;
}

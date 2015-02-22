#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <cmath>
using namespace std;

namespace {
	int o_size = 100;
	double rotate = 0;
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

void draw_rotated_line()
{
	glPushMatrix();
		glRotatef(rotate, 0, 0, 1);
		rotate += 18;
		glBegin(GL_LINE);
			glVertex2f(-50, 0);
			glVertex2f(50, 0);
		glEnd();
	glPopMatrix();
}

void draw_translated_line(double tx, double ty)
{
	glPushMatrix();
		glTranslatef(tx, ty, 0);
		glBegin(GL_LINE);
			glVertex2f(-50, 0);
			glVertex2f(50, 0);
		glEnd();
	glPopMatrix();
}
void t_plus_r(double tx, double ty,double ang)
{
	glPushMatrix();
		glRotatef(ang, 0,0, 1);
		glTranslatef(tx, ty, 0);
		glBegin(GL_LINE);
			glVertex2f(-50, 0);
			glVertex2f(50, 0);
		glEnd();
	glPopMatrix();
}
void static RenderFunction(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	
	draw_axis();
	glPointSize(10);
	// code actual here
	
	for (int i = 0; i < 10; i++) {
		draw_rotated_line();
	}
	draw_translated_line(0, 10);
	draw_translated_line(0, -10);
	draw_translated_line(10, 0);
	draw_translated_line(-10, 0);

	t_plus_r(5 * sqrt(2), 5* sqrt(2), -45);
	t_plus_r(5 * sqrt(2), -5 * sqrt(2), -45);
	t_plus_r(-5* sqrt(2), 5 * sqrt(2), 45);
	t_plus_r(5 * sqrt(2), -5*sqrt(2), 135);
	// code end
	cout << "end" << endl;
	glutSwapBuffers();
//	glutPostRedisplay();
	glFlush();
}


int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("");
	glutReshapeFunc(ResizeFunction);
	glutDisplayFunc(RenderFunction);
	glutMainLoop();


	return 0;
}

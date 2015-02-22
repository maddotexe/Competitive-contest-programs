#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <cmath>
using namespace std;

namespace {
	int o_size = 100;
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

void circle(double x, double y, double r)
{
	glBegin(GL_POINTS);
		for (double a = -3.14; a <= 3.14; a += 0.05) {
			glVertex2f(x + r * sin (a), y + r * cos (a));
		}
	glEnd();
	glFlush();
}

void line(double a, double b, double c, double d)
{
	glBegin(GL_LINES);
		glVertex2f(a, b);
		glVertex2f(c, d);
	glEnd();
	glFlush();
}


void cantor(float x, float y, float len)
{
	if (len < 2) 
		return;
	line(x, y, x + len, y);
	y += 20;
	cantor(x, y,len/3);
	cantor(x  + len * 2/3 , y,len/3);
}	

void func(double x1, double y1, double x2, double y2, double x3, double y3)
{
	if (abs(x1- x2) < 10)
			return ;
				
	double mx1 = (x1 + x2) / 2;
	double mx2 = (x2 + x3) / 2;
	double mx3 = (x3 + x1) / 2;
	double my1 = (y1 + y2) / 2;
	double my2 = (y2 + y3) / 2;
	double my3 = (y3 + y1) / 2;

	glColor3f(1, 0, 0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
		glVertex2f(x3, y3);
	glEnd();

	glColor3f(1, 0, 0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(mx1, my1);
		glVertex2f(mx2, my2);
		glVertex2f(mx3, my3);
	glEnd(); 
	glFlush();

	func(x1, y1, mx1, my1, mx3, my3);
	func(mx1, my1, x2, y2, mx2, my2);
	func(mx3, my3, mx2, my2, x3, y3);
}

void static RenderFunction(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	
	func(0, 100, -100, -100, 100, -100);
	
	// code ends here
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

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

void make_triangle(double trX, double trY)
{
	glPushMatrix();
	glTranslatef(trX, trY, 0);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(7, 23);
	glVertex2f(20, 3);
	glEnd();
	glFlush();
	glPopMatrix();
}

void func1() 
{
	make_triangle(0, 0);
	make_triangle(20, 0);
	make_triangle(40, 0);
	make_triangle(60, 0);
	make_triangle(0, 20);
	make_triangle(0, 40);
	make_triangle(0, 60);
	make_triangle(20, 20);
	make_triangle(40, 20);
	make_triangle(60, 20);
	make_triangle(20, 40);
	make_triangle(40, 40);
	make_triangle(60, 40);
	make_triangle(20, 60);
	make_triangle(40, 60);
	make_triangle(60, 60);
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

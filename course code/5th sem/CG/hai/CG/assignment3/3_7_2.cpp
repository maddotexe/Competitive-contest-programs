#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <map>
#include <cmath>

#define inf 1000000
#define dbl double

using namespace std;

void init() { 
	glOrtho(-100, 100, -100, 100, -100, 100); 
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
}

void make_circle(dbl d1, dbl d2, dbl r)
{
	for (dbl i = 0; i <= acos(-1)*2; i += 0.001) {
		glBegin(GL_POINTS);
		glVertex2f(r*sin(i) + d1, r*cos(i) + d2);
		glEnd();
	}
	glFlush();
}

void func1() 
{
	glColor3f(0.6, 0.6, 1);
	glutSolidSphere(50, 30, 30);
	glColor3f(0, 0, 0);
	make_circle(0, 25, 30);
	//make equations of circle and the rest is done
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

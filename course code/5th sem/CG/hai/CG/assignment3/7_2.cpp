#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <cmath>
using namespace std;
/**
	medial curves
	c1 = (x - h1)^2 + (y - k1) ^ 2 = r1^2;
	c2 = (x - h2)^2 + (y - k2) ^ 2 = r2 ^2;
	is givven bye
	Ax^2 + Bxy + Cy^2 + Dx +  Ey + F = 0;
	A = 4 * ((h1 - h2)^ 2  - R);
	B = 8 * (h1 - h2)(k1 - k2);
	C = 4 * ((k1 - k2) ^ 2 - R);
	D = 4 * (h1(-D1 + D2 + r) + h2 * (D1 - D2 + R);
	E = 4 * (k1 (-D1 + D2 + R) + k2 * (D1 - D2 + R));
	F = (D1 - D2) ^ 2 - 2 * (D1 + D2) R + R ^2;
	R = (r1 - s*r2)^2;
	D1 = h1^2 + k1^2;
	D2 = h2 ?^2 + k2^2;
	s = +/- 1;
**/
namespace {
	int n = 5;
	double xx[] = {-10.0, -10.0, 0, 10, 10};
	double yy[] = {-10, 0, 10, 0, -10};
	int o_size = 100;
};

void ResizeFunction(int Width, int Height)
{
	glOrtho(-o_size, o_size, -o_size, o_size, -o_size, o_size);
	glViewport(0, 0, Width, Height);
}


void make_circle(double d1, double d2, double r)
{
	for (double i = 0; i <= acos(-1)*2; i += 0.001) {
		glBegin(GL_POINTS);
		glVertex2f(r*sin(i) + d1, r*cos(i) + d2);
		glEnd();
	}
	glFlush();
}

void make_translate_circle(double d1, double d2, double r, double tr1, double tr2)
{
	glPushMatrix();
		glTranslatef(tr1, tr2, 0);
		make_circle(d1, d2, r);
		glFlush();
	glPopMatrix();
	
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

void static RenderFunction(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	
	draw_axis();
	glPointSize(2);
	// code actual here
	glColor3f(0.6f, 0.6f, 0.0f);
	glutSolidSphere(50, 30, 30);
	glColor3f(0, 0, 0);
	make_circle(0, 30, 30);
	make_circle(0, 15, 45);		
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

#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <cmath>

using namespace std;

#define PI 3.1457

void rotate_along_yaxis(float &x, float &y, float &z, float angle);

namespace {
	int o_size = 100;
	int r = 50;
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


void draw_circle_XY(float radius, float ang)
{
	float x, y, z;
	for (float t = -PI; t <= PI; t += 0.01) {
		x = radius * sin (t);
		y = radius * cos (t);
		z = 0;
		rotate_along_yaxis(x, y, z, ang);
		glVertex3f(x, y, z);
	}
}

void draw_circle_XZ(float y1, float radius)
{
	float x, y, z;
	for (float t = -PI; t <= PI; t += 0.01) {
		x = radius * sin (t);
		z = radius * cos (t);
		y = y1;
//		rotate_along_yaxis(x, y, z, ang);
		glVertex3f(x, y, z);
	}
}

void rotate_along_yaxis(float &x, float &y, float &z, float angle)
{
	float x_new, y_new, z_new;
	x_new = cos(angle) * x + sin(angle) * z;
	y_new = y;
	z_new = -sin(angle) * x + y + z * cos(angle);
	x = x_new;
	y = y_new;
	z = z_new;
}

void draw_longitude(float inc)
{

	//longitude
	for (float t = inc + 0; t <= inc + PI; t = t + PI/5) {
		draw_circle_XY(r, t);
		
	}
}

void wait(int t)
{
	for (int i = 0; i < t* 1000; i++) {for (int i1 = 0; i1 < t*t; i1++){}}
}

void static RenderFunction(void)
{
	static int inc = 0;
	while (1) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 1.0f, 0.0f);
	

	glPointSize(2);
	float i;
	float x, y, z;
	
	glBegin(GL_POINTS);
		
		for (float s = -PI; s <= PI; s = s + 0.1) {
			for (float t = -PI; t <= PI; t = t + 0.1) {
				glVertex3f(r * cos(s) * sin(t), r * cos(t), r * sin(t) * sin(s));
			}
		}
	
		draw_longitude(inc);
		inc = (inc + PI/10);
		
		wait(1000);	
	
	glEnd();
		glutSwapBuffers();
		cout << "!";
		glFlush();
	}
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

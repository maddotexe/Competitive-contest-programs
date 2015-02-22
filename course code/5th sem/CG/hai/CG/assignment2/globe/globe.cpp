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


void draw_circle(float radius, float ang)
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

void static RenderFunction(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 1.0f, 0.0f);
	
	draw_axis();
	glPointSize(2);
	float x, y, z;
	// code actual here
	glBegin(GL_POINTS);
		
		
		for (float t = 0; t <= PI; t = t + PI/10) {
			//cout << "X " << x << " Y  " << y <<  " z " << z << endl;
			draw_circle(r, t);
			for (long long int i = 0; i < 10000000; i ++) {
				for (int ij = 0; ij < 10; ij++) {}
			}
			//rotate_along_yaxis(x, y, z, 0.04);			
		}
		//draw_sphere(10);

	glEnd();
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

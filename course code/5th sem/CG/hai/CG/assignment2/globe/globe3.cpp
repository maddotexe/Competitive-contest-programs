#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <cmath>

using namespace std;

#define PI 3.1457

void rotate_along_yaxis(float &x, float &y, float &z, float angle);

namespace {
	int o_size = 100;
	int r = 70;
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

	for (float t =  - PI; t <= PI; t += 0.01) {
		x =  radius * sin (t);
		y =  radius * cos (t);
		z =  0;
		rotate_along_yaxis(x, y, z, ang);
		glVertex3f(x, y, z);
	}
}

void draw_circle_XZ(float y1, float radius)
{
	float x, y, z;
	for (float t = -PI; t <= PI; t += 0.02) {
		x = radius * sin (t);
		z = radius * cos (t);
		y = y1;
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

void wait(int t)
{
	t = 0;	
	for (long long int i = 0; i < t * 10000; i ++) {}
}	

void draw_longitude(float inc)
{

	//longitude
	for (float t = inc + 0; t <= inc + PI; t = t + PI/5) {
		draw_circle_XY(r, t);
		wait(0);
	}
}

void draw_latitude()
{
	// latitude
	for (float t = -r; t <= r; t = t + 10) {
		double rad = sqrt(r*r - t*t);
		draw_circle_XZ(t, rad);
		wait(0);
	}
}

void static RenderFunction(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	
	draw_axis();
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(2);
	float x, y, z;
	int i1 = 0;
	// code actual here
	
	for (float i = 0; i < 10000000; i = i + PI/50) {		
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_POLYGON);
			for (float t =  - PI; t <= PI; t += 0.01) {
				x =  r * sin (t);
				y =  r * cos (t);
				z =  0;
				glVertex3f(x, y, z);
		}

		glEnd();

		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_POINTS);
			draw_longitude(i);
			draw_latitude();
		glEnd();	
		glFlush();
		glutSwapBuffers();
		for (long long int i = 0; i < 100 * 10000; i ++) {for (int j = 0; j < 100; j++){}}
		glClear(GL_COLOR_BUFFER_BIT);
	}
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

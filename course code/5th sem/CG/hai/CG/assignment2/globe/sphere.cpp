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

void draw_sphere(float radius)
{
	float x, y, z;
	for (float t = -PI; t <= PI; t = t + 0.01) {
		for (float s = -PI; s <= PI; s = s + 0.01) {
			x = radius * cos(s) * sin(t);
			y = radius * sin(s) * sin(t);
			z = radius *  cos(t);	
			glVertex3f(x , y, z);
		}
	}
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
		
		draw_sphere(10);		

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

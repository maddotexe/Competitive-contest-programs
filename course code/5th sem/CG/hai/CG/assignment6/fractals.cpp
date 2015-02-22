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
		for (double a = -3.14; a <= 3.14; a += 0.01) {
			glVertex2f(x + r * sin (a), y + r * cos (a));
		}
	glEnd();
	glFlush();
}

void drawCircle(float x, float y, float radius)
{
	circle(x, y, radius);
	if (radius > 8) {
		drawCircle(x + radius/2,y,  radius/2);
		drawCircle(x - radius/2, y, radius/2);
		drawCircle(x, y + radius/2, radius/2);
		drawCircle(x, y - radius/2, radius/2);
	}
}	

void static RenderFunction(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.7f, 0.7f);
	
	draw_axis();
	glPointSize(2);
	// code actual here
		drawCircle(0, 0, 50);
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

#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"

using namespace std;

namespace {
	int o_size = 100;
	int ctr = 0;
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


void f(double X, double Y, double size)
{

//	ctr ++;
	if (size < 10) {
		return;
	}

	glBegin(GL_POINTS);
		for (int i = 0; i < 10*size; i++) {
			int s = size; 
			double x = rand() % s;
			double y = rand() % s;
			glColor3f(1.0, 0.0, 0.0);
			glVertex2f(X + x, Y + y);
			glColor3f(0.0, 0.0, 1.0);
			glVertex2f(X + s + x, Y + y);
			glColor3f(0.0, 1.0, 0.0);
			glVertex2f(X + x, Y + s + y);
			glColor3f(1.0, 1.0, 1.0);
			glVertex2f(X + s + x, Y + s + y);
		}
	glEnd();
	glFlush();
	f(X, Y, size/2);
	f(X + size/2, Y, size/2);
	f(X + size/2, Y + size/2, size/2);
	f(X, Y + size/2, size/2);

}
void static RenderFunction(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	
	draw_axis();
	glPointSize(1);
	// code actual here
	int size = 50;
	f(0, 0, 50);
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

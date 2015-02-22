#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"

using namespace std;

namespace {
	int o_size = 50;
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


void f(double x1, double y1, double x2, double y2, double size)
{

//	ctr ++;
	if (size < 2) {
		return;
	}
	double mid_x = (x1 + x2)/2;
	double mid_y = (y1 + y2)/2;
	glBegin(GL_POINTS);
		for (int i = 0; i < 10*size; i++) {
			int s = size/2; 
			double x = rand() % s;
			double y = rand() % s;
			glColor3f(1.0, 0.0, 0.0);
			glVertex2f(x1 + x, y1 + y);
			glColor3f(0.0, 0.0, 1.0);
			glVertex2f(mid_x + x, y1 + y);
			glColor3f(0.0, 1.0, 0.0);
			glVertex2f(x1 + x, mid_y + y);
			glColor3f(1.0, 1.0, 1.0);
			glVertex2f(mid_x + x, mid_y + y);
		}
	glEnd();
	glFlush();
	f(x1, y1, mid_x, mid_y, size/2);
	f(x1 + mid_x, y1, x2, mid_y, size/2);
	f(x1, y1 + mid_y, mid_x, y2, size/2);

//f(X + size/2, Y + size/2, size/2);
//	f(X, Y + size/2, size/2);

}
void static RenderFunction(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	
	draw_axis();
	glPointSize(2);
	// code actual here
	int size = 50;
	f(0, 0, 20, 20, 20);
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

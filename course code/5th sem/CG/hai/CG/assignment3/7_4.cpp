#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"

using namespace std;

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



void static RenderFunction(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	
	draw_axis();
	glPointSize(10);
	// code actual here
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

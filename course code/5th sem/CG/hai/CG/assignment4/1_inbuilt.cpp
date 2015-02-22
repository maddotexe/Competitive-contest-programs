#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"

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

void static RenderFunction(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	
	draw_axis();
	glPointSize(10);
	// code actual here
		
	glPushMatrix();
	glRotatef(45, 0, 0, 1);
	glBegin(GL_LINE_LOOP);
		glVertex2f(0, 0);
		glVertex2f(0, 20);
		glVertex2f(20, 20);
		glVertex2f(20, 0);
	glEnd();
	glFlush();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(30, 30, 0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(0, 0);
		glVertex2f(0, 20);
		glVertex2f(20, 20);
		glVertex2f(20, 0);
	glEnd();
	glFlush();
	glPopMatrix();

	glPushMatrix();
	glScaled(2, 2,  1);
	glBegin(GL_LINE_LOOP);
		glVertex2f(0, 0);
		glVertex2f(0, 20);
		glVertex2f(20, 20);
		glVertex2f(20, 0);
	glEnd();
	glFlush();
	glPopMatrix();
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

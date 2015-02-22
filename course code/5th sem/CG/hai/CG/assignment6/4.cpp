#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"

using namespace std;

namespace {
	int o_size = 100;
	double x, y, z, angle = 0;
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
	
	glPointSize(2);
	// code actual here
	
	glPushMatrix();
		int k = (int) angle;
		glRotatef(angle, (int)x, (int) y, (int) z);
		angle = ((int)(angle + 10))%360;
//		glBegin(GL_LINE_LOOP);
//			glVertex2f(-3, 0);
//			glVertex2f(3, 0);
//			glVertex2f(0, 5);
//		glEnd();

		glBegin(GL_LINE_LOOP);
			glVertex2f(-3, 0);
			glVertex2f(3, 0);
			glVertex2f(6, -25);
			glVertex2f(-6, -25);
		glEnd();

		glBegin(GL_LINE_LOOP);
			glVertex2f(0, 5);
			glVertex2f(3, 0);
			glVertex2f(29, 12);
			glVertex2f(23, 21);
		glEnd();

		glBegin(GL_LINE_LOOP);
			glVertex2f(0, 5);
			glVertex2f(-3, 0);
			glVertex2f(-29, 12);
			glVertex2f(-23, 21);
		glEnd();

	glPopMatrix();
	// code ends here
	cout << "end" << endl;
	glutSwapBuffers();
//	glutPostRedisplay();
	glFlush();
}

void animation()
{
	sleep(1);
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	cin >> x >> y >> z;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("");
	glutReshapeFunc(ResizeFunction);
	glutDisplayFunc(RenderFunction);
	glutIdleFunc(animation);
	glutMainLoop();


	return 0;
}

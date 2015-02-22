#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"

using namespace std;

namespace {
	int o_size = 100;
	double x = 0, y = 0, angle = 0;
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
		glRotatef(angle, 0, 0, 1);
		angle += 10;
		glColor3f(1, 0, 1);
		glutSolidSphere(50, 18, 18);
		glColor3f(0 , 1, 0);
		glutWireSphere(50, 18, 18);
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
	glShadeModel(GL_FLAT);
	glRotatef(90, 1, 0, 0);
	glRotatef(x, 0, 0, 1);
	glRotatef(y, 0 , 1,0);
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	cin >> x >> y;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("");
	glutReshapeFunc(ResizeFunction);
	glutDisplayFunc(RenderFunction);
	glutIdleFunc(animation);
	glClearColor(1, 1, 1, 1);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glutMainLoop();


	return 0;
}

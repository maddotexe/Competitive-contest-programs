#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <cstdio>
#include <cmath>
using namespace std;
int o_size = 200;
void init()
{
//	glShadeModel(GL_FLAT);
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_CULL_FACE);
//	glCullFace(GL_BACK);
//	texName = LoadTexture("earth.bmp");
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
}

void timer(int v)
{
	static GLfloat u = 0.0;
	u += 0.01;
	glLoadIdentity();
	gluLookAt(8*cos(u),7*cos(u) - 1, 4 * cos(u/3) + 2, 0.5, 0.5, 0.5, cos(u), 1, 0);

	glutPostRedisplay();
	glutTimerFunc(1000/60.0, timer, v);

}

void ResizeFunction(int Width, int Height)
{
//	glOrtho(-o_size, o_size, -o_size, o_size, -o_size, o_size);
	glViewport(0, 0, Width, Height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, GLfloat(Width)/ GLfloat(Height), .5, 50);
	glMatrixMode(GL_MODELVIEW);
}

void start()
{
	sleep(1);
	glutPostRedisplay();
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
int r = 0;
void static RenderFunction(void)
{
	glPushMatrix();
//	glRotatef(r, 0.7, .7, 0.7);
//	r += 10;
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
//	glEnable(GL_TEXTURE_2D);	
//	draw_axis();
	glPointSize(10);
	// code actual here
	glBegin(GL_POLYGON);
		glVertex3f(0, 0, 1.0);
		 glVertex3f(0, 1, 1.0);
		glVertex3f(0, 1, 0.0);
		glVertex3f(0, 0, 0.0);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(0, 1, 0.0);
		glVertex3f(1, 1, 0.0);
		glVertex3f(1, 0, 0.0);
		glVertex3f(0, 0, 0.0);
	glEnd();
	glBegin(GL_POLYGON);
		 glVertex3f(1, 1, 0.0);
		 glVertex3f(1, 0, 0.0);
		 glVertex3f(1, 0, 1.0);
		 glVertex3f(1, 1, 1.0);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(0, 1, 1.0);
		 glVertex3f(0, 1, 0.0);
		 glVertex3f(1, 1, 0.0);
		 glVertex3f(1, 1, 1.0);
	glEnd();
	glBegin(GL_POLYGON);
		 glVertex3f(0, 0, 0.0);
		glVertex3f(1, 0, 0.0);
		 glVertex3f(1, 0, 1.0);
		 glVertex3f(0, 0, 1.0);
	glEnd();
	glBegin(GL_POLYGON);
		 glVertex3f(0, 1, 1.0);
		glVertex3f(1, 1, 1.0);
		 glVertex3f(1, 0, 1.0);
		 glVertex3f(0, 0, 1.0);
	glEnd();
	glPopMatrix();
	// code ends here
	cout << "end" << endl;
	glutSwapBuffers();
	glFlush();
//	glDisable(GL_TEXTURE_2D);
}


int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("");
	init();
	glutReshapeFunc(ResizeFunction);
	glutTimerFunc(1000, timer, 0);
	glutDisplayFunc(RenderFunction);
	//glutIdleFunc(start);
	glutMainLoop();


	return 0;
}

#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"

using namespace std;

namespace {
	int o_size = 100;
};


struct POINTS {
	double x;
	double y;
	double z;
};
typedef struct POINTS point;

point mat[35][2];

void init1()
{
	glClearColor(0, 0, 0, 0);
	glShadeModel(GL_FLAT);
	glScaled(3, 3, 3);
//	glRotatef(60, 1, 0, 0);
//	glRotatef(60, 0, 1, 0);
}

void input()
{
	mat[1][0].x = -80;
	mat[1][0].y = 0;
	mat[1][0].z = 0;

	mat[1][1].x = -80;
	mat[1][1].y = 50;
	mat[1][1].z = 0;

	mat[2][0].x = 80;
	mat[2][0].y = 0;
	mat[2][0].z = 0;

	mat[2][1].x = 80;
	mat[2][1].y = 50;
	mat[2][1].z = 0;
	
	for (int i = 2; i < 17; i++) {
		int k1 = 2*i-1;
		mat[k1][0].x = mat[1][0].x;
		mat[k1][0].y = mat[1][0].y;
		mat[k1][0].z = mat[1][0].z + 10*(i-1);
		
		mat[k1][1].x = mat[1][1].x;
		mat[k1][1].y = mat[1][1].y;
		mat[k1][1].z = mat[1][1].z + 10*(i-1);

		k1 = 2*i;

		mat[k1][0].x = mat[2][0].x;
		mat[k1][0].y = mat[2][0].y;
		mat[k1][0].z = mat[2][0].z + 10*(i-1);

		mat[k1][1].x = mat[2][1].x;
		mat[k1][1].y = mat[2][1].y;
		mat[k1][1].z = mat[2][1].z + 10*(i-1);
	}
	mat[33][0].x = -80;
	mat[33][0].y = 0;
	mat[33][0].z = 0;

	mat[33][1].x = -80;
	mat[33][1].y = 0;
	mat[33][1].z = 200;
	
	mat[34][0].x = 80;
	mat[34][0].y = 0;
	mat[34][0].z = 0;

	mat[34][1].x = 80;
	mat[34][1].y = 0;
	mat[34][1].z = 200;

	for (int i = 1; i < 35; i++) {
		cout << mat[i][0].x << " " << mat[i][0].y << " " << mat[i][0].z << endl;
		cout << mat[i][1].x << " " << mat[i][1].y << " " << mat[i][1].z << endl;
//		cout << endl << endl;
//		int p; cin >> p;
		glBegin(GL_LINE);
			glVertex3f(mat[i][0].x, mat[i][0].y, mat[i][0].z);
			glVertex3f(mat[i][1].x, mat[i][1].y, mat[i][1].z);
		glEnd();
	}
}


void ResizeFunction(int Width, int Height)
{
	glOrtho(-o_size, o_size, -o_size, o_size, -o_size, o_size);
	glViewport(0, 0, Width, Height);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1, 1, 1, 0, 0, 0, 1, 0, 1);
	glFrustum(-100, 100 ,-100, 100, -100 ,100);
	init1();
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
	
/*	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1, 1, 1, 0, 0, 0, 1, 0, 1);
	glFrustum(-100, 100 ,-100, 100, -100 ,100);
*/
	draw_axis();
	glPointSize(10);
	// code actual here
		input();
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

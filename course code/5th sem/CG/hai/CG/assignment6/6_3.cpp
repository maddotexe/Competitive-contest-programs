#include <GL/gl.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

using namespace std;

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
//		cout << mat[i][0].x << " " << mat[i][0].y << " " << mat[i][0].z << endl;
//		cout << mat[i][1].x << " " << mat[i][1].y << " " << mat[i][1].z << endl;
//		cout << endl << endl;
//		int p; cin >> p;
		glBegin(GL_LINE);
			glVertex3f(mat[i][0].x, mat[i][0].y, mat[i][0].z);
			glVertex3f(mat[i][1].x, mat[i][1].y, mat[i][1].z);
		glEnd();
	}
}

void func1()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	glLoadIdentity();
	gluLookAt(0, 0, -3, 0, 0, 10, 0, 1, 1);
//	glScalef(10, 10, 10);
	input();

	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-100, 100, -100, 100, 1, 200);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Assignment");
	init1();
	glutDisplayFunc(func1);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}

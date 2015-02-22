#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <cmath>
using namespace std;

namespace {
	int o_size = 100;
	float x2, y2;
	float x1, y_one;
	float c, m;
	int n;
	int mat[200][200];
};

float mod(float  x) {
	if (x < 0)
		 return -x;
	return x;
}

float  dist(float x1, float y3) {
	
	return (1.0/sqrt(1+m*m))*(mod(y3-m*x1-c));
}

void input() {
	cin >> x1 >> y_one >> x2 >> y2;
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 200; j++) {
			 mat[i][j]=-1;
		}
	}

	m = (y2-y_one)/(x2-x1);
	c = y_one - m * x1;
	for (int i = x1; i < x2; i++) {
		for (int j = y_one;j < y2;j++) {
			 mat[i][j] = dist(i,j);
		}
	}
	
}

void ResizeFunction(int Width, int Height)
{
	glOrtho(-o_size, o_size, -o_size, o_size, -o_size, o_size);
	glViewport(0, 0, Width, Height);
}


void draw_axis()
{
	glPointSize(2);
	glBegin(GL_POINTS);
	for (float i = -o_size; i < o_size; i = i + 0.5) {
		glVertex2f(i, 0);
		glVertex2f(0, i);
	}
	glEnd();
}	


void static RenderFunction(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	
	draw_axis();
	glPointSize(1);
	// code actual here
	glBegin(GL_POINTS);
		for (int i = 0;i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				if (mat[i][j]==0) {
					glColor3f(1, 1, 1);
					glVertex2f(i, j);
				} else if (mat[i][j]==1) {
					glColor3f(.3, .3, .3);
					glVertex2f(i, j);
				} else if (mat[i][j]==2) {
					glColor3f(.1, .1, .1);
					glVertex2f(i, j);
				} 
			}
		}

	glEnd();
	// code ends here
	cout << "end" << endl;
	glutSwapBuffers();
//	glutPostRedisplay();
	glFlush();
}


int main(int argc, char** argv)
{
	input();
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

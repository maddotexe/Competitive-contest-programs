#include <iostream>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <map>
#include <cmath>
#define inf 1000000

using namespace std;

namespace {
	double x1,x2,y2,y3,c,m;
	double mat[200][200];
}

double dist(double x1, double y3) {
	return (1.0/sqrt(1+m*m))*(abs(y3-m*x1-c));
}

void input() {
	cin >>x1>>y3>>x2>>y2;
	for (int i=0;i<200;i++) for (int j=0;j<200;j++) mat[i][j]=-1;
	m=(y2-y3)/(x2-x1);
	c=y3-m*x1;
	for (int i=(int)x1;i<(int)x2;i++) {
		for (int j=(int)y3;j<(int)y2;j++) {
			double distk = dist(i, j);
			if (distk < 1) {
				mat[i][j] += 1;
				mat[i-1][j] += 0.25;
				mat[i][j-1] += 0.25;
				mat[i+1][j] += 0.25;
				mat[i][j+1] += 0.25;
				
				mat[i-1][j-1] += 0.12;
				mat[i-1][j+1] += 0.12;
				mat[i+1][j-1] += 0.12;
				mat[i+1][j+1] += 0.12;
			} 
		}
	}
	
}

void init() { 
	glOrtho(-100,100,-100,100,-100,100); 
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void pointPlot(int i, int j, double d1) {
	glColor3f(d1,d1,d1);
	glBegin(GL_POINTS);
	glVertex3f(i,j,0);
	glEnd();
	glFlush();
}

void func1()
{
	for (int i=0;i<100;i++) {
		for (int j=0;j<100;j++) {
			if (mat[i][j] >= 0.49 && mat[i][j] < 1) {
				pointPlot(i,j,0.6);
			} else if (mat[i][j] >= 0.37) {
				pointPlot(i,j,0.3);
			} else if (mat[i][j] >= 0.12) {
				pointPlot(i, j, 0.1);
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (mat[i][j] >= 1) {
				pointPlot(i, j, 1);
			}
		}
	}
	glFlush();
	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	input();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("hello world");
	init();
	glutDisplayFunc(func1);
	glutMainLoop();

	return 0;
}

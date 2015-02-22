#include <iostream>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <map>
#include <cmath>
#define inf 1000000

#define FOR(i,n) for (int i=0;i<n;i++)

using namespace std;

namespace {
	double x1,x2,y2,y3,c,m;
	int M[200][200];
}

double dist(double x1, double y3) 
{
	return (1.0/sqrt(1+m*m))*(fabs(y3-m*x1-c));
}

void take() {
	cin >> x1;
	cin >> y3;
	cin >> x2;
	cin >> y2;
	for (int i=0;i<200;i++) for (int j=0;j<200;j++) M[i][j]=-1;
	m=(y2-y3)/(x2-x1);
	c=y3-m*x1;
	for (int i=(int)x1;i<(int)x2;i++) for (int j=(int)y3;j<(int)y2;j++) M[i][j]=dist(i,j);
	
}

void graphics() { 
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

void playit()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(10);
	FOR(i,100) FOR(j,100) {
			if (M[i][j]==0) {
				pointPlot(i,j,1);
			}
			if (M[i][j]==1) {
				pointPlot(i,j,0.3);
			}
			if (M[i][j]==2) {
				pointPlot(i,j,0.1);
			} 
		}
}

int main(int argc, char **argv)
{
	take();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("program");
	graphics();
	glutDisplayFunc(playit);
	glutMainLoop();

	return 0;
}

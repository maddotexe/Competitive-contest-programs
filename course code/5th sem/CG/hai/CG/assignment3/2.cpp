#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <cmath>
using namespace std;

double x1,x2,y2,y3,c,m;
int mat[200][200];
int o_size = 500;

void ResizeFunction(int Width, int Height)
{
	glOrtho(-o_size, o_size, -o_size, o_size, -o_size, o_size);
	glViewport(0, 0, Width, Height);
}

double dist(double x1, double y3) {
	return (1.0/sqrt(1+m*m))*(fabs(y3-m*x1-c));
}

void pointPlot(int i, int j, double d1) {
	glColor3f(d1,d1,d1);
	glBegin(GL_POINTS);
	glVertex3f(i,j,0);
	glEnd();
	glFlush();
}
double fabs(double x)
{
	if (x)
		return x;
	return -x;
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
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	
	draw_axis();
	glPointSize(3);
	// code actual here
	glBegin(GL_POINTS);
		
		for (int i=0;i<100;i++) {
			for (int j=0;j<100;j++) {
				if (mat[i][j]==0) {
					pointPlot(i,j,1);
				} else if (mat[i][j]==1) {
					pointPlot(i,j,0.3);
				} else if (mat[i][j]==2) {
					pointPlot(i,j,0.1);
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
	cin >> x1 >> y3 >> x2 >> y2;
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 200; j++) {
			 mat[i][j] = -1;
		}
	}

	m = (y2-y3) / (x2-x1);
	c = y3-m*x1;
	for (int i = (int)x1; i < (int)x2; i++) {
		for (int j = (int)y3; j < (int)y2; j++) {
			mat[i][j] = dist(i,j);
		}
	}

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

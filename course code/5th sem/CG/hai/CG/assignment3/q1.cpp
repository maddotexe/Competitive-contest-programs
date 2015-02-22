#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <cmath>
using namespace std;

namespace {
	int o_size = 100;
	float x[10], y[10];
	int n;
};

void ResizeFunction(int Width, int Height)
{
	glOrtho(-o_size, o_size, -o_size, o_size, -o_size, o_size);
	glViewport(0, 0, Width, Height);
}

void IntensityPixel(float x, float y, float distance)
{
	double intensity = distance;
	
	glVertex2f(x, y);
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

void haha(float x, float y, float z)
{
	glColor3f(x/10, y/10, z/20);
}

void static RenderFunction(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	
	draw_axis();
	glPointSize(1);
	// code actual here
	glBegin(GL_POLYGON);
		for (int i = 0; i < n; i++) {
			haha(x[i] , y[i], x[i]+y[i]);
			//glColor3f(x[i]/10, y[i]/10, (x[i]+y[i])/20);
			glVertex2f(x[i], y[i]);
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
	cout << "enter number of points \n";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
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

#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"

using namespace std;

namespace {
	double a, b, c;
	double x[10], y[10];
	int n;
}

double fabs(double x)
{
	if (x > 0) {
		return x;
	}
	return -x;
}

void haha()
{
	glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
}

void  renderFunction()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(a, b, c);
	
	glBegin(GL_POLYGON);
		for (int i = 0; i < n; i++)
			glVertex2f(x[i], y[i]);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	cout << "enter the color compostion" << endl;
	cin >> a >> b >> c;

	cout << "enter numebr of points, point" << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(720, 720);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("");
	haha();
	glutDisplayFunc(renderFunction);
	glutMainLoop();


	return 0;
}

#include <GL/gl.h>
#include <GL/freeglut.h>
#include <iostream>
#include <algorithm>

using namespace std;

namespace {
	double X[1000];
	double Y[1000];
	double EY;
	double EX;
	double EXY;
	double EXX;
	double b;
	double m;
	double x1;
	double x2;
	double y1;
	double y2;
	double dx;
	double dy;
	int Np;
}

void renderfunction()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
	glBegin(GL_POINTS);
//	glVertex2f(x1, y1);
	x1 /= 100;
	y1 /= 100;
	int i;
	for (i = 0; i < 1000000; i++) {
		glVertex2f(x1, y1);
		x1 += dx;
		y1 += dy;
		
	}
	cout << i << endl;
//	glVertex2f(x2, y2);
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	EY = EX = EXY = EXX = 0;
	cin >> Np;
	for (int i = 0; i < Np; i++) {
		
		cin >> X[i] >> Y[i];
		//X[i] = rand() %1000;
		//Y[i] = rand() % 1000;
		X[i] /= 100;
		Y[i] /= 100;
		EX += X[i];
		EY += Y[i];
		EXY += (X[i] * Y[i]);
		EXX += (X[i] * X[i]);
	}
	m = ( (Np*EXY) - (EX*EY) ) / ( (Np*EXX) - (EX*EX) );
	b = ( EY - (m*EX) ) / Np;
	x1 = X[0];
	y1 = m*x1 + b;
	x2 = X[Np-1];
	y2 = m*x2 + b;
	dx = (x2-x1)/1000;
	dy = (y2-y1)/1000;
	cout << "Equation(s) is(are) " << " y = " << m << "x + " << b << endl;
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("");
	glutDisplayFunc(renderfunction);
	glutMainLoop();

	return 0;
}

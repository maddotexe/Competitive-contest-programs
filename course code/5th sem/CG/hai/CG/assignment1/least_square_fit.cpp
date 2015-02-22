#include <GL/gl.h>
#include <GL/freeglut.h>
#include <iostream>
#include <algorithm>

using namespace std;

namespace {
	float X[1000];
	float Y[1000];
	float EY;
	float EX;
	float EXY;
	float EXX;
	float b;
	float m;
	float x1;
	float x2;
	float y1;
	float y2;
	float dx;
	float dy;
	int Np;
}
void hahaha()
{
	EY = EX = EXY = EXX = 0;
	cin >> Np;
	for (int i = 0; i < Np; i++) {
		cin >> X[i] >> Y[i];
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
	y1 = Y[0];
	x2 = X[Np-1];
	y2 = m*x2 + b;
	dx = (x2-x1)/100000;
	dy = (y2-y1)/100000;
	cout << "Equation(s) is(are) " << " y = " << m << "x + " << b << endl;
}

void renderFunction()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	glBegin(GL_POINTS);	

		x1 /= 100;
		y1 /= 100;
		float k1 = -1;
		float k2 = 0;
		float e = 1.0/10000;
		for (int i = 0; i < 1000000; i++) {
			glVertex2f(k1, k2);
			k1 += e;
		}
		k1 = 1;
		for (int i = 0; i < 1000000; i++) {
			glVertex2f(0, k1);
			k1 -= e;
		}
		for (int i = 0; i < 1000000; i++) {
			glVertex2f(x1, y1);
			x1 += dx;
			y1 += dy;
		}
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	hahaha();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("");
	glutDisplayFunc(renderFunction);
	glutMainLoop();

	return 0;
}


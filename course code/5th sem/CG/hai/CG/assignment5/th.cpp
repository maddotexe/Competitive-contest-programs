#include <GL/gl.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <vector>
#include <stack>
#include <ctime>

using namespace std;

vector<int> a[1000][3];
stack<int> s1;
stack<int> s2;
stack<int> s3;
int n = 3;
int index = 1;

void th(int n, char x, char y, char z)
{
	if (n <= 0) {
		return;
	}

	th(n - 1, x, z, y);
	int k = -1;
	if (x == 'A') {
		k = s1.top();
		s1.pop();
	} else if (x == 'B') {
		k = s2.top();
		s2.pop();
	} else if (x == 'C') {
		k = s3.top();
		s3.pop();
	}

	if (y == 'A') {
		s1.push(k);
	} else if (y == 'B') {
		s2.push(k);
	} else if (y == 'C') {
		s3.push(k);
	}
	stack<int> s4 = s1;
	stack<int> s5 = s2;
	stack<int> s6 = s3;
	vector<int> v1, v2, v3;
	while (s4.size()) {
		v1.push_back(s4.top());
		s4.pop();
	}
	while (s5.size()) {
		v2.push_back(s5.top());
		s5.pop();
	}
	while (s6.size()) {
		v3.push_back(s6.top());
		s6.pop();
	}
	for (int i = v1.size()-1; i >= 0; i--) {
		a[index][0].push_back(v1[i]);
	}
	for (int i = v2.size()-1; i >= 0; i--) {
		a[index][1].push_back(v2[i]);
	}
	for (int i = v3.size()-1; i >= 0; i--) {
		a[index][2].push_back(v3[i]);
	}
	index++;
	th(n - 1, z, y, x);
}

void towers_of_hanoi()
{
	for (int i = n; i > 0; i--) {
		s1.push(i);
	}
	a[0][0].push_back(3);
	a[0][0].push_back(2);
	a[0][0].push_back(1);
	th(n, 'A', 'B', 'C');
}

void init1()
{
	glClearColor(0, 0, 0, 0);
	glOrtho(-100, 100, -100, 100, -100, 100);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(10);
}

void plot(int index)
{
}

void func1()
{
	for (int i = 0; i < index; i++) {
		double d1 = clock();
		while (true) {
			double d2 = clock();
			if (d2 - d1 > 3000000) {
				break;
			}
		}
		glColor3f(1, 1, 1);
		glRectf(-80, -80, 80, 80);
		glColor3f(1, 1, 1);
		
		glColor3f(0, 0, 0);
		for (int j = 0; j < a[index][0].size(); i++) {
			glBegin(GL_POINTS);
			glVertex2f(0, i*10);
			glEnd();
		}
		glFlush();
	}
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100, 100, -100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char **argv)
{
	towers_of_hanoi();
	cout << "towers of Hanoi " << endl;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Trafalgar Law : Towers of Hanoi");
	init1();
	glutDisplayFunc(func1);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}
#include <iostream>
#include <stack>
#include <vector>
#include <ctime>

#include "GL/freeglut.h"
#include "GL/gl.h"

using namespace std;

int o_size = 200;
vector<int> a[1000][3];
stack<int> s1;
stack<int> s2;
stack<int> s3;
int n = 4;
int index = 1;
int current = 0;
int peg_x[] = {-150, 0, 150};
int peg_y[] = {0, 0, 0};

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


void ResizeFunction(int Width, int Height)
{
	glOrtho(-o_size, o_size, -o_size, o_size, -o_size, o_size);
	glViewport(0, 0, Width, Height);
}

void draw_peg()
{
	glPointSize(3);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.7, 0.7);
	for (int i = 0; i < 3; i++) {
		glVertex2f(peg_x[i], peg_y[i]);
		glVertex2f(peg_x[i], o_size - 10);
	}
	glEnd();
}	

void make_at(int peg_no, vector<int> s)
{
	glColor3f(0.0, 1.0, 0.0);
	for (int i = 0; i < s.size(); i++) {
		glBegin(GL_POINTS);
		glEnd();
		glRectf(peg_x[peg_no] - 20*(s[i]), peg_y[peg_no] + 10 + (i) * 20, peg_x[peg_no] + 20*(s[i]), peg_y[peg_no] + 40 + (i) * 40);
	}
//	glutSwapBuffers();
	glFlush();
}

void wait()
{
	
	double d1 = clock();
	while (true) {
		double d2 = clock();
		if (d2 - d1 > 300000) break;
	}
}

void animation()
{
	if (current == index) {
	//	sleep(1);
		current = index - 1;
		glutPostRedisplay();
		return;
	}
	sleep(1);
	current++;
	glutPostRedisplay();
}

void static RenderFunction(void)
{
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	draw_peg();
	// code actual here
	glBegin(GL_POINTS);
		for (int i = 0; i < 3; i++) 
			make_at(i, a[current][i]);
	glEnd();
	// code ends here
	glFlush();
}


int main(int argc, char** argv)
{
	towers_of_hanoi();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("");
	glutReshapeFunc(ResizeFunction);
	glutDisplayFunc(RenderFunction);
	glutIdleFunc(animation);
	glutMainLoop();


	return 0;
}

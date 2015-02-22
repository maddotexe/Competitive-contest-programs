#include <GL/gl.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <vector>
#include <stack>
#include <ctime>

#define GLV glVertex2f
#define pb push_back

using namespace std;

namespace 
{
	stack<int> s1, s2, s3;
	/*change towers_of_hanoie value of n here */
	int n;
	
	int index = 1, current = 0;
	vector<int> a[1000][3];
}

void take()
{
	cout << "enter n " << endl;
	cin >> n;
}

void towers_of_hanoi(int n, char x, char y, char z)
{
	if (n <= 0) {
		return;
	}

	towers_of_hanoi(n - 1, x, z, y);
	int k = -1;
	if (x == 'A') k = s1.top(), s1.pop();
	else if (x == 'B') k = s2.top(), s2.pop();
	else if (x == 'C') k = s3.top(), s3.pop();

	if (y == 'A') s1.push(k);
	else if (y == 'B') s2.push(k);
	else if (y == 'C') s3.push(k);

	stack<int> s4 = s1, s5=s2, s6=s3;

	vector<int> v1, v2, v3;
	while (s4.size()) {
		v1.pb(s4.top());
		s4.pop();
	}
	while (s5.size()) {
		v2.pb(s5.top());
		s5.pop();
	}
	while (s6.size()) {
		v3.pb(s6.top());
		s6.pop();
	}
	for (int i = v1.size()-1; i >= 0; i--) a[index][0].pb(v1[i]);
	for (int i = v2.size()-1; i >= 0; i--) a[index][1].pb(v2[i]);
	for (int i = v3.size()-1; i >= 0; i--) a[index][2].pb(v3[i]);

	index++;
	towers_of_hanoi(n - 1, z, y, x);
}

void towers_of_hanoi()
{
	for (int i = n; i > 0; i--) {
		s1.push(i);
		a[0][0].pb(i);
	}
	towers_of_hanoi(n, 'A', 'B', 'C');
}

void graphics()
{
	glClearColor(0, 0, 0, 0);
	glOrtho(-100, 100, -100, 100, -100, 100);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(10);
}

void looping()
{
	if (current == index) {
		exit(0);
	}
	sleep(1);
	current++;
	glutPostRedisplay();
}

void plotlines(int x1, int y1, int x2, int y2)
{
	glBegin(GL_LINES);
		GLV(x1, y1);
		GLV(x2, y2);
	glEnd();
	glFlush();
}

void playit()
{	
	glClear(GL_COLOR_BUFFER_BIT);

	plotlines(-33, 0, -33, 100);
	plotlines(0, 0, 0, 100);
	plotlines(33, 0, 33, 100);

	for (int i = 0; i < a[current][0].size(); i++) {
		glPointSize(a[current][0][i]*4);
		glBegin(GL_POINTS);
		GLV(-33, i*20);
		glEnd();
	}
	for (int i = 0; i < a[current][1].size(); i++) {
		glPointSize(a[current][1][i]*4);
		glBegin(GL_POINTS);
		GLV(0, i*20);
		glEnd();
	}
	for (int i = 0; i < a[current][2].size(); i++) {
		glPointSize(a[current][2][i]*4);
		glBegin(GL_POINTS);
		GLV(33, i*20);
		glEnd();
	}
	glFlush();
	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	take();
	towers_of_hanoi();
	cout << "towers of Hanoi " << endl;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Towers of Hanoi");
	graphics();
	glutDisplayFunc(playit);
	glutIdleFunc(looping);
	glutMainLoop();

	return 0;
}

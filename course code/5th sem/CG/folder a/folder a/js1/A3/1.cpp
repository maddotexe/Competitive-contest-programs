#include <iostream>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <map>
#include <cstring>
#include <cstdio>

#define inf 1000000

using namespace std;

struct color {
	double d1,d2,d3;
};

map<string, color> m;
string s;

void graphics() 
{ 
	glOrtho(-100, 100, -100, 100, -100, 100); 
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	color c1;
	c1.d1=1; c1.d2=0; c1.d3=0; m["red"] = c1;
	c1.d1=0; c1.d2=1; c1.d3=0; m["green"] = c1;
	c1.d1=0; c1.d2=0; c1.d3=1; m["blue"] = c1;
}

void playit()
{
	color c1=m[s];
	glColor3f(c1.d1,c1.d2,c1.d3);
	glBegin(GL_POLYGON);
		glVertex2f(0, 0);
		glVertex2f(0, 50);
		glVertex2f(50, 0);
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	cin >>s;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("hello world");
	graphics();
	glutDisplayFunc(playit);
	glutMainLoop();

	return 0;
}

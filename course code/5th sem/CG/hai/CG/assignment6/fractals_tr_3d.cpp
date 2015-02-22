#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <cmath>
using namespace std;

namespace {
	int o_size = 1;
};

void ResizeFunction(int Width, int Height)
{
	glOrtho(-o_size, o_size, -o_size, o_size, -o_size, o_size);
	glViewport(0, 0, Width, Height);
}



void func(int n, double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3)
{
	if (n <= 0) {
		glVertex3f(x1, y1, z1);
		glVertex3f(x2, y2, z2);
		glVertex3f(x3, y3, z3);
	} else {
		float dx = (x1 + x2) / 2;
		float dy = (y1 + y2) / 2;
		float dz = (z1 + z2) / 2;
		float ex = (x2 + x3) / 2;
		float ey = (y2 + y3) / 2;
		float ez = (z2 + z3) / 2;
		float fx = (x3 + x1) / 2;
		float fy = (y3 + y1) / 2;
		float fz = (z3 + z1) / 2;
		func(n-1, x1, y1, z1, dx, dy, dz, fx, fy, fz);
		func(n-1, x2, y2, z2, ex, ey, ez, dx, dy, dz);
		func(n-1, x3, y3, z3, fx, fy, fz, ex, ey, ez);
	}
}


void draw() 
{ 
 float ax = 0.0; 
 float ay = 0.5; 
 float az = -0.5; 
 float bx = -0.43; 
 float by = -0.25; 
 float bz = -0.5; 
 float cx = 0.43; 
 float cy = -0.25; 
 float cz = -0.5; 
 float dx = 0.0; 
 float dy = 0.0; 
 float dz = 0.0; 

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
 glBegin(GL_TRIANGLES); 
 glColor3f(0.5, 0.5, 0.5); 
 func(3, ax, ay, az, bx, by, bz, cx, cy, cz); 
 glColor3f(1.0, 0.0, 0.0); 
 func(3, dx, dy, dz, ax, ay, az, bx, by, bz); 
 glColor3f(0.0, 1.0, 0.0); 
 func(3, dx, dy, dz, bx, by, bz, cx, cy, cz); 
 glColor3f(0.0, 0.0, 1.0); 
 func(3, dx, dy, dz, cx, cy, cz, ax, ay, az); 
 glEnd(); 
 glFlush(); 
} 

void static RenderFunction(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	
		draw();
		// code ends here
	cout << "end" << endl;
	glutSwapBuffers();
//	glutPostRedisplay();
	glFlush();
}


int main(int argc, char** argv)
{

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

#include <iostream>
#include <cmath>
#include <GL/freeglut.h>
using namespace std;
void draw_circle()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);
	glOrtho(-11.0, 11.0, -11.0, 11.0, -11.0, 11.0);
	glPointSize(10.0f);
	glBegin(GL_POINTS);
//	glVertex3f(0.5f, 0.5f, 0.5f);
	for (float i = -3.14; i <= 3.14; i = i + 0.01) {
		glVertex3f(10*sin(i), 10*cos(i), 0.0);
		glVertex3f(10.5*sin(i), 10.5*cos(i), 0.0);
	}

	glEnd();
	float th = 0.0;
	glPointSize(9.0f);
	for (int i = 0; i < 20; i++) {
			
		glColor3f(0.0, 1.0, 0.0);
		glPointSize(10.0f);
		glBegin(GL_LINES);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(10*sin(th), 10*cos(th), 0.0);
		glEnd();
		th = th + 0.314;
	}
	
	glRotatef(10, 1, 0, 0);
	glFlush();

}

int main(int argc, char** argv)
{
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE);
        glutInitWindowSize(500, 500);
        glutInitWindowPosition(10, 10);
        glutCreateWindow("Point");
        glutDisplayFunc(draw_circle);
        glutMainLoop();

        return 0;
}



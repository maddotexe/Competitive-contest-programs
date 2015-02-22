#include <iostream>
#include <cmath>
#include "GL/freeglut.h"
#include "GL/gl.h"

using namespace std;

namespace {
	int o_size = 100;
	double x_one, y_one;
	double x_two, y_two;
	double sx, sy;
};

void ResizeFunction(int Width, int Height)
{
	glOrtho(-o_size, o_size, -o_size, o_size, -o_size, o_size);
	glViewport(0, 0, Width, Height);
}

void draw_axis()
{
	glPointSize(3);
	glBegin(GL_POINTS);
	for (float i = -o_size; i < o_size; i = i + 0.5) {
		glVertex2f(i, 0);
		glVertex2f(0, i);
	}
	glEnd();
}	

void scale()
{
	x_one += 10;
	y_one += 10;
	x_two += 10;
	y_two += 10;
	
	x_one *= sx;
	x_two *= sx;
	y_one *= sy;
	y_two *= sy;

}

void static RenderFunction(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	
	draw_axis();
	glPointSize(10);
	glLineWidth(5);
	// code actual here
	glBegin(GL_LINE);
		
		glVertex2f(x_one, y_one);	 
		glVertex2f(x_two, y_two);	

	glEnd();
	// after rotation
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINE);
		
		scale();
		glVertex2f(x_one, y_one);	 
		glVertex2f(x_two, y_two);	

	glEnd();
	// code ends here
	glutSwapBuffers();
//	glutPostRedisplay();
	glFlush();
}

void input()
{
	cout << "enter points" << endl;
	cin >> x_one >> y_one >> x_two >> y_two;

	cout << "enter scaling factors" << endl;
	cin >> sx >> sy;
}

int main(int argc, char** argv)
{
	
	input();

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

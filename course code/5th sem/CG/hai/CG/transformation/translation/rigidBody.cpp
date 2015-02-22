#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"

using namespace std;

namespace {
	int o_size = 100;
	float x0 = 0, y0 = 0;
	float trans_x, trans_y;
};

void ResizeFunction(int Width, int Height)
{
	glOrtho(-o_size, o_size, -o_size, o_size, -o_size, o_size);
	glViewport(0, 0, Width, Height);
}

void draw_axis()
{
	glPointSize(1);
	glBegin(GL_POINTS);
	for (float i = -o_size; i < o_size; i = i + 0.5) {
		glVertex2f(i, 0);
		glVertex2f(0, i);
	}
	glEnd();
}	

void  RenderFunction(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	
	draw_axis();
	glPointSize(3);
	// code actual here
	glBegin(GL_POINTS);
			 
		glVertex2f(x0, y0);	
		glVertex2f(trans_x + x0, trans_y + y0);	
	glEnd();
	// code ends here
	cout << "end" << endl;
	glutSwapBuffers();
//	glutPostRedisplay();
	glFlush();
}


void input()
{
	cout << "enter pints" <<  endl;
	cin >> x0 >> y0;
	cout << "enter trans_x , y " << endl;
	cin >> trans_x >> trans_y;
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

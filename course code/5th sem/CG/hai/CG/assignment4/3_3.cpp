#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"

using namespace std;

int o_size = 165;
struct node { double x,y,z; };
typedef struct node rgb;
static int s = 0;
static double r = 1;
static double g = 1;
static double b = 1;
static int counter = 0;
rgb M[65][65];


void mainfunction(double x, double x2, double y, double y2) {
	if ((x2 - x) <= 2) {
		return;
	}
	counter++;
	double midx = (x+x2) / 2;
	double midy = (y+y2) / 2;

	for (int i = x + 1; i <= midx; i++) {
		for (int j = y + 1; j <= midy; j++){
			M[i][j].x = (M[i][j].x + 1) / 2;
			M[i][j].y /= 2;
			M[i][j].z /= 2;
		}
	}
	for (int i = x + 1; i <= midx; i++) {
		for (int j = midy + 1; j <= y2; j++){
			M[i][j].y = (M[i][j].y + 1) / 2;
			M[i][j].x /= 2;
			M[i][j].z /= 2;
		}
	}
	for (int i = midx + 1; i <= x2; i++) {
		for (int j = y + 1; j <= midy; j++){
			M[i][j].z = (M[i][j].z + 1) / 2;
			M[i][j].y /= 2;
			M[i][j].x /= 2;
		}
	}
	for (int i = midx + 1; i <= x2; i++) {
		for (int j = midy + 1; j <= y2; j++){
			M[i][j].x = 1;
			M[i][j].y = 1;
			M[i][j].z = 1;
		}
	}
	mainfunction(x, midx, y, midy);
	mainfunction(x, midx, midy, y2);
	mainfunction(midx, x2, y, midy);
}


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


void static RenderFunction(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	
	draw_axis();

	glPointSize(1);
	// code actual here
	for (int i = 1; i < 65; i++) {
		for (int j = 1; j < 65; j++) {
			M[i][j].x = M[i][j].y = M[i][j].z = 1;
		}
	}
	mainfunction(0, 64, 0, 64);
	
	for (int i = 1; i <= 64; i++) {
		for (int j = 1; j <= 64; j++){
			glColor3f(M[i][j].x, M[i][j].y, M[i][j].z);
			glBegin(GL_POINTS);
				glVertex2f(i, j);
			glEnd();
		}
	}
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

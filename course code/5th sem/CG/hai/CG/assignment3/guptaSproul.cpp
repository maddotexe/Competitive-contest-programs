#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <cmath>
using namespace std;

namespace {
	int o_size = 100;
	float x_one, y_one;
	float x_two, y_two;
	float dx, dy, d;
};

void ResizeFunction(int Width, int Height)
{
	glOrtho(-o_size, o_size, -o_size, o_size, -o_size, o_size);
	glViewport(0, 0, Width, Height);
}

void IntensityPixel(float x, float y, float distance)
{
	double intensity = distance;
	glColor3f(distance, distance, distance);	
	glVertex2f(x, y);
}

void draw_axis()
{
	glPointSize(2);
	glBegin(GL_POINTS);
	for (float i = -o_size; i < o_size; i = i + 0.5) {
		glVertex2f(i, 0);
		glVertex2f(0, i);
	}
	glEnd();
}	


void static RenderFunction(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	
	draw_axis();
	glPointSize(3);
	// code actual here
	glBegin(GL_POINTS);
		
		dx = x_two - x_one;
		dy = y_two - y_one;
		d = 2 * dy  - dx;
		int incrE = 2 * dy;
		int incrNE = 2 *(dy - dx);

		// code for antialisaing
		int two_v_dx = 0;
		double invDenom = 1.0/(2 * sqrt(dx * dx + dy * dy));
		double two_dx_invDenom =  2 * dx * invDenom;
		// code end
		int x = x_one;
		int y = y_one;
		// code added for antialisaing
		IntensityPixel(x, y, 0); // start pixel
		IntensityPixel(x, y + 1, two_dx_invDenom);//neighbour above
		IntensityPixel(x, y - 1, two_dx_invDenom);//neighbour down
		// code end

		while (x < x_two) {
			if (d < 0) {
				//code for anti 
				two_v_dx = d + dx;
				// 
				d += incrE;
				x++;
			} else {
				//code
				two_v_dx = d - dx;
				//
				d += incrNE;
				x++;
				y++;
			}
			IntensityPixel(x, y, two_v_dx * invDenom); // start pixel
			IntensityPixel(x, y + 1, two_dx_invDenom - two_v_dx * invDenom);//neighbour above
			IntensityPixel(x, y - 1, two_dx_invDenom - two_v_dx * invDenom);//neighbour down
		}


	glEnd();
	// code ends here
	cout << "end" << endl;
	glutSwapBuffers();
//	glutPostRedisplay();
	glFlush();
}


int main(int argc, char** argv)
{
	cout << "enter p1, p2\n";
	cin >> x_one >> y_one >> x_two >> y_two;

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

#include <iostream>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <map>

#define CLEAR glClear(GL_COLOR_BUFFER_BIT)
#define FOR(i,a,n) for (int i=a;i<=n;i++)

#define inf 1000000

struct RGB { double x,y,z; };
typedef struct RGB rgb;

namespace 
{
	static int s = 0;
	static double r = 1;
	static double g = 1;
	static double b = 1;
	static int counter = 0;
	rgb M[65][65];
}

using namespace std;




void mainfunction(double x, double x2, double y, double y2) {
	if ((x2 - x) <= 2) {
		return;
	}
	counter++;
	cout << "counter " << counter << endl;
	double midx = (x+x2) / 2;
	double midy = (y+y2) / 2;

	FOR(i,x+1,midx) FOR(j,y+1,midy) {
			M[i][j].x = (M[i][j].x + 1) / 2;
			M[i][j].y /= 2;
			M[i][j].z /= 2;
		}
	FOR(i,x+1,midx) FOR(j,midy+1,y2) {
			M[i][j].y = (M[i][j].y + 1) / 2;
			M[i][j].x /= 2;
			M[i][j].z /= 2;
		}
	FOR(i,midx+1,x2) FOR(j,y+1,midy) {
			M[i][j].z = (M[i][j].z + 1) / 2;
			M[i][j].y /= 2;
			M[i][j].x /= 2;
		}
	FOR(i,midx+1,x2) FOR(j,midy+1,y2) M[i][j].x = M[i][j].y = M[i][j].z = 1;
	mainfunction(x, midx, y, midy);
	mainfunction(x, midx, midy, y2);
	mainfunction(midx, x2, y, midy);
}

void graphics() { 
	glOrtho(-65, 65, -65, 65, -65, 65); 
	glClearColor(0, 0, 0, 0);
	CLEAR;
	FOR(i,1,64) FOR(j,1,64) M[i][j].x = M[i][j].y = M[i][j].z = 1;
}

void playit() {
	mainfunction(0, 64, 0, 64);
	cout << "mainfunctiontion returned" << endl;
	FOR(i,1,64) FOR(j,1,64) {
			glColor3f(M[i][j].x, M[i][j].y, M[i][j].z);
			glBegin(GL_POINTS);
				glVertex2f(i, j);
			glEnd();
		}
	glFlush();
	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("hello world");
	graphics();
	glutDisplayFunc(playit);
	glutMainLoop();

	return 0;
}


#include <iostream>
#include <sstream>
#include <fstream>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

double toRadian(double deg);
void plotSkyMap();
void convert(double a[], double theta, double phi);

void renderFunction()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor (0.7, 0.7, 0.7, 0.5); 		// set white background		       
	
	plotSkyMap();
	// rotateGlobe();

	glFlush();
}


int main(int argc, char* argv[])
{
/*
	x2 /= m;
	y2 /= m;
	x1 /= m;
	y1 /= m;
*/
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("\t\tDraw Globe");
	
	
	glutDisplayFunc(renderFunction);
	glutMainLoop();    
	
	return 0;
}

void plotSkyMap()
{
	string s = "";
	char str[1000];
	int r1, r2, r3, r4;
	int d1, d2, d3, d4;
	float mag;
	int tmp;
	char temp[100];
	double theta, phi;
	double PI = M_PI;
	double secIn_1_DAY = 24 * 60 * 60 * 100;
	double numOfSec;
	double degree;
	double XYZ[3];
	
	ifstream inptr("input.txt");
	getline(inptr, s);
	getline(inptr, s);

	while (inptr.good()) {

		getline(inptr, s);
		
		for (int i = 0; i < s.size(); i++) {
			str[i] = s[i];
		}
		str[s.size()] = '\0';
		
		sscanf(str, "%d %d:%d:%d.%d %d:%d:%d.%d %*s %*s %*s %f", &tmp, &r1,&r2,&r3,&r4, &d1,&d2,&d3,&d4, &mag);
		printf("%d:%d:%d.%d %d:%d:%d.%d  %f", r1,r2,r3,r4, d1,d2,d3,d4, mag);
		
		numOfSec = r1*360000 + r2 * 6000 + r3 * 100 + r4;
		theta = PI*2 * numOfSec / secIn_1_DAY;
		
		degree = d1 + (float(d2 * 60 + d3)) / 3600.0;
		phi = toRadian(degree);
		
		convert(XYZ, theta, phi);

		glBegin(GL_POINTS);
			glVertex3f(XYZ[0], XYZ[1], XYZ[2]);
		glEnd();
		
		
	}
}

void convert(double a[], double theta, double phi)
{
	a[1] = sin(theta);
	a[0] = cos(theta)*cos(phi);
	a[2] = cos(theta)*sin(phi);

	//cout << "generate X, y, z" << endl;
}

double toRadian(double deg)
{
	return (M_PI/180 * deg);
}


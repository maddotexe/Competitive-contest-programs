//------------------------------------------------------------
/// \file	Main.cpp
/// \author	Rob Bateman
/// \date	9-feb-2005
/// \brief	The Chaikin curve is one of the simplest subdivison
/// 		curves around. It uses a very simple ratio method
/// 		to determine the new points on the curve. It can be
/// 		shown mathmatically that this curve is the same as
/// 		a quadratic b-spline.
//------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <vector>

/// a strcture to hold a curve point
struct Point {

	/// the position
	float x,y,z;

	/// ctor
	Point() : x(0),y(0),z(0){}

	/// ctor
	Point(const float a,const float b,const float c)
		:x(a),y(b),z(c){}

	/// copy ctor
	Point(const Point& p) : x(p.x),y(p.y),z(p.z) {}
};

/// a dynamic array of all points in the curve
std::vector<Point> Points;


//------------------------------------------------------------	IncreaseLod()
// When we increase the LOD we will have to re-create the points
// array inserting the new intermediate points into it.
//
//	Basically the subdivision works like this. each line,
//
//            A  *------------*  B
//
//	will be split into 2 new points, Q and R.
//
//                   Q    R
//            A  *---|----|---*  B
//
//	Q and R are given by the equations :
//
// 		Q = 3/4*A + 1/4*B
// 		R = 3/4*B + 1/4*A
//
void IncreaseLod() {
	std::vector<Point> NewPoints;

	// keep the first point
	NewPoints.push_back(Points[0]);
	for(unsigned int i=0;i<(Points.size()-1);++i) {
	
		// get 2 original points
		const Point& p0 = Points[i];
		const Point& p1 = Points[i+1];
		Point Q;
		Point R;

		// average the 2 original points to create 2 new points. For each
		// CV, another 2 verts are created.
		Q.x = 0.75f*p0.x + 0.25f*p1.x;
		Q.y = 0.75f*p0.y + 0.25f*p1.y;
		Q.z = 0.75f*p0.z + 0.25f*p1.z;

		R.x = 0.25f*p0.x + 0.75f*p1.x;
		R.y = 0.25f*p0.y + 0.75f*p1.y;
		R.z = 0.25f*p0.z + 0.75f*p1.z;

		NewPoints.push_back(Q);
		NewPoints.push_back(R);
	}
	// keep the last point
	NewPoints.push_back(Points[Points.size()-1]);

	// update the points array
	Points = NewPoints;
}
//------------------------------------------------------------	DecreaseLod()
// When we decrease the LOD, we can rather niftily get back
// to exactly what we had before. Since the original subdivision
// simply required a basic ratio of both points, we can simply
// reverse the ratio's to get the previous point...
//
void DecreaseLod() {

	// make sure we dont loose any points!!
	if (Points.size()<=4) 
		return;

	std::vector<Point> NewPoints;

	// keep the first point
	NewPoints.push_back(Points[0]);

	// step over every 2 points
	for(unsigned int i=1;i<(Points.size()-1);i+=2) {

		// get last point found in reduced array
		const Point& pLast = NewPoints[NewPoints.size()-1];

		// get 2 original point
		const Point& p0 = Points[i];
		Point Q;

		// calculate the original point
		Q.x = p0.x - 0.75f*pLast.x;
		Q.y = p0.y - 0.75f*pLast.y;
		Q.z = p0.z - 0.75f*pLast.z;

		Q.x *= 4.0f;
		Q.y *= 4.0f;
		Q.z *= 4.0f;

		// add to new curve
		NewPoints.push_back(Q);
	}

	// copy over points
	Points = NewPoints;
}


//------------------------------------------------------------	OnKeyPress()
//
void OnKeyPress(unsigned char key,int,int) {
	switch(key) {

	// increase the LOD
	case '+':
		IncreaseLod();
		break;

	// decrease the LOD
	case '-':
		DecreaseLod();
		break;
	default:
		break;
	}

	// ask glut to redraw the screen for us...
	glutPostRedisplay();
}


//------------------------------------------------------------	OnDraw()
//
void OnDraw() {

	// clear the screen & depth buffer
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

	// clear the previous transform
	glLoadIdentity();

	// set the camera position
	gluLookAt(	1,10,30,	//	eye pos
				0,0,0,	//	aim point
				0,1,0);	//	up direction

	glColor3f(1,1,0);
	glBegin(GL_LINE_STRIP);

	// iterate through all curve points and render
	std::vector<Point>::iterator it = Points.begin();
	for(;it != Points.end();++it) {

		// specify the point
		glVertex3f( it->x,it->y,it->z );
	}
	glEnd();

	// currently we've been drawing to the back buffer, we need
	// to swap the back buffer with the front one to make the image visible
	glutSwapBuffers();
}

//------------------------------------------------------------	OnInit()
//
void OnInit() {
	// enable depth testing
	glEnable(GL_DEPTH_TEST);

	// create the initial curve points
	Points.push_back( Point(10,10,0) );
	Points.push_back( Point(5,10,2)  );
	Points.push_back( Point(-5,0,0)  );
	Points.push_back( Point(-10,5,-2));
}

//------------------------------------------------------------	OnExit()
//
void OnExit() {
}

//------------------------------------------------------------	OnReshape()
//
void OnReshape(int w, int h)
{
	if (h==0)
		h=1;

	// set the drawable region of the window
	glViewport(0,0,w,h);

	// set up the projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// just use a perspective projection
	gluPerspective(45,(float)w/h,0.1,100);

	// go back to modelview matrix so we can move the objects about
	glMatrixMode(GL_MODELVIEW);
}


//------------------------------------------------------------	main()
//
int main(int argc,char** argv) {

	// initialise glut
	glutInit(&argc,argv);

	// request a depth buffer, RGBA display mode, and we want double buffering
	glutInitDisplayMode(GLUT_DEPTH|GLUT_RGBA|GLUT_DOUBLE);

	// set the initial window size
	glutInitWindowSize(640,480);

	// create the window
	glutCreateWindow("Chaikin Curve: +/- to Change Level of Detail");

	// set the function to use to draw our scene
	glutDisplayFunc(OnDraw);

	// set the function to handle changes in screen size
	glutReshapeFunc(OnReshape);

	// set the function for the key presses
	glutKeyboardFunc(OnKeyPress);
	
	// run our custom initialisation
	OnInit();

	// set the function to be called when we exit
	atexit(OnExit);

	// this function runs a while loop to keep the program running.
	glutMainLoop();
	return 0;
}

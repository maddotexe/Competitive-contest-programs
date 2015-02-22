//------------------------------------------------------------
/// \file	Main.cpp
/// \author	Rob Bateman
/// \date	9-feb-2005
/// \brief	This sample demonstrates a bspline. I recommend
/// 		first looking at the bezier curve example before
/// 		this one.
/// 			The only difference between a bezier curve and
/// 		a bspline is that it uses a different set of
/// 		blending functions. This actually produces a much
/// 		shorter curve than the equivalent bezier, however
/// 		the advantage is that any curve that shares 3 control
/// 		points will remain continuos. ie, by drawing seperate
/// 		curve segments we can use as many control points
/// 		as needed.
//------------------------------------------------------------

#include <stdlib.h>
#include <GL/glut.h>

/// the control points for the curve
float Points[4][3] = {
	{ 10,10,0 },
	{  5,10,2 },
	{ -5,0,0 },
	{-10,5,-2}
};

/// the level of detail of the curve
unsigned int LOD=20;

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

	// use the parametric time value 0 to 1
	for(int i=0;i!=LOD;++i) {

		float t = (float)i/(LOD-1);

		// the t value inverted
		float it = 1.0f-t;

		// calculate blending functions
		float b0 = it*it*it/6.0f;
		float b1 = (3*t*t*t - 6*t*t +4)/6.0f;
		float b2 = (-3*t*t*t +3*t*t + 3*t + 1)/6.0f;
		float b3 =  t*t*t/6.0f;

		// sum the control points mulitplied by their respective blending functions
		float x = b0*Points[0][0] +
				  b1*Points[1][0] + 
				  b2*Points[2][0] + 
				  b3*Points[3][0] ;

		float y = b0*Points[0][1] + 
				  b1*Points[1][1] + 
				  b2*Points[2][1] + 
				  b3*Points[3][1] ;

		float z = b0*Points[0][2] + 
				  b1*Points[1][2] + 
				  b2*Points[2][2] + 
				  b3*Points[3][2] ;

		// specify the point
		glVertex3f( x,y,z );
	}
	glEnd();

	// draw the control points
	glColor3f(0,1,0);
	glPointSize(3);
	glBegin(GL_POINTS);
	for(int i=0;i!=4;++i) {
		glVertex3fv( Points[i] );
	}
	glEnd();

	// draw the hull of the curve
	glColor3f(0,1,1);
	glBegin(GL_LINE_STRIP);
	for(int i=0;i!=4;++i) {
		glVertex3fv( Points[i] );
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
}

//------------------------------------------------------------	OnExit()
//
void OnExit() {
}

//------------------------------------------------------------	OnKeyPress()
//
void OnKeyPress(unsigned char key,int,int) {
	switch(key) {

	// increase the LOD
	case '+':
		++LOD;
		break;

	// decrease the LOD
	case '-':
		--LOD;

		// have a minimum LOD value
		if (LOD<3) 
			LOD=3;
		break;
	default:
		break;
	}

	// ask glut to redraw the screen for us... 
	glutPostRedisplay();
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
	glutCreateWindow("Bezier Curve: +/- to Change Level of Detail");

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

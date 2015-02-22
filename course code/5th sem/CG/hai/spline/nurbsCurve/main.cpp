//------------------------------------------------------------
/// \file	Main.cpp
/// \author	Rob Bateman
/// \date	9-feb-2005
/// \brief	This is a very simple example of a bezier curve
//------------------------------------------------------------

#include <stdlib.h>
#include <GL/glut.h>

float g_Points[7][3] = { 
	{ 10,10,0 },
	{  5,10,2 },
	{ -5,5,0 },
	{-10,5,-2},
	{-4,10,0},
	{-4,5,2},
	{-8,1,0}
};
float g_Knots[] = {0.0f,0.0f,0.0f,0.0f,1.0f,2.0f,3.0f,4.0f,4.0f,4.0f,4.0f};
unsigned int g_num_cvs=7;
unsigned int g_degree=3;
unsigned int g_order=g_degree+1;
unsigned int g_num_knots=g_num_cvs+g_order;

unsigned int LOD=20;

//------------------------------------------------------------	CoxDeBoor()
//
float CoxDeBoor(float u,int i,int k,const float* Knots) {
	if(k==1)
	{
		if( Knots[i] <= u && u <= Knots[i+1] ) {
			return 1.0f;
		}
		return 0.0f;
	}
	float Den1 = Knots[i+k-1] - Knots[i];
	float Den2 = Knots[i+k] - Knots[i+1];
	float Eq1=0,Eq2=0;
	if(Den1>0) {
		Eq1 = ((u-Knots[i]) / Den1) * CoxDeBoor(u,i,k-1,Knots);
	}
	if(Den2>0) {
		Eq2 = (Knots[i+k]-u) / Den2 * CoxDeBoor(u,i+1,k-1,Knots);
	}
	return Eq1+Eq2;
}

//------------------------------------------------------------	GetOutpoint()
//
void GetOutpoint(float t,float OutPoint[]) {

	// sum the effect of all CV's on the curve at this point to 
	// get the evaluated curve point
	// 
	for(unsigned int i=0;i!=g_num_cvs;++i) {

		// calculate the effect of this point on the curve
		float Val = CoxDeBoor(t,i,g_order,g_Knots);

		if(Val>0.001f) {

			// sum effect of CV on this part of the curve
			OutPoint[0] += Val * g_Points[i][0];
			OutPoint[1] += Val * g_Points[i][1];
			OutPoint[2] += Val * g_Points[i][2];
		}
	}
}


//------------------------------------------------------------	Draw()
//
void OnDraw() {

	// clear the screen & depth buffer
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

	// clear the previous transform
	glLoadIdentity();

	// set the camera position
	gluLookAt(	1,10,26,	//	eye pos
				0,5,0,	//	aim point
				0,1,0);	//	up direction

	glColor3f(1,1,0);
	glBegin(GL_LINE_STRIP);
	for(int i=0;i!=LOD;++i) {

		float t  = g_Knots[g_num_knots-1] * i / (float)(LOD-1);

		if(i==LOD-1) 
			t-=0.001f;

		float Outpoint[3]={0,0,0};

		GetOutpoint(t,Outpoint);

		glVertex3fv(Outpoint);
	}
	glEnd();

	glColor3f(1,0,0);
	glPointSize(3);
	glBegin(GL_POINTS);
	for(int i=0;i!=g_num_cvs;++i) {
		glVertex3fv(g_Points[i]);
	}
	glEnd();

	// currently we've been drawing to the back buffer, we need
	// to swap the back buffer with the front one to make the image visible
	glutSwapBuffers();
}
//------------------------------------------------------------	Reshape()
//
void OnReshape(int w, int h)
{
	if (h==0) {
		h=1;
	}

	// set the drawable region of the window
	glViewport(0,0,w,h);

	// set up the projection matrix 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// just use a perspective projection
	gluPerspective(45,(float)w/h,0.1,100);

	// go back to modelview matrix so we can move the objects about
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
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
		LOD+=2;
		break;

	// decrease the LOD
	case '-':
		LOD-=2;

		// have a minimum LOD value
		if (LOD<4) 
			LOD=4;
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
	glutCreateWindow("Nurbs Curve: +/- to Change Level of Detail");

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

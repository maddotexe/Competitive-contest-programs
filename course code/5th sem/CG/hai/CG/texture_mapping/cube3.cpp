#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <cstdio>
#include <cmath>
using namespace std;
#define checkImageWidth 64
#define checkImageHeight 64

static GLubyte checkImage[checkImageHeight][checkImageWidth][4];
static GLuint texName;

namespace {
	int o_size = 100;
};


GLuint LoadTexture( const char * filename )
{
	GLuint texture;
	int width, height;
	unsigned char * data;
	FILE * file;
	file = fopen( filename, "rb" );

	if ( file == NULL ) return 0;
		width = 1024;
		height = 512;
	data = (unsigned char *)malloc( width * height * 3 );
	fread( data, width * height * 3, 1, file );
	fclose( file );

	for(int i = 0; i < width * height ; ++i)
	{
		int index = i*3;
		unsigned char B,R;
		B = data[index];
		R = data[index+2];

		data[index] = R;
		data[index+2] = B;
	}


	glGenTextures( 1, &texture );
	glBindTexture( GL_TEXTURE_2D, texture );
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_DECAL );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );

	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
	gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
	free(data);

	return texture;
}

void init()
{
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	texName = LoadTexture("earth.bmp");
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
}
void timer(int v)
{
	static GLfloat u = 0.0;
	u += 0.01;
	glLoadIdentity();
	gluLookAt(8 * cos(u), 7 * cos(u) - 1, 4 * cos(u/3) + 2, 0.5, 0.5, 0.5, cos(u), 1, 0);
	glutPostRedisplay();
	glutTimerFunc(1000/60.0, timer, v);

}
void ResizeFunction(int Width, int Height)
{
	glOrtho(-o_size, o_size, -o_size, o_size, -o_size, o_size);
	glViewport(0, 0, Width, Height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, GLfloat(Width)/ GLfloat(Height), 0.5, 40);
	glMatrixMode(GL_MODELVIEW);
}

void start()
{
	sleep(1);
	glutPostRedisplay();
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
int r = 0;
void static RenderFunction(void)
{
	glPushMatrix();
	glRotatef(r, 0.7, .7, 0.7);
	r += 10;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glEnable(GL_TEXTURE_2D);	
//	draw_axis();
	glPointSize(5);
	// code actual here
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 10.0);
		glTexCoord2f(0.0, 1.0); glVertex3f(0, 10, 10.0);
		glTexCoord2f(1.0, 1.0); glVertex3f(0, 10, 0.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(0, 0, 0.0);
	glEnd();
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(0, 10, 0.0);
		glTexCoord2f(0.0, 1.0); glVertex3f(10, 10, 0.0);
		glTexCoord2f(1.0, 1.0); glVertex3f(10, 0, 0.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(0, 0, 0.0);
	glEnd();
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(10, 10, 0.0);
		glTexCoord2f(0.0, 1.0); glVertex3f(10, 0, 0.0);
		glTexCoord2f(1.0, 1.0); glVertex3f(10, 0, 10.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(10, 10, 10.0);
	glEnd();
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(0, 10, 10.0);
		glTexCoord2f(0.0, 1.0); glVertex3f(0, 10, 0.0);
		glTexCoord2f(1.0, 1.0); glVertex3f(10, 10, 0.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(10, 10, 10.0);
	glEnd();
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0.0);
		glTexCoord2f(0.0, 1.0); glVertex3f(10, 0, 0.0);
		glTexCoord2f(1.0, 1.0); glVertex3f(10, 0, 10.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(0, 0, 10.0);
	glEnd();
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(0, 10, 10.0);
		glTexCoord2f(0.0, 1.0); glVertex3f(10, 10, 10.0);
		glTexCoord2f(1.0, 1.0); glVertex3f(10, 0, 10.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(0, 0, 10.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
		glVertex3f(0, 0, 10.0);
		 glVertex3f(0, 10, 10.0);
		glVertex3f(0, 10, 0.0);
		glVertex3f(0, 0, 0.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(0, 10, 0.0);
		glVertex3f(10, 10, 0.0);
		glVertex3f(10, 0, 0.0);
		glVertex3f(0, 0, 0.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
		 glVertex3f(10, 10, 0.0);
		 glVertex3f(10, 0, 0.0);
		 glVertex3f(10, 0, 10.0);
		 glVertex3f(10, 10, 10.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(0, 10, 10.0);
		 glVertex3f(0, 10, 0.0);
		 glVertex3f(10, 10, 0.0);
		 glVertex3f(10, 10, 10.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
		 glVertex3f(0, 0, 0.0);
		glVertex3f(10, 0, 0.0);
		 glVertex3f(10, 0, 10.0);
		 glVertex3f(0, 0, 10.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
		 glVertex3f(0, 10, 10.0);
		glVertex3f(10, 10, 10.0);
		 glVertex3f(10, 0, 10.0);
		 glVertex3f(0, 0, 10.0);
	glEnd();
	glPopMatrix();
	// code ends here
	cout << "end" << endl;
	glutSwapBuffers();
	glFlush();
	//glDisable(GL_TEXTURE_2D);
}



int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("");
	init();
	glutReshapeFunc(ResizeFunction);
	glutTimerFunc(100, timer, 0);
	glutDisplayFunc(RenderFunction);
	
	
	glutMainLoop();


	return 0;
}

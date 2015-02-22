#include <GL/glut.h>
#include <iostream>

using namespace std;

int r = 0;

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#define checkImageWidth 64
#define checkImageHeight 64

static GLubyte checkImage[checkImageHeight][checkImageWidth][4];
static GLuint texName;

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
	free( data );

	return texture;
}

void init()
{
	glOrtho(-100, 100, -100, 100, -100, 100);
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.3, 0.3, 0.3);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	texName= LoadTexture( "earth.bmp");
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
}

void func1()
{
	glColor3f(0.3, 0.3, 0.3);
	glClear(GL_COLOR_BUFFER_BIT);
	glRotatef(r, .71, .71, 0.71);
	r += 10;
	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texName);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0); 
		glTexCoord2f(0.0, 1); glVertex3f(0, 50, 0);
		glTexCoord2f(1, 1); glVertex3f(50, 50, 0);
		glTexCoord2f(1, 0.0); glVertex3f(50, 0, 0);
	glEnd();
        
glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0); 
		glTexCoord2f(0.0, 1); glVertex3f(0, 0, 50);
		glTexCoord2f(1, 1); glVertex3f(0, 50, 50);
		glTexCoord2f(1, 0.0); glVertex3f(0, 50, 0);
	glEnd();
glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0); 
		glTexCoord2f(0.0, 1); glVertex3f(0, 0, 50);
		glTexCoord2f(1, 1); glVertex3f(50, 0, 50);
		glTexCoord2f(1, 0.0); glVertex3f(50, 0, 0);
	glEnd();

glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(50, 0, 0); 
		glTexCoord2f(0.0, 1); glVertex3f(50, 0, 50);
		glTexCoord2f(1, 1); glVertex3f(50, 50, 50);
		glTexCoord2f(1, 0.0); glVertex3f(50, 50, 0);
	glEnd();
        
glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(0, 50, 0); 
		glTexCoord2f(0.0, 1); glVertex3f(0, 50, 50);
		glTexCoord2f(1, 1); glVertex3f(50, 50, 50);
		glTexCoord2f(1, 0.0); glVertex3f(50, 50, 0);
	glEnd();
glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 50); 
		glTexCoord2f(0.0, 1); glVertex3f(0, 50, 50);
		glTexCoord2f(1, 1); glVertex3f(50, 50, 50);
		glTexCoord2f(1, 0.0); glVertex3f(50, 0, 50);
	glEnd();



/*
	
	
	
	glBegin(GL_POLYGON);
		glVertex3f(50, 0, 0);
		glVertex3f(50, 50, 0);
		glVertex3f(50, 50, 50);
		glVertex3f(50, 0, 50);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(0, 50, 0);
		glVertex3f(0, 50, 50);
		glVertex3f(50, 50, 50);
		glVertex3f(50, 50, 0);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(0, 0, 50);
		glVertex3f(50, 0, 50);
		glVertex3f(50, 50, 50);
		glVertex3f(0, 50, 50);
	glEnd();*/
	glDisable(GL_TEXTURE_2D);
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 50, 0);
		glVertex3f(50, 50, 0);
		glVertex3f(50, 0, 0);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 50);
		glVertex3f(0, 50, 50);
		glVertex3f(0, 50, 0);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 50);
		glVertex3f(50, 0, 50);
		glVertex3f(50, 0, 0);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(50, 0, 0);
		glVertex3f(50, 50, 0);
		glVertex3f(50, 50, 50);
		glVertex3f(50, 0, 50);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(0, 50, 0);
		glVertex3f(0, 50, 50);
		glVertex3f(50, 50, 50);
		glVertex3f(50, 50, 0);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(0, 0, 50);
		glVertex3f(50, 0, 50);
		glVertex3f(50, 50, 50);
		glVertex3f(0, 50, 50);
	glEnd();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

void start()
{
	sleep(1);
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_SINGLE);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("cube");
	init();
	glutDisplayFunc(func1);
	glutIdleFunc(start);
	glutMainLoop();

	return 0;
}


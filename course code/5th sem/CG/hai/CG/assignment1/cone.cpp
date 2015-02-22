#include <iostream> 
#include "GL/freeglut.h" 
#include "GL/gl.h" 
#include <cmath> 
#include <climits> 
  
using namespace std; 
  
void renderFunction() 
{ 
    glClearColor(0.0, 0.0, 0.0, 0.0); 
    glClear(GL_COLOR_BUFFER_BIT); 
    glColor3f(1.0, 0.0, 0.0); 
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0); 
//  glPointSize(10);         
  
    glBegin(GL_POINTS); 
    double l = 1.2;  
    // using glvertex to draw a point 
    for (double i = 1.0; i >= 0; i = i - 0.05) { 
        for (double theta = -3.14; theta <= 3.14; theta += 0.01) { 
            glVertex3f(i*cos(theta), i*sin(theta), l); 
        } 
        l += 0.03; 
    } 
  
      
    glEnd(); 
    glFlush(); 
} 
  
int main(int argc, char** argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE); 
    glutInitWindowSize(700, 700); 
    glutInitWindowPosition(10, 10); 
    glutCreateWindow(""); 
    glutDisplayFunc(renderFunction); 
    glutMainLoop(); 
  
    return 0; 
} 

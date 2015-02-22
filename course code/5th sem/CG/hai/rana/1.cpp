    #include <iostream>
    #include <cmath>
   // #include <windows.h>
  //  #include <gl/Gl.h>
 //   #include <gl/Glu.h>
    # include <GL/freeglut.h>
    using namespace std;

    double r=600/4,delta=1/r;
    float xc=0,yc=0,a=40,k=5,phy=0,z=0.3,d=0.1;
    void drawcircle(double x0,double y0,double r){
    const float PI = 3.1515f;
    const float DEGTORAD = PI/180.0f;
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < 360; ++i){
    float posX = std::cos(i*DEGTORAD) * r + x0;
    float posY = std::sin(i*DEGTORAD) * r + y0;
    glVertex3f( posX, posY , 0.0f );
    }
    glEnd();
    }
    void handleResize(int w,int h)
    {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,(double)w/(double)h,1.0,200.0);
    }
    float angle = 30.0f;
    void myStyleInit(int red,int green,int blue)
    {
    glClearColor(red,green,blue,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glPointSize(3);
    gluOrtho2D(-150.0, 150.0,-150.0,150.0);
    }
    void drawScene()
    {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0,0);
    glPointSize(3);
    drawcircle(800/2,600/2,r);
    drawcircle(800/2,600/2,(3*r)/4);
    drawcircle(800/2,600/2,r/2);
    drawcircle(800/2,600/2,r/4);
    drawcircle(800/2,600/2,r/8);
    glFlush();
    glutSwapBuffers();
    }
    void move(int state)
    {
    if(xc>=150-a || xc<=-150+a)
    {
    z*=-1;
    xc+=z;
    yc+=d;
    phy+=0.01;
    }
    if(yc>=150-a || yc<=-150+a)
    {
    d*=-1;
    xc+=z;
    yc+=d;
    phy+=0.01;
    }
    else
    {
    xc+=z;
    yc+=d;
    phy+=0.01;
    }
    glutPostRedisplay();
    glutTimerFunc(1,move,0);
    }
    int main()
    {
    int mainWindow;
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(300,200);
    glutInitWindowSize(900,900);
    mainWindow = glutCreateWindow("Stress Ball");
    myStyleInit(1,1,1);
    glutDisplayFunc(drawScene);
    glutTimerFunc(1,move,0);
    glutMainLoop();
    }

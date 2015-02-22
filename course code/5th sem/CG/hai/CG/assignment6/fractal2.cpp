#include <windows.h>
#include <gl/gl.h>
#include <math.h>
#include "opengl.h"
#include "Complex_Number.cpp"

// Prototype for calculation of the pixel
Complex_Number getest(Complex_Number pt, Complex_Number c_temp);
// Define global functions/variables used in creating the fractal
void drawfractal(MSG msg, HDC hDC);

bool bQuit = false;  // termination condition
int color=0;
int GLOB;

LRESULT CALLBACK
WndProc( HWND hWnd, UINT message,
         WPARAM wParam, LPARAM lParam );

// WinMain
int WINAPI
WinMain( HINSTANCE hInstance,
         HINSTANCE hPrevInstance,
         LPSTR lpCmdLine,
         int iCmdShow )
{
  WNDCLASS wc;
  HWND hWnd;
  HDC hDC;
  HGLRC hRC;
  MSG msg;
  int cx=GetSystemMetrics(SM_CXSCREEN);
  int cy=GetSystemMetrics(SM_CYSCREEN);
  // register window class

  wc.style = CS_OWNDC;
  wc.lpfnWndProc = WndProc;
  wc.cbClsExtra = 0;
  wc.cbWndExtra = 0;
  wc.hInstance = hInstance;
  wc.hIcon = LoadIcon( NULL, IDI_APPLICATION );
  wc.hCursor = LoadCursor( NULL, IDC_CROSS );
  wc.hbrBackground = (HBRUSH)GetStockObject( BLACK_BRUSH );
  wc.lpszMenuName = NULL;
  wc.lpszClassName = "Fractal";
  RegisterClass( &wc );

  // create main window
  hWnd = CreateWindow(
    "Fractal", "Fractal",
    WS_POPUPWINDOW | WS_VISIBLE,
    0, 0, cx, cy,        //cx, cy
    NULL, NULL, hInstance, NULL );


  // enable OpenGL for the window
   EnableOpenGL( hWnd, &hDC, &hRC );
	randomize();

  // program main loop
  while ( !bQuit ) {

    // check for messages
    if ( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) ) {

      // handle or dispatch messages
      if ( msg.message == WM_QUIT ) {
        bQuit = TRUE;
      } else {
        TranslateMessage( &msg );
        DispatchMessage( &msg );
      }

    }

	 /* Create Fractal and display on screen */
    else
    {
      GLOB=rand()%10+1;
	   drawfractal(msg, hDC);
		color++;
   }
  }

  // shutdown OpenGL
  DisableOpenGL( hWnd, hDC, hRC );

  // destroy the window explicitly
  DestroyWindow( hWnd );

  return msg.wParam;

}

// Window Procedure

LRESULT CALLBACK
WndProc( HWND hWnd, UINT message,
         WPARAM wParam, LPARAM lParam )
{

  switch ( message ) {

  case WM_CREATE:
    return 0;

  case WM_LBUTTONDOWN:
  	bQuit = TRUE;
   return 0;

  case WM_RBUTTONDOWN:
  	bQuit = TRUE;
   return 0;

  case WM_SETCURSOR:
    SetCursor(NULL);
    break;


  case WM_MOUSEMOVE:
// uncomment for screen saver version
/*      POINT pt;
    GetCursorPos(&pt);
    if ((m_ypos == -1) && (m_xpos == -1)) // have not captured mouse yet...
    	{
	    m_xpos = pt.x;
	    m_ypos = pt.y;
      }
    else {
    	if ((pt.x != m_xpos) || (pt.y != m_ypos)) bQuit=TRUE;
      }

*/
    return 0;

  case WM_KEYDOWN:
  bQuit = TRUE;
  return 0;

  case WM_CLOSE:
    PostQuitMessage( 0 );
    return 0;

  case WM_DESTROY:
    return 0;

  default:
    return DefWindowProc( hWnd,
      message, wParam, lParam );

  }
  return 0;
}

void drawfractal(MSG msg, HDC hDC)

{

double a, b;

Complex_Number c(0,-1);
Complex_Number point(1,1);
Complex_Number temp(0,0);

const double STEP = .0017; // Pixel Separation
const double bound = 1;  // Screen bounds

for (double y = -bound; y<bound; y+=STEP) {
for (double x = -bound; x<bound; x+=STEP) {
	if (bQuit == TRUE) break;  // must still yield control

   // This yields control to windows
   // while still executing a CPU intensive loop
    if ( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) ) {

      if ( msg.message == WM_QUIT ){ 	bQuit = TRUE;}
      else {
        TranslateMessage( &msg );
        DispatchMessage( &msg );

      }
    }

   // Now for the CPU intensive part
   else
   {
	   glBegin(GL_POINTS);
	   point = getest(point, c);
      point.Get_ab(a, b);
      glVertex2d(a,b);
   	glEnd();
      point.Set_ab(x, y);
   }

 }
      SwapBuffers( hDC );
      glFlush();
 }  //End of for loop

}

Complex_Number getest(Complex_Number pt, Complex_Number c_temp)
{
double red=0;
double green=0;
double blue=0;

   double a, b;
   pt.Get_ab(a, b);
	Complex_Number temp(a,b);

   for (int i=0; i<15; i++) {
	   double j, k;
   // get good estimate for point
   // need to test if going infinity or not.

	   for (int dum=0; dum < GLOB; dum ++)
	   {
	  		temp.Multiply(pt);
	   }
	      temp.Add(c_temp);
	      temp.Get_ab(j, k);
	      pt.Set_ab(j,k);

	      	if ((fabs(j) > 10) || (fabs(k) > 10))
		      {
					red =log(fabs(k)+1)*.25;
	            green=sin(.005*j);
	            blue=(1/log(i+2))*.25;
			      break;
	         }
   	}
	// set color based on observations....
	if (color%5==0)
		glColor3f (blue,green,red);// blue
	else if (color%2==0)
		glColor3f (green,red,blue);// green
	else
		glColor3f (red,blue,green); //red

	pt.Set_ab(a,b);
	return pt;

}



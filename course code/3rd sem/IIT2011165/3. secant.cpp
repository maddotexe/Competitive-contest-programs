#include <iostream>
#include <math.h>

using namespace std;
//function claculator
float f(float x, float a, float b, float c) {
      float y;
      y = a * x * x + b * x + c;
      return y;
}
int main()
{
    float a, b, c, x0, x1, x2, y0, y1, y2;
    //input
    cin >> a >> b >> c >> x0 >> x1;
    //secant operation
    while( ((x0 - x1) > 0.001) || ((x1 - x0) > 0.001)) {
           y0 = f(x0, a, b, c);
           y1 = f(x1, a, b, c);
          // x2 = (x0 + x1)/2;
          x2 = x0 - ((x0 - x1)/(y0 - y1)) * y0;
          if(fabs(x0) < fabs(x1)) {
                cout << "a root in " << x0 << x2 << endl;
                x1 = x2;
          }
          else {
               cout << "a root in " << x2 << x1 << endl;;
               x0 = x2;
          } 
    }
    //output
    cout << x0 << endl;
    getchar();
    getchar();
    return 0;
} 


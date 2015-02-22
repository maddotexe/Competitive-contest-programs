#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
//given function calculator
float f(float x, float a, float b, float c) {
      float y = a * x * x + b * x + c;
      return y;
}

int main()
{
    float a, b, c, x0, x1, x2, y0, y1, y2;
    //input
    cin >> a >> b >> c >> x0 >> x1;
    cout << y0;
    //bisection operation
    while(((x1 - x0) > 0.001)|| ((x0 - x1) > 0.001)) {
             y0 = f(x0, a, b, c);
             y1 = f(x1, a, b, c);
             x2 = (x0 + x1)/2;
             y2 = f(x2, a, b, c);
             if(y0 * y2 < 0) {
                   cout << "a root in" << x0 << x2 << endl;
                   x1 = x2;
             }
             else {
                  cout << "a root in" << x2 << x1 << endl;
                  x0 = x2;
             }
    }
    //output
    cout << x0 << endl;
    return 0;
}
                   
                   
                
      

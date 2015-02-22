#include <iostream>
# define h 0.1
using namespace std;

double f(double x, double y) {
	return (x *y + y * y);
}

int main()
{
    double x0, y0, x1, k[5], x, y;
    //input
    cin >> x0 >> y0 >> x1;
    x = x0;
    y = y0;
    cout <<"x0 = " << x0 << "\ny0 = " << y0 << "\nx1 = \n";
    //soving through runga-kutta 
    while (1) {
          k[1] = h * f(x , y);
          k[2] = h * f(x + h/2, y + k[1]/2);
          k[3] = h * f(x + h/2, y + k[2]/2);
          k[4] = h * f(x + h, y + k[3]);
          k[0] = (k[1] + 2*k[2] + 2*k[3] + k[4]) /6;
          y = y + k[0];
          x = x + h;
          if(x >= x1)
               break;
    }
    //input
    cout << y;

    
    return 0;
}

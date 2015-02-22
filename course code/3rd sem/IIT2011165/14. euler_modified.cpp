#include <iostream>

using namespace std;

double f(double x, double y) {
	return (x + y);
}

int main()
{
	double i, h, y0, y, y1, x, x0, x1, y2;
	//input
	cout << "enter the value of h , x0, y0 and x1 : ";
	cin >> h >> x0 >> y0 >> x1;
	
 	y = y0;
 	x = x0;
 	//applying euler
	while(1) {
		y1 = y + h * f(x, y);
		y2 = y1;
		cout << y1 << endl;
		while(1) {
                 y2 = y + h / 2 * (f(x, y) + f(x + h, y2));
                 if ((y2 > y1? y2 - y1: y1 - y2) < 0.0001) 
                    break;
                 y1 = y2;
        }
		x = x + h;
		y = y1;
		cout << y << endl;
		if(x >= x1) 
			break;
	} 
	//output
	cout << y;
    cin >> x;
	return 0;
}

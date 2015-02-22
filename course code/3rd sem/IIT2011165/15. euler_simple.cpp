#include <iostream>

using namespace std;

double f(double x, double y) {
	return (x + y);
}

int main()
{
	double i, h, y0, y, y1, x, x0, x1;
	//input
	cout << "enter the value of h , x0, y0 and x1 : ";
	cin >> h >> x0 >> y0 >> x1;
	
 	y = y0;
 	x = x0;
 	//applying euler
	while(1) {
		y1 = y + h * f(x, y);
		x = x + h;
		cout << y1 << endl;
		y = y1;
		if(x >= x1) 
			break;
	}
	//output
	cout << y1;
    cin >> x;
	return 0;
}

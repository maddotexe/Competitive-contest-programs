#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int t;
	
	scanf("%d", &t);
	long double c1x, c1y, c2x, c2y, r1, r2, d, a;
	while (t--) {
		//scanf("%Lf%Lf%Lf%Lf%Lf%Lf", &c1x, &c1y, &c2x, &c2y, &r1, &r2);
		cin >> c1x >> c1y >> c2x >> c2y >> r1 >> r2;
		r2 *= sqrt(2) / 2.0;
		cout << c1x << " " << c1y << " " << c2x << " " << c2y << " ";
		d = sqrt((c2x - c1x) * (c2x - c1x)  +  (c2y - c1y) * (c2y - c1y));
		
		cout << d << endl;
		a = d / 2.0;
		a = a / r1;
		a = acos(a);
		cout << a << endl;
		a = r1 * sin(a);
		
		cout << 2 * a << endl;
	}
	
	return 0;
}
		

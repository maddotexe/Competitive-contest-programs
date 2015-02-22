#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define p 3.14159265358979

int main()
{
	double r, n;
	while (1) {
		cin >> r >> n;
		if (!r && !n) return 0;
		double x = r / sin(p/ (2*n));
		
		printf("%.2f\n", x);
	}
}

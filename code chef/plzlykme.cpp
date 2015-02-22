#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

double fast(double a, int n) {
	if(n == 0) {
		return 1.0;
	}
	
	double c = fast(a, n/2);
	
	if (n & 1) {
		return (c * c) * a;
	} else {
		return c * c;
	}
	
	
	return a;
}

int main()
{
	double l, s, c;
	int t, d;
	
	cin >> t;
	
	while (t--) {
		cin >> l >> d >> s >> c;
		
		
		s = s * fast(1 + c, d - 1);
		if (s < l) cout << "DEAD AND ROTTING\n";
		else cout << "ALIVE AND KICKING\n";
	}
	return 0;
}

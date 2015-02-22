#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else 
		return gcd(b, a % b);
}


int main()
{
	int a, b;
	cin >> a >> b;
	if (a == b) {
		cout << 0 << endl;
		return 0;
	}
	int g = gcd(a, b);
	//cout << g << endl;
	
	a = a / g;
	b = b / g;
	bool f = false;
	int c = 0;
	while (1) {
		if (a % 5 == 0) {
			a /= 5;
			c++;
			continue;
		}
		
		if (a % 3 == 0) {
			a /= 3;
			c++;
			continue;
		}
		
		if (a % 2 == 0) {
			a /= 2;
			c++;
			continue;
		}
		
		break;
	}
	
	while (1) {
		if (b % 5 == 0) {
			b /= 5;
			c++;
			continue;
		}
		
		if (b % 3 == 0) {
			b /= 3;
			c++;
			continue;
		}
		
		if (b % 2 == 0) {
			b /= 2;
			c++;
			continue;
		}
		
		break;
	}
	
	if (a == 1 && b == 1) {
		cout << c << endl;
	} else {
		cout << -1 << endl;
	}
}

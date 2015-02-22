#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
#define m 1000000007
long long int n, l, y, x;
int main()
{
	
	while (1) {
		x = 1;
		y = 0;
		cin >> n >> l;
		if(n == 0 && l == 0) return 0;
		for (int i = 1; i < l + 1; i++) {
			x = (n * x) % m;
			y = (y + x) % m;
		}
		
		cout << y << endl;
	}
}

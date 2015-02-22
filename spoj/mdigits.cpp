#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int r[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};


void no_of_digit(int num, int p, int c[], int f)
{
	int n = num / r[p], i;
	
	for (i = 0; i < n; i++) {
		c[i] += r[p];
	}
	
	c[i] += num % r[p] + 1;
	
	if (f) {
		c[0] -= r[p];
	}
	
	if (p == 0) 
		return ;
		
	for (int i = 0; i < 10; i++) {
		c[i] += n * p * r[p - 1];
	}
	
	if (f) {
		c[0] -= (r[p] - 1) / 9;
	}
	
	no_of_digit(num % r[p], p - 1, c, 0);
}


int main()
{
	int a, b, ac[11], bc[11];
	
	while (1) {
		scanf("%d%d", &a, &b);
		
		if (a == 0 && b == 0) return 0;
		
		if (a > b) {
			int c = a;
			a = b;
			b = c;
		}
		a--;
		for (int i = 0; i < 10; i++) {
			ac[i] = bc[i] = 1;
		}
		
		if (a) {
			int p = (int)floor(log10(a));
			no_of_digit(a, p, ac, 1);
		}
		int p = (int)floor(log10(b));
		no_of_digit(b, p, bc, 1);
		
		cout << bc[0] - ac[0];
		for (int i = 1; i < 10 ; i++) {
			cout << " " << bc[i] - ac[i];
		}
		cout << endl;	
		
	}
	return 0;
}
	

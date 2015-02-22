#include <iostream>
#include <cstdio>

using namespace std;

double a[100001];

void pre()
{
	a[0] = 1.0;
	for (int i = 1; i < 100001; i++) {
		a[i] = a[i - 1] + 1.0 / (double)(i + 1);
	}
}

int main()
{
	pre();
	int n, t;
	
	cin >> t;
	
	while (t--) {
		cin >> n;
		printf("%.6f\n", a[n - 1]);
	}
	
}
		

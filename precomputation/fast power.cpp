#include <iostream>
#include <cstdio>

using namespace std;

#define m 100002013

long long int fast(long long int a, long long int n) {
	if(n == 0) {
		return 1;
	}
	if (n == 1) {
		return a;
	}
	
	long long int c = fast(a, n/2);
	
	a = (c * c) % m;;
	
	if (n & 1) {
		a = (a * 2) % m;
	}
	
	
	return a;
}

int main()
{
	int n ;
	cin >> n;
	
	cout << fast(2, n);
	return 0;
}

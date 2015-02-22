#include <iostream>
#include <cstdio>

using namespace std;

long long a[100100];
void func()
{
	a[0] = 0;
	for (long long i = 1; i <= 100001; i++) {
		a[i] = i * (i - 1) / 2;
	}
}

int main()
{
	func();
	int n, t, x;
	cin >> t;
	
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x;
		}
		
		cout << a[n] << endl;
	}
}

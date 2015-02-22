#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n], b[n];
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = 0;
	}
	bool f = true, f1 = false;
	while (f) {
		f = false;
		if (f1) f1 = false;
		else f1 = true;
		
		for (int i = 0; i < n; i++) {
			if (f1) {
				if (i != 0) {
					cout << "R";
					if (b[i] == a[i]) continue;
					if (b[i] != a[i]) {
						b[i]++;
						cout << "P";
					}
					
				}
				if (b[i] != a[i]) f = true;
			} else {
				if (n - 1 - i != n - 1) {
					cout << "L";
					if (b[n - 1 - i] == a[n - 1 - i]) continue;
					if (b[n - 1 - i] != a[n - 1 - i]) {
						cout << "P";
						b[n - 1 - i]++;
					}
					
				}
				if (b[n - 1 - i] != a[n - 1 - i]) f = true;
			}
		}
	}
}

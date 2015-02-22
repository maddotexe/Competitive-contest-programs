#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n];
	map<int, int> m;
	map<int,int>::iterator it, it1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << -1 << endl;
		return 0;
	}
	sort(a, a+n);
	
	for (int i = 1; i < n; i++) {
		m[a[i]-a[i-1]]++;
	}
	if (m.size() == 1) {
			cout << 1 << endl;
			cout << a[0] << endl;
			return 0;
	}
	if (m.size() > 2) {
		cout << 0 << endl;
		return 0;
	}
	if (n == 2) {
		if (a[0] == a[1]) {
			cout << 1 << endl;
			cout << a[0] << endl;
			return 0;
		} else {
			if ((a[1] - a[0]) % 2 == 0) {
				cout << 3 << endl;
				cout << a[0] - a[1] + a[0] << " " << (a[1]+a[0]) / 2 << " " << a[1] + a[1] - a[0] << endl;
				return 0;
			} else {
				cout << 2 << endl;
				cout << a[0] - a[1] + a[0] << " " << a[1] + a[1] - a[0] << endl;
				return 0;
			}
		}
	}
	it = m.begin();
	it1 = it++;
	int a1 = it->first, x = it1->first , b = it->second, y = it1->second;
	if (x > 1 && y > 1) {
		cout << 0 << endl;
		return 0;
	}
	if (y > 1) {
		int tmp = a1;
		a1 = x;
		x = tmp;
		
		tmp = b;
		b = y;
		y = tmp;
	}
	if (y == b) {
		if (x < a1) {
			int tm = a1;
			a1 = x;
			x = tm;
		} 
	}
	//cout << a1 << endl << b << endl << x << endl << y << endl;
	if ((b > 1 && a1 > x) || (y > 1 && a1 < x)) {
		cout << 0 << endl;
		return 0;
	}
	
	if (it->second <= 1 || it1->second <= 1) {
		
		
		
		if (x / a1 == 2 && a1 != 0) {
			int p = a[0];
			for (int i = 1; p < a[n-1]; i++) {
				p = a[0] + (i) * a1;
				if (p != a[i]) {
					cout << 1 << endl;
					cout << p << endl;
					return 0;
				}
			} 
		} else {
			cout << 0 << endl;
			return 0;	
		}
	} else {
		cout << 0 << endl;
	}
		
}

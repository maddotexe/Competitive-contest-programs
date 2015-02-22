#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, m, x, j = 0, k = 0;
	vector <int> a;
	cin >> n >> m;
	int b[n];
	for (int i = 1; i <= m; i++) {
		cin >> x;
		a.push_back(x);
	}
	
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == -1) {
			if (a[0] > k - j) {
				continue;
			}
			int tmp = lower_bound(a.begin(), a.end(), k - j) - a.begin();
			j += a[tmp];
			cout << tmp << endl;
		} else {
			b[k++] = x;
		}
		cout << j << k << endl;
	}
	
	if (j == k) {
		cout << "Poor stack!\n";
	} else {
		for (int i = j; i < k; i++) {
			cout << b[i];
		}
		cout << endl;
	}
}

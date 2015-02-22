#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	int a[n];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 1) {
			if (m > 0) {
				m--;
			} else {
				ans++;
			}
		} else {
			if (k > 0) {
				k--;
			} else if (m > 0) {
				m--;
			} else {
				ans++;
			}
		}
	}
	cout << ans << endl;
}

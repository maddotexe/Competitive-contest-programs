#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	
	int a[n/k][k];
	
	int c1 = 0, c2 = 0;
	for (int j = 0; j < n / k; j++)
	for (int i = 0; i < k; i++) {
		cin >> a[j][i];
	}
	int ans = 0;
	for (int i = 0; i < k; i++) {
		c1 = 0; c2 = 0;
		for (int j = 0; j < n / k; j++) {
			if (a[j][i] ==  1) c1++;
			else c2++;
		}
		if (c1 >= c2) {
			ans += n / k - c1;
		} else {
			ans += n / k - c2;
		}
	} 
	cout << ans << endl;
}

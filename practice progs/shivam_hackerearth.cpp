#include<bits/stdc++.h>

using namespace std;
#define mem(x,i) memset(x,i,sizeof(x))

int a[1200];

int main()
{
	int i = 1;
	int t, l, r;
	mem(a, 0);
	while (i * i <= 1023) {
		a[i*i] = 1;
		i++;
	}
	for (int i = 1; i < 1022; i++) {
		a[i] += a[i-1];
	}
	
	cin >> t;
	while (t--) {
		if (l > r) {
			cout << 0 << endl;
			continue;
		}
		cin >> l >> r;
		cout << a[r] - a[l-1] << endl;
	}
	return 0;
}



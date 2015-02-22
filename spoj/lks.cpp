#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int v[2000002];

int main()
{
	int w, i, j, k;
	int n;
	
	scanf("%d%d", &w, &n);
	int val[n], wt[n];;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &val[i], &wt[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = w; j >= 0; j--) {
			if (wt[i] + j <= w) {
				v[j + wt[i]] = max(v[j + wt[i]], v[j] + val[i]);
			}
			//cout << v[j] << " ";
		}
	//	cout << endl;
	}
	
	k = v[0];
	for (int i = 0; i <= w; i++) {
	//	cout << v[w -i] << " ";
		if (v[i] > k) {
			k = v[i];
		}
	}
	
	printf("%d\n", k);
	
}
	
	

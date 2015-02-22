#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int w, n, i, j, k, t, p;
	cin >> t;
	while (t--) {
		vector <int> v, v1;
		vector <int> val, wt;
		scanf("%d%d", &n, &w);
		if(!w && !n) return 0;
		for (i = 0; i < n; i++) {
		
			scanf("%d%d%d", &k, &p, &j);
			
			wt.push_back(j);
			val.push_back(k * p);	
		}
		
		v.resize(w + 1);
		v1.resize(w + 1);
		
		for (i = 0; i <= n; i++) {
			for (j = 0; j <= w; j++) {
				if (i == 0 || j == 0) {
					v1[j] = 0;
				} else if (wt[i - 1] <= j) {
					v1[j] = max(val[i - 1] + v[j - wt[i - 1]], v[j]);
				} else {
					v1[j] = v[j];
				}
			}
		
			v = v1;
		}
		k = v[0];
		j = i;
		
		for (i = 0; i <= w; i++) {
			if(v[i] > k) {
				k = v[i];
				j = i;
			}
		}
	
		cout << k << endl;
	}
	return 0;
}
	
	

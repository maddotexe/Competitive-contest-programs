#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define fi first
#define se second

using namespace std;

int main()
{
	int n, k;
	cin >> n;
	vector <pair <long long, int> > v(n+1);
	
	long long a[n], x, sum = 0;
	a[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		v[i].fi = x;
		v[i].se = i;
		a[i] = 0;
	}
	
	sort(++v.begin(), v.end());
	
	cin >> k;
	
	for (int i = 1; i <= k; i++) {
		sum += v[i].fi * (i - 1 - k + i);
		a[i] += v[i].fi + a[i-1]; 
	}
	
	long long ans = sum;
	int pos = k;
	
	for (int i = k + 1; i <= n; i++) {
			a[i] = v[i].fi + a[i-1];
			sum += (k-1)*v[i].fi - 2 *(a[i-1] - a[i-k]) + (k-1)*v[i-k].fi;
			if (sum < ans) {
				sum = ans;
				pos = i;
			}
	}
	vector <int> b;
	for (int i = pos; i > pos - k; i--) {
		b.push_back(v[i].se);
	}
	sort (b.begin(), b.end());
	
	for (int i = 0; i < k; i++) {
		cout << b[i] << " ";
	}
	cout << endl;
}

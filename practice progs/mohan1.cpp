#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

ll a[100010];
set <ll> s;

ll fast(ll n, ll m) {
	if (m == 0) return 1;
	ll d = fast(n, m / 2);
	d = (d * d) % MOD;
	if (m & 1) {
		d = (d * n) % MOD;
	}
	return d;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll sum = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			s.insert(i);
		} else {
			sum *= a[i];
			sum %= MOD;
		}
	}
	
	int q;
	cin >> q;
	ll x, y, ty;
	for (int i = 0; i < q; i++) {
		cin >> ty >> x;
		x--;
		ll d = fast(a[x], MOD - 2);
		if (ty == 0) {
			cin >> y;
			a[x] = y;
			if (y == 0) {
				if (s.find(x) == s.end()) {
					s.insert(x);
					sum *= d;
					sum %= MOD;
				}
			} else {
				if (s.find(x) != s.end()) {
					sum *= y;
					sum %= MOD;
					s.erase(x);
				} else {
					sum = (sum * d) % MOD;
					sum = sum * y;
					sum %= MOD;
				}
			}
		} else {
			if (s.size() > 1) {
				cout << 0 << endl;
			} else if (s.size() == 0) {
				cout << (sum * d) % MOD << endl;
			} else {
				if (s.find(x) != s.end()) {
					cout << sum << endl;
				} else {
					cout << 0 << endl;
				}
			}
		}
	}
	
	
	return 0;
}



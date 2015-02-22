#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <string>
#include <list>
#include <bitset>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <deque>
#include <climits>
#include <cassert>

using namespace std;

#define ull unsigned long long
#define ll long long
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define Sl(x) scanf("%lld",&x)
#define Su(x) scanf("%llu",&x)
#define S(x) scanf("%d",&x)
#define IS(x) cin>>x
#define ISF(x) getline(cin,x)
#define pii pair<ull,ull>
#define pll pair<ll,ll>
#define pps pair<ll,pll>
#define ppf pair<pll,ll>
#define psi pair<string,int>
#define pis pair<int,string>
#define fr first
#define se second
#define MOD 1000000007
#define MP(x,y) make_pair(x,y)
#define eps 1e-7
#define V(x) vector<x>
#define pb(x) push_back(x)
#define mem(x,i) memset(x,i,sizeof(x))
#define fori(i,s,n) for(i=(s);i<(n);i++)
#define ford(i,s,n) for(i=(n);i>=(s);--i)
#define INF 8944674407370955161LL
#define debug(i,st,arr) fori(i,0,st){cout<<arr[i]<<" ";}cout<<endl;
#define forci(i,sw) for((i)=(sw).begin();(i)!=(sw).end();(i)++)
#define forcd(i,sw) for((i)=(sw).rbegin();(i)!=(sw).rend();(i)++)

int abs(int x) {if(x < 0) return -x; return x;}

int main()
{
	ios_base::sync_with_stdio(false);
	ll n, k, t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		ll a[n], c1 = 0, c2 = 0;
		bool f = false;
		cin >> a[0] >> a[1];
		ull h, h1, pos, pos1;
		if (a[0] == 0) {
			f = true;
			c2++;
		}
		if (a[0] == 1) {
			c1++;
		}
		if (a[1] == 0) {
			f = true;
			c2++;
		}
		if (a[1] == 1) {
			c1++;
		}
		if (a[0] > a[1]) {
			h = a[0], h1 = a[1], pos = 0, pos1 = 1;
		} else {
			h1 = a[0], h = a[1], pos1 = 0, pos = 1;
		}
		
		for (int i = 2; i < n; i++) {
			cin >> a[i];
			if (a[i] == 0) {
				f = true;
				c2++;
			}
			if (a[i] == 1) {
				c1++;
			}
			if (a[i] > h) {
				h1 = h;
				h = a[i];
				pos1 = pos;
				pos = i;
			} else if (a[i] >= h1) {
				h1 = a[i];
				pos1 = i;
			}
		}
		if (n == 2 && (h == 0 || h1 == 0)) {
			if (h > k) {
				printf("0\n");
				continue;	
			} else if (h <= k) {
				printf("-1\n");
				continue;
			}
		}
		if (f && c2 > 1 && k > 0) {
			printf("-1\n");
			continue;
		}
		
		if (c1 + c2 == n && k >= 1) {
			printf("-1\n");
			continue;
		}
		
		if (c1 == n && k == 0) {
			printf("0\n");
			continue;
		}
		
		
	
		//cout << pos << " " << pos1 << endl;
		ll c = 0, i = n - 1;
		
		while (a[i] > k && i >= 0) {
			c++;
			i--;
		//	cout << i << endl;
		}
		if (c > 0) {
			//cout << n << " " << c <<endl;;
			if (c == n - 1 || c == n) {
				printf("0\n");
				continue;
			} 
			printf("%ld\n", n - c - 1);	
		} else {
			bool f1 = true;
			while (a[pos] * a[pos1] <= k) {
				c++;
				if (f1) {
					a[pos1] *= a[pos];
					f1 = false;
				} else {
					a[pos] *= a[pos1];
					f1 = true;
				}
			}
			
			if (a[pos] <= k && a[pos1] <= k) {
				c++;
				if (f1) {
					a[pos1] *= a[pos];
					f1 = false;
				} else {
					a[pos] *= a[pos1];
					f1 = true;
				}
			}
			printf("%ld\n", c + n - 2);
		}
	}
	return 0;
}


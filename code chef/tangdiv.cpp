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
#define pii pair<int,int>
#define ppi pair<int, pii>
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

pii a[510], b[510];

int main()
{
	ios_base::sync_with_stdio(false);
	int t, n, k, p;
	cin >> t;
	
	while (t--) {
		cin >> n >> k >> p;
		for (int i = 0; i < k; i++) {
			cin >> a[i].fr >> a[i].se;
		}
		
		for (int i = 0; i < p; i++) {
			cin >> b[i].fr >> b[i].se;
		}
		
		bool f = false;
		int x, y;
		for (int i = 0; i < p; i++) {
			if (b[i].fr > b[i].se) {
				f = true;
				x = b[i].fr;
				break;
			}
		}
		
		if (f) {
			y = n + 1 - x;
			
			for (int i = 0; i < k; i++) {
				if (a[i].fr >= x) {
					a[i].fr = a[i].fr - x + 1;
				} else {
					a[i].fr += y;
				}
				
				if (a[i].se >= x) {
					a[i].se = a[i].se - x + 1;
				} else {
					a[i].se += y;
				}
			}
			
			for (int i = 0; i < p; i++) {
				if (b[i].fr >= x) {
					b[i].fr = b[i].fr - x + 1;
				} else {
					b[i].fr += y;
				}
				if (b[i].se >= x) {
					b[i].se = b[i].se - x + 1;
				} else {
					b[i].se += y;
				}
			}
		}
		
		/*for (int i = 0; i < k; i++) {
			cout << a[i].fr << " " << a[i].se << endl;
		}
		cout << endl;
		for (int i = 0; i < p; i++) {
			cout << b[i].fr << " " << b[i].se << endl;
		}
		*/
		sort(a, a+k);
		sort(b, b+p);
		f = true;
		for (int i = 0, j = 0; i < k; i++) {
			int x = a[i].fr, y = a[i].se;
			int c = b[j].fr, d = b[j].se;
			//cout << x << " " << y << endl;
			bool flag = false;
			if (x > y) {
				f = false;
				break;
			}
			if (x >= c && y >= c && x <= d && y <= d) {
				flag = true;
				continue;
			} else {
				if ((x >= c && x <= d && (y >= d || y <= c)) || (y >= c && y <= d && (x >= d || x <= c))) {
					f = false;
					flag = true;
					break;
				}
			}
			if (!flag) {
				i--;
				j++;
			}
		}
		if (f) cout << "Yes\n";
		else cout << "No\n";
		
	}
	return 0;
}



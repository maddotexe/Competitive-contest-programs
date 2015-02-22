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

double x;
map<double, int> m, m1, m2, m3;
int main()
{
	ios_base::sync_with_stdio(false);
	int t, n;
	freopen("input4l.in", "r", stdin);
	freopen("output4l.out", "w", stdout);
	map<double, int>::iterator it, it1, it2;
	cin >> t;

	for (int cs = 1; cs <= t; cs++) {
		cin >> n;
		m.clear();
		m1.clear();
		m3.clear();
		for (int i = 0; i < n; i++) {
			cin >> x;
			m[x]++;
		}
		for (int j = 0; j < n; j++) {
			cin >> x;
			m3[x]++;
			m1[x]++;
		}
		int c = 0;
		
		for (it = m.begin(); it != m.end(); it++) {
			it1 = m1.upper_bound(it->first);
			if (it1 != m1.end()) {
				m1.erase(it1->first);
			} else {
				m1.erase(m1.begin());
				c++;
			}
		}
		
		int c1 = 0;
		
		for (it = m3.begin(); it != m3.end(); it++) {
			it1 = m.upper_bound(it->first);
			if (it1 != m.end()) {
				m.erase(it1->first);
				c1++;
			} else {
				m.erase(m.begin());
			}
		}
		
		cout << "Case #" << cs << ": " << c1 << " " << c << endl;
		
	}
	return 0;
}



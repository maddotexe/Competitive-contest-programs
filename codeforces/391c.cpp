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

vector <pii> v;

int check(int x)
{
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector <pii> v;
	vector <ppi> v1;
	vector <int> v2;
	int x, y;
	bool sel[101];
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.pb(pii(x, y));
		
		v1.pb(ppi(y, pii(x, i)));
	}
	
	sort(v.rbegin(), v.rend());
	sort(v1.begin(), v1.end());
	
	int minpoints = v[m].fr;
	int ans = 0;
	for (int i = 0; i < minpoints; i++) {
		ans += v1[i].fr;
		v2.pb(v1[i].se.se);
	}
	
	for (int i = 0; i < v.size(); i++) {
		bool f = false;
		if (v[i].fr == minpoints) {
			for (int j = 0; j < v2.size(); j++) {
				if (v2[j] == i) {
					f = true;
					break;
				}
			}
			if (!f) {
				for (int j = 0; j < v2.size(); j++) {
					
				}
			}
		}
	}
	
	
	return 0;
}


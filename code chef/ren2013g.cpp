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

int dis(int x, int y, int x1, int y1) {
	return (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y); 
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, a, b;
	priority_queue <pii , vector<pii> , greater <pii> > pq;
	vector <pii> v;
	cin >> n;
	int dist[n+2];
	
	for (int i = 0; i < n + 2; i++) {
		dist[i] = 99999999;
	}
	v.pb(pii(0, 0));
	dist[0] = 0;
	for (int i = 0; i < n + 1; i++) {
		cin >> a >> b;
		v.pb(pii(a, b));
	}
	
	pq.push(pii(0, 0));
	
	while (!pq.empty()) {
		pii p = pq.top();
		pq.pop();
		int pos = p.second;
		if (pos == n + 1) break;
		
		for (int i = 1; i < n + 2; i++) {
			if (dist[i] > dist[pos] + dis(v[pos].fr, v[pos].se, v[i].fr, v[i].se) && i != pos) {
				dist[i] = dist[pos] + dis(v[pos].fr, v[pos].se, v[i].fr, v[i].se);
				pq.push(pii(dist[i], i));
			}
		}
	}
	cout << dist[n+1] << endl;
	return 0;
}


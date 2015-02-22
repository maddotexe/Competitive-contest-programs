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

pair <int, pii> stud[100001];
pii bug[100001];
int n, m, k;
set <pii> s;
int ans [100001];
ll solve(int d) 
{
	s.clear();
	ll sum = 0;
	int last = 0;
	
	for (int i = 0; i < m; i += d) {
		while (last < n && stud[last].fr >= bug[i].fr) {
			s.insert(stud[last].se);
			last++;
		}
		if (s.size() == 0) return (ll) 1e18;
		
		pii p = *s.begin();
		s.erase(s.begin());
		sum += p.fr;
		
		for (int j = i; j < m && j < i + d; j++) {
			ans[bug[j].se] = p.se;
		}
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		bug[i].se = i;
		cin >> bug[i].fr;
	}
	for (int i = 0; i < n; i++) {
		cin >> stud[i].fr;
	}
	for (int i = 0; i < n; i++) {
		cin >> stud[i].se.fr;
		stud[i].se.se = i;
	}
	
	sort(stud, stud + n);
	sort(bug, bug + m);
	reverse(stud, stud + n);
	reverse(bug, bug + m);
	
	int l = 1, r = m;
	
	while (l <= r) {
		int mid = (l + r) / 2;
		if (solve(mid) <= k) r = mid - 1;
		else l = mid + 1;
	}
	
	if (l > m) {
		cout << "NO\n";
		return 0;
	}
	
	solve(l);
	cout << "YES\n";
	for (int i = 0; i < m; i++) {
		cout << ans[i] + 1 << " ";
	}
	cout << endl;
	return 0;
}


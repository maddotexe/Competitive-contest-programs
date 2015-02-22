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

set<pii>s, s1;

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	set<pii>::iterator it, it1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i*i + j*j == n*n) {
				s.insert(pii(i, j));
				s.insert(pii(-i, j));
				s.insert(pii(i, -j));
				s.insert(pii(-i, -j));
				
			}
		}
	}
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= m; j++) {
			if (i*i + j*j == m*m) {
				s1.insert(pii(i, j));
				s1.insert(pii(-i, j));
				s1.insert(pii(i, -j));
				s1.insert(pii(-i, -j));
				
			}
		}
	}
	
	
	for (it = s.begin(); it != s.end(); it++) {
		for (it1 = s1.begin(); it1 != s1.end(); it1++) {
			if (*it == *it1) continue;
			int x1 = it->fr, y1 = it->se, x2 = it1->fr, y2 = it1->se;
			if (!x1 || !y1 || !x2 || !y2) continue;
			if (x1 == x2 || y1 == y2) continue;
			int g1 = __gcd(abs(x1), abs(y1));
			int g2 = __gcd(abs(x2), abs(y2));
			
			x1 /= g1, y1 /= g1;
			x2 /= g2, y2 /= g2;
			
			if(!((x1 == -y2 && x2 == y1) || (x1 == y2 && y1 == -x2))) continue;
			cout << "YES\n";
			cout << 0 << " " << 0 << endl;
			cout << it->fr << " " << it->se << endl;
			cout << it1->fr << " " << it1->se << endl;
			return 0;	
		}
	}
	cout << "NO\n";
	return 0;
}



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

int main()
{
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	
	int a[s.size()+1][3];
	int m, x, y;
	for (int i = 1; i <= s.size(); i++) {
		a[i][0] = a[i-1][0] + (s[i-1] == 'x');
		a[i][1] = a[i-1][1] + (s[i-1] == 'y');
		a[i][2] = a[i-1][2] + (s[i-1] == 'z');
	}
	
	cin >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		x--;
		
		int g = a[y][0] - a[x][0], h = a[y][1] - a[x][1], k = a[y][2] - a[x][2];
		if (y - x <= 2) 
			cout << "YES\n";
		else {
			if (max(h, max(g, k)) - min(g, min(h, k)) > 1) 
				cout << "NO\n";
			else 
				cout << "YES\n";
		}
	}
	return 0;
}


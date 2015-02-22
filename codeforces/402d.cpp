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

int n, m, x, c, beauty, temp;
int a[5002], g[5002];
map <int, int> m1;

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i < m; i++) {
		cin >> x;
		m1[x] = 1;
	}
	g[1] = a[1];
	x = a[1];
	for (int i = 2; i <= n; i++) {
		x = __gcd(x, a[i]);
		g[i] = x;
	}
	for (int i = n; i >= 1; i--) {
		beauty = 0;
		x = g[i];
		
		for (int j = 2; j * j <= x; j++) {
			if (x % j == 0) {
				if (m1[j]) c = 1;
				else c = -1;
				
				while (x % j == 0) {
					beauty += c;
					x /= j;
				}
			}
			
		}
		if (x > 1) {
			if (m1[x]) beauty++;
			else beauty--;
		}
		if (beauty > 0) {
			for (int j = 1; j <= i; j++) {
				a[j] /= g[i];
				g[j] /= g[i];
			}
		}
	}
	
	beauty = 0;
	
	for (int i = n; i >= 1; i--) {
		temp = 0;
		x = a[i];
		
		for (int j = 2; j * j <= x; j++) {
			if (x % j == 0) {
				if (m1[j]) c = -1;
				else c = 1;
				
				while (x % j == 0) {
					temp += c;
					x /= j;
				}
			}
		}
		if (x > 1) {
			if (m1[x]) temp--;
			else temp++;
		}
		
		beauty += temp;
	}

	cout << beauty << endl;
	return 0;
}



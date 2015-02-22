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
	int a, b, c, d;
	int e, f, g, h;
	int r = 0;
	for (int i = 0; i < 6; i++) {
		if (e == 1 && f == 1 && g == 1 && h == 1) {
			r = 1;
			break;
		}
		cout << i + 1 << " " << i + 1 << " " << i + 1 << " " << i + 1 << endl;
		fflush(stdout);
		cin >> e >> f >> g >> h;
		if (e == 1) {
			a = i + 1;
		} 
		if (f == 1) {
			b = i + 1;
		} 
		if (g == 1) {
			c = i + 1;
		} 
		if (h == 1) {
			d = i + 1;
		} 
	}
	if (!r)
	cout << a << " " << b << " " << c << " " << d << endl;
	fflush(stdout);
        return 0;
}


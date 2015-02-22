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
	int n;
	cin >> n;
	
	int a[n];
	int t = 0, c, x;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x < 0) a[t++] = x;
	}
	cin >> c;
	if (t == 0 || c == 0) {
		cout << 0 << endl;
		return 0;
	} else if (t < c) {
		ll k = 0;
		for (int i = 0; i < t; i++) {
			 k += (0 - a[i]);
		}
		cout << k << endl;
		return 0;
	}
	
	sort(a, a+t);
	ll h , sum = 0;
	h = (0 - a[c - 1]);
	sum = h * c;
	for (int i = 0; i < c - 1; i++) {
		sum += (0 - a[i] - h);
	}
	
	cout << sum << endl;
	
        return 0;
}


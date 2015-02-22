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

double p[100];
int a[100], b[100];
bool c[100];

double ans;

double func(int n, int s, int curr)
{
	if (curr == n) return 1.0;
	double sum = 0.0;
	bool bb = true;
	
	if (!c[a[curr]]) {
		c[a[curr]] = true;
		sum += func(n, s+1, curr+1) * p[curr];
		c[a[curr]] = false;                                                                                        
	}
	if (!c[b[curr]]) {
		c[b[curr]] = true;
		sum += func(n, s+1, curr+1) * (1.0 - p[curr]);
		c[b[curr]] = false;
	}
	
	return sum;
}


int main()
{
	int t, n;
	cin >> t;
	int x;
	
	while (t--) {
		cin >> n;
		ans = 0.0;
		for (int i = 0; i < n; i++) {
			cin >> x >> a[i] >> b[i];
			c[i] = false;
			p[i] = (double)x / 100.0;
		}
		
		if (n > 16) {
			cout << "0.00000000\n";
			continue;
		}
		printf("%.7lf\n", func(n, 0, 0));
	}
		
        return 0;
}


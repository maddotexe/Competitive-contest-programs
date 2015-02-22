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
	int a[1<<10];
	char s[22];
	cin >> n;
	memset(a, 0, sizeof(a));
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		
		int l = strlen(s);
		int mask = 0;
		for (int i = 0; i < l; i++) {
			mask |= (1 << (s[i] - '0'));
		}
		
		a[mask]++;
	}
	long long int m = 0;
	for (int i = 0; i < (1 << 10); i++) {
		for (int j = 0; j < (1 << 10); j++) {
			if (i != j && (i & j)) {
				m += (long long int) a[i] * a[j];
			}
		}
	}
	
	for (int i = 0; i < (1 << 10); i++) {
		m += (a[i] * (a[i] - 1));
	}
	cout << m / 2 << endl;
	
	return 0;
}


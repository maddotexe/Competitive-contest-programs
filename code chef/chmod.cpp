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

long long int fast(long long int a, int n, int m) {
	if (n == 1) {return a;}
	else if ( n == 0 )  return 1;
	else {
		long long int d = fast(a, n / 2, m);
		d = (d* d)% m;
		
		if (n &1 ) {
			d = (d * a) % m;
		}
		
		return d;
	}
	
}

int main()
{
	
	int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
	
	int n, t, x, q, a, b, m;
	scanf("%d", &n);
	vector <vector <int> > vv;
	vector <int> v(27);
	vv.push_back(v);
	for (int i = 0; i < n; i++) {
		cin >> x;
		int k = 0;
		while (x != 1) {
			if (x % prime[k] == 0) {
				v[k]++;
				x /= prime[k];
			} else {
				k++;
			}
		}
		vv.push_back(v);
	}
	
	cin >> q;
	long long int ans = 1;
	for (int j = 0; j < q; j++) {
		scanf("%d%d%d", &a, &b ,&m);
		ans = 1;
		for (int i = 0; i < 25; i++) {
			long long int y = fast(prime[i], vv[b][i] - vv[a-1][i], m);
			
			ans = (ans * y) % m;
		}
		printf("%d\n", ans);
	}



	return 0;
}


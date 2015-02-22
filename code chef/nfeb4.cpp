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

int n, c[100001];
int a[1000000];

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	
	cin >> t;
	
	while (t--) {
		mem(c, -1);
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			c[a[i]] = i;
		}
		
		vector <int> v;
		int curr = -1;
		for (int i = 100000; i > 0; i--) {
			if (c[i] != -1) {
				if (c[i] > curr) {
					v.pb(c[i]);
					curr = c[i];
				}
			}
		}
		curr = 0;
		int ans = 0, mul = 0;
		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			sum = mul = 0;
			if (i == 0) {
				mul = v[i];
			} else {
				mul = v[i] - v[i-1] - 1;
			}
			for (int j = curr; j < v[i]; j++) {
				sum += a[j];
			}
			//cout << mul << v[i] << endl;
			ans += mul * a[v[i]] - sum;
			curr = v[i] + 1;
		}
		cout << ans << endl;
	}
	return 0;
}


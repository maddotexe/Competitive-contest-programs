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
	int n, m;
	
	cin >> n >> m;
	vector <int> v(100001);
	if (m & 1) {
		int k = (m + 1) / 2;
		v[1] = k;
		for (int i = 1, j = 2; i <= m/ 2; i++, j+=2) {
			//cout << i + k << " " << k - i << endl;
			if ((i + k <= m) && (k - i > 0)) {
			//	cout << 99999999999<<endl;
				if (i == 0) {
					v[i] = i + k;
				} else {
					v[j] = k - i;
					v[j+1] = i + k;
				}
			}
		}
	} else {
		int k = m / 2;
		for (int i = 0, j = 1; i <= m / 2; i++, j += 2) {
			if (i + k + 1 <= m && k - i > 0) {
				if (i == 0) {
					v[j] = m / 2;
					v[j+1] = m / 2 + 1;
				} else {
					v[j] = k - i;
					v[j+1] = i + 1 +k;
				}
			}
		} 
	}
	for (int i = 0; i < n; i++) {
		cout << v[i % m + 1] << endl;
	}
	return 0;
}


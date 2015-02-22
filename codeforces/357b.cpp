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
#define ln length()
#define MP(x,y) make_pair(x,y)
#define eps 1e-7
#define vi(x) vector<x>
#define pb(x) push_back(x)
#define mem(x,i) memset(x,i,sizeof(x))
#define fori(i,s,n) for(i=(s);i<(n);i++)
#define ford(i,s,n) for(i=(n);i>=(s);--i)
#define debug(i,st,arr) fori(i,0,st){cout<<arr[i]<<" ";}cout<<endl;
#define forci(i,sw) for((i)=(sw).begin();(i)!=(sw).end();(i)++)
#define forcd(i,sw) for((i)=(sw).rbegin();(i)!=(sw).rend();(i)++)
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<ll>::max()
#define lmin numeric_limits<ll>::min()
#define MOD 1000000007
#define INF 8944674407370955161LL

template <typename T>
T abs(T x) {if(x < 0) return -x; return x;}
template <typename T>
T gcd(T a,T b){return b?gcd(b,a%b):a;}

int main()
{
	int n, x, y, z, m;
	cin >> n >> m;
	int a[n];
	memset(a, 0, sizeof(a));
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		x--;
		y--;
		z--;
		if (a[x] == 0 && a[y] == 0 && a[z] == 0) {
			a[x] = 1; a[y] = 2; a[z]= 3;
		} else if (a[x] && a[z] && a[y]) {
		} else if (a[x] && a[y]) {
			for (int k = 1; k <= 3; k++) {
				if (a[x] != k && a[y] != k) {
					a[z] = k;
					break;
				}
			}
		} else if (a[x] && a[z]) {
			for (int k = 1; k <= 3; k++) {
				if (a[x] != k && a[z] != k) {
					a[y] = k;
					break;
				}
			}
		} else if (a[z] && a[y]) {
			for (int k = 1; k <= 3; k++) {
				if (a[z] != k && a[y] != k) {
					a[x] = k;
					break;
				}
			}
		} else if (a[x]) {
			bool f = false;
			for (int k = 1; k <= 3; k++) {
				if (a[x] != k) {
					if (f) {
						a[z] = k;
					} else {
						a[y] = k;
						f = true;
					}
				}
			}
		} else if (a[y]) {
			bool f = false;
			for (int k = 1; k <= 3; k++) {
				if (a[y] != k) {
					if (f) {
						a[z] = k;
					} else {
						a[x] = k;
						f = true;
					}
				}
			}
		} else if (a[z]) {
			bool f = false;
			for (int k = 1; k <= 3; k++) {
				if (a[z] != k) {
					if (f) {
						a[x] = k;
					} else {
						a[y] = k;
						f = true;
					}
				}
			}
		}
		
	}
	for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
        return 0;
}


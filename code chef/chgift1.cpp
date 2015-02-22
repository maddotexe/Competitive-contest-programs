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
#define ff first
#define ss second
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

int abs(int x) {if(x < 0) return -x; return x;}

int main()
{
	int t, n, x;
	int sum;
	
	cin >> t;
	
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			if(i == 0) cin >> sum;
			else {
				cin >> x;
				
				if (sum == -1) {
					if (x < 0) sum += x;
					else sum -= x;
				} else if (sum == 1) {
					if (x < 0) sum += x;
					else sum -= x;
				} else if (x == 1) {
					sum -= x;
				} else if (x == -1) {
					sum += x;
				} else {
				
					if (x < 0) {
						if (sum <= 0) {
							sum += x;
						} else {
							sum *= x;
						}
					} else if (x > 0) {
						if(sum < 0) sum*= x;
						else sum -= x;
					}
				}
			}
		}
		cout << sum << endl;
	}
        return 0;
}


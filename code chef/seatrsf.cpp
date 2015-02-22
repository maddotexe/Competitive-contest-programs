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

using namespace std;
 
long long pow(long long n, long long m)
{
        if(m == 0) return 1;
        if(m == 1) return n;
        ll d = pow(n, m / 2);
        d = (d * d) % MOD;
        if (m & 1) {
        	d = (d * n) % MOD;
        }
        return d;
}
 
int main()
{
    long long t;
 
    cin >> t;
 
    while(t--) {
        long long n, m, r, k;
        cin >> n >> m >> r >> k;
        if(m - r <= 0) {
            cout << 0 << endl;
            continue;
        }
        if(n == 1 && r == 0) {
            cout << m << endl;
            continue;
        }
        else if(n == 1) {
            cout << 0 << endl;
            continue;
        }
        long long ans = ((m - r) * ((pow(r + 1, n) + pow(r - 1, n) + MOD + MOD - 2 * pow(r, n) )))%MOD;
        if(ans < 0) ans += MOD;
        cout << ans << endl;
    }
    return 0;
}

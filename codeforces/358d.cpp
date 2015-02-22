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

int n;
int a[3004], b[3004], c[3004], dp[3004][2];

int solve(int pos, int f) 
{
    if (pos == n) {
        if(f) return b[pos];
        else return a[pos];
    }
    int ans = 0;
    if (dp[pos][f] != -1) return dp[pos][f];
    
    if (f == 0) {
        ans = max(ans, a[pos] + solve(pos + 1, 1));
        ans = max(ans, b[pos] + solve(pos + 1, 0));
    } else {
        ans = max (ans, b[pos] + solve(pos+1, 1));
        ans = max (ans, c[pos] + solve(pos+1, 0));
    }
    return dp[pos][f] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    //a[i] = b[i] = c[i] = a[n+1] = b[n+1] = c[n+1] = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; 
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i]; 
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> c[i]; 
    }
    mem(dp, -1);
    cout << solve(1, 0);
    
    return 0;
}

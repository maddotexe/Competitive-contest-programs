#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define FD(i,a,n) for(int i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%llu",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

/* Relevant code begins here */

/* Input from file or online */

void input() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
#endif
}

/* Input opener ends */

int a[1123], n;
#define MOD 1000000007
ill dp[1005][10005][2];
ill f(int idx,int sum, bool pos) {
	cout << sum << endl;
    if ( idx == n ) return (sum==0);
    ill &res = dp[idx][sum][pos];
    if  ( res != -1 ) return res;
    res = (sum==0);
    if ( !pos ) sum=-sum;
    int sumadd = sum+a[idx];
    if ( sumadd < 0 ) res += f(idx+1,sumadd,0);
    else res += f(idx+1,sumadd,1);
    int sumsub = sum-a[idx];
    if ( sumsub < 0 ) res += f(idx+1,sumsub,0);
    else res += f(idx+1,sumsub,1);
    res = res%MOD;
    return res;
}

int main() {
    M(dp,-1); S(n);
    F(i,0,n) {
        S(a[i]);
    }
    ill ans = 0;
    F(i,0,n) {
        ans += f(i+1,a[i],1);
        ans += f(i+1,a[i],0);
        ans %= MOD;
    }
    for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			cout << dp[i][j][0] << " " << dp[i][j][1]<< endl;
		}
	}
    printf("%lld\n", ans);
    return 0;
}

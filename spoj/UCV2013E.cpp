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

long long int fact1[501];

long long int fast(long long int a, long long int n) {
	if (n == 0) return 1;
	else if (n == 1) return a;
	long long int b = fast(a, n / 2);
	
	b = (b * b) % MOD;
	
	if (n & 1) {
		b = (b * a) % MOD;
	}
	
	return b;
}

void fact()
{
	fact1[0] = 1;
	
	for (int i = 1; i < 501; i++) {
		fact1[i] = (fact1[i-1] * i) % MOD;
	}
}

int main()
{
    fact();	
    int n;
    long long int a[501], b[501];
    
    while (1) {
    	scanf("%d", &n);
    	
    	if (n == 0) return 0;
    	
    	for (int i = 0; i < n; i++) {
    		scanf("%lld", &a[i]);
    	}
    	
    	for (int i = 0; i < n; i++) {
    		scanf("%lld", &b[i]);
    	}
    	long long int sum = 0;
    	long long int v = 1, val;
    	for (int i = 0; i < n; i++) {
    		sum += b[i] - a[i];
    		
    		val = fast(fact1[b[i] - a[i]], MOD - 2);
    		
    		v = (v * val) % MOD;
    	}
    	
    	sum = fact1[sum];
    	
    	printf("%lld\n", (sum * v) % MOD);
    }
    
    return 0;
}


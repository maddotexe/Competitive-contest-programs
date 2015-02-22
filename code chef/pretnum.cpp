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

bool pri[1000010];
ll p[800000];
int lim = 0;

bool temp[1000010];

vector <ll> po;

void sieve()
{
	pri[0] = true;
	pri[1] = true;
	
	for (int i = 2; i <= 1001; i++) {
		if (pri[i] == false) {
			for (int j = i * i; j <= 1000001; j += i) {
				pri[j] = true;
			}
		}
	}
	
	for (int i = 0; i < 1000001; i++) {
		if (pri[i] == false) {
			p[lim++] = (ll)(i);
		}
	}
}

int segmented_sieve(ll a, ll b)
{
	int c; 
	if (a <= 2 && 2 <= b)
		c = 1;
	else c = 0;
	
	if(b < 2) return 0;
	if(a < 3) a = 3;
	
    	if(!(a&1)) a++;
    	if(!(b&1)) b--;
    	
    	if(b < a) return 0;
    	
    	mem(temp, 0);
    	for (int i = 0; i < lim && p[i] * p[i] <= b; i++) {
    		ll j = p[i] * ((a + p[i] - 1) / p[i]);
    		if (j % 2 == 0) {
    			j += p[i];
    		}
    		
    		for (int k = p[i] * 2; j <= b; j += k) {
    			if (j != p[i]) {
    				temp[j-a] = 1;
    			}
    		}
    	}
    	
    	for (int i = 0; i <= (b - a); i += 2) {
    		if (temp[i] == 0) c++;
    	}
    	return c;
    	
}

void powers() {
	for (int i = 0; i < lim; i++) {
		int j = 1;
		ll res = 1;
		while (j) {
			res *= p[i];
			if (res < 1000001000100) {
				if (!pri[j+1]) po.push_back(res);
			} else if (res > 1000000000100){
				break;
			}
			j++;	
		}	
	}
	sort(po.begin(), po.end());
}

int main()
{
	sieve();
	powers();
	
	ll a, b, d;
	int ans;
	int t;
	
	vector <ll>:: iterator it;
	cin >> t;
	while (t--) {
		scanf("%lld%lld", &a, &b);
		ans = 0;
		it = find(po.begin(), po.end(), b);
		d = b;
		if (it == po.end()) d--;
		ans = upper_bound(po.begin(), po.end(), d) - lower_bound(po.begin(), po.end(), a);
		//cout << ans << endl;
		if (b > 1000000) {
			ans += segmented_sieve(max(a, 1000001LL), b);
		}
		cout << ans << endl;
		
	}
	//cout << segmented_sieve(10000000000, 10001000000);
        return 0;
}


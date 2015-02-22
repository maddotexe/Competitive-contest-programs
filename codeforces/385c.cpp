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
#define ma 10000000
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


int a[10000010], b[1000010];
int c[10000010];

vector <int> pri;
bool cc[10000010];

void sieve()
{
	cc[0] = cc[1] = true;
	
	for (int i = 2; i <= 3163; i++) {
		if (!cc[i])
		for (int j = i * i; j < 10000005; j += i) {
			cc[j] = true;
		}
	}
	for (int i = 2; i < 10000005; i++) {
		if (!cc[i]) pri.pb(i);
	}
}
int main()
{
	sieve();
	
	ios_base::sync_with_stdio(false);
	int n, mm, x, l , r;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		b[i] = x;
		a[x]++;
	}
    
	for (int i = 0; i < n; i++) {
		if (a[b[i]] != 0) {
			int x = b[i];
			
			for (int pos = 0; pri[pos] * pri[pos] <= x && pos < pri.size(); pos++) {
				if (x % pri[pos] == 0) {
					c[pri[pos]] += a[b[i]];
					while (x % pri[pos] == 0) x /= pri[pos];
				}
			}
			if (x != 1) {
				c[x] += a[b[i]];
			}
			a[b[i]] = 0;
		}
	}
	
	for (int i = 1; i < 10000003; i++) {
		c[i] += c[i-1];
	}
    
	cin >> mm;
	
	for (int i = 0; i < mm; i++) {
		cin >> l >> r;
		if (l > 10000000) {
			cout << 0 << endl;
			continue;
		}
		if (r > 10000000) {
			r = 10000000;
		}
		cout << c[r] - c[l-1] << endl;
	}
    
    

}

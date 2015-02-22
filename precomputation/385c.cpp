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

bool pri[10000010];

void sieve()
{
	memset(pri, 0, sizeof(pri));
	pri[0] = 1;
	pri[1] = 1;
	for (int i = 2; i < 3164; i++) {
		if (pri[i] == 0)
		for (int j = i * i; j < 10000009; j = j + i) {
			pri[j] = 1;
		}
	}
	
}

int main()
{
	//sieve();
	ios_base::sync_with_stdio(false);
	int n, mm,x, l , r;
	map<int, int> m;
	m[1] = 0;
	map<int, int>::iterator it, it1, it2;
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x % 2 == 0) {
			m[2]++;
			while (x % 2 == 0) x /= 2;
		}
		for (int i = 3; (i * i <= x); i += 2) {
			if (x % i == 0) {
				m[i]++;
				while (x % i == 0) x /= i;
			}
		} 
		if (x > 1) {
			m[x]++;
		}
	}
	
	cin >> mm;
	
	it1 = m.begin();
	it = it1;
	for (it++; it != m.end(); it++, it1++) {
		it->second += it1->second;
		it2 = it;
	}
	
	while (mm--) {
		cin >> l >> r;
		if (r >= it2->first) {
			it1 = it2;
		} else {
			it1 = m.lower_bound(r+1);
			it1--;
		}
		if (l > it2->first) {
			cout << 0 << endl;
			continue;
		} else {
			it = m.upper_bound(l - 1);
			it--;
		}
		printf("%d\n", it1->second - it->second);
	}
}

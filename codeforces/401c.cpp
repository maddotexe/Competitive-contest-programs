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
#define ppi pair<int, pii>
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
	if (n - m > 1 || m > (2 * (n + 1))) {
		cout << -1 << endl;
		return 0;
	}
	if (n >= m) {
		bool f = true;
		while (n != 0 && m != 0) {
			if (f) {
				n--;
				cout << 0;
			} else {
				m--;
				cout << 1;
			}
			f = !f;
		}
		
		if (n != 0) {
			cout << 0 << endl;
		} else if (m != 0) {
			cout << 1 << endl;
		} else {
			cout << endl;
		}
		return 0;
	}
	
	int x = 2 * (n + 1) - m;
	int a = n, b = m;
	for (int i = 0; i < n + 1 - x; i++) {
		if (i == 0) {
			cout << "11";;
			b -=2;
		} else {
			cout << "011";
			b -=2;
			a--;
		}
	} 
	bool f = true;
	while (a != 0 && b != 0) {
		
		if (f) {
			cout << "0";
			a--;
		} else {
			cout << 1;
			b--;
		}
		f = !f;
	}
	n = a, m = b;
	if (n != 0) {
		cout << 0 << endl;
	} else if (m != 0) {
		for (int i = 0; i < m; i++) {
			cout << 1;
		}
		cout << endl;
	} else {
		cout << endl;
	}
	return 0;
}



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

int main()
{
	ios_base::sync_with_stdio(false);
	ll n, pos, pos1;
	cin >> n;
	ll sum = n;
	ll a = n;
	if (n == 1) {
		cout << "2\nNY\n" << "YN\n";
		return 0;
	}
	for (ll i = 2; i * i <= a; i++) {
		if (a % i== 0) {
			if ((i + (a / i)) <= sum) {
				pos = i;
				pos1 = a / i;
				sum = min(sum, (i + a / i));
			}
			a = a / i;
		}
	}
	
	bool cc[sum+2][sum+2];
	
	if (a > 0) {
		cout << sum + 2 << endl;
		cc[0][0] = cc[0][1] = cc[1][0]= cc[1][1] = 0;
		for (int i = 2; i < a + 2; i++) {
			cc[0][i] = cc[i][0] = 1;
		}
		for (int i = 2; i < a + 2; i++) {
			cc[1][i] = cc[i][1] = 1;
		}
		for (int i = 0; i < sum + 2; i++) {
			for (int j = 0; j < sum + 2; j++) {
				if (cc[i][j]) cout << "Y";
				else cout << "N";
			}
			cout << endl;
		}
		return 0;
	}
	cc[0][0] = cc[0][1] = cc[1][0]= cc[1][1] = 0;
	for (int i = 2; i < pos + 2; i++) {
		cc[0][i] = 1;
	}
	for (int i = pos + 2; i < sum + 2; i++) {
		cc[0][i] = 0;
	}
	for (int i = 2; i < pos + 2; i++) {
		cc[1][i] = 0;
	}
	for (int i = pos + 2; i < sum + 2; i++) {
		cc[1][i] = 1;
	}
	
	for (int i = 2; i < pos + 2; i++) {
		for (int j = 0; j < sum + 2; j++) {
			if (j == 0) {
				cc[i][j] = 1;
			} else if (j == 1) {
				cc[i][j] = 0;
			} else if (j < pos + 2) {
				cc[i][j] = 0;
			} else {
				cc[i][j] = 1;
			}
		}
	}
	
	for (int i = pos + 2; i < sum + 2; i++) {
		for (int j = 0; j < sum + 2; j++) {
			if (j == 1) {
				cc[i][j] = 1;
			} else if (j == 0) {
				cc[i][j] = 0;
			} else if (j < pos + 2) {
				cc[i][j] = 1;
			} else {
				cc[i][j] = 0;
			}
		}
	}
	cout << sum + 2 << endl;
	for (int i = 0; i < sum + 2; i++) {
		for (int j = 0; j < sum + 2; j++) {
			if (cc[i][j]) cout << "Y";
			else cout << "N";
		}
		cout << endl;
	}
	return 0;
}


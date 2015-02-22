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
	int n, m;
	cin >> n >> m;
	
	string s[n];
	
	for (int i = 0; i < n; i++) cin >> s[i];
	bool flag = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'B') {
				for (int k = 0; k < n; k++) {
					for (int l = 0; l < m; l++) {
						if (i == k && j == l) continue;
						bool f, f1;
						if (s[k][l] == 'B') {
							f = f1 = true;
							//cout << "k = " << k << " l = " << l << endl;
							if (i == k) {
								for (int x = min(j, l); x <= max(j, l); x++) {
									if (s[i][x] != 'B') {
										//cout << x << " " ;
										f1 = f = false;
										break;
									}
								}
							} else if (j == l) {
								for (int x = min(i, k); x <= max(i, k); x++) {
									if (s[x][j] != 'B') {
										//cout << x << " ";
										f = f1 = false;
										break;
									}
								}
							} else {
								for (int x = min(i, k); x <= max(i, k); x++) {
									if (s[x][j] != 'B') {
										//cout << x << " ";
										f = false;
										break;
									}
								}
								//cout << "     ";
								for (int x = min(j, l); x <= max(j, l); x++) {
									if (s[i][x] != 'B') {
										//cout << x << " ";
										f1 = false;
										break;
									}
								}
							}
							//cout << endl << endl;
							if (!f1 && !f) {
								//cout << i << " " << j << " " << k << " " << l << endl;
								flag = false;
								cout << "NO\n";
								return 0;
							}
						}	
					}
				}
			}
		}
	}
	
	if (flag) cout << "YES\n";
	return 0;
}


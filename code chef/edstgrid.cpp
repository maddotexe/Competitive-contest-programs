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
#define ff first
#define ss second
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

int abs(int x) {if(x < 0) return -x; return x;}

char c;
char a[101][101];
int n, m;
string s[1000001];

string its(int x) {
	string s = "";
	while (x != 0) {
		s = char((x % 10) + '0') + s;
		x /= 10; 
	}
	return s;
}

int main()
{
	int t, c1, c2, cost, pos, pos1;
	cin >> t;
	
	while (t--) {
		
		int w = 0, b = 0;
		cin >> n >> m >> c1 >> c2;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				if(a[i][j] == 'W') w++;
				else b++;
			}
		}
		if(b == 0 || w == 0) {
			cout << 0 << endl;
			continue;
		}
		if (b > w) {
			c = 'W';
			pos = 2;
			pos1 = 3;
			cost = c2;
		} else {
			c = 'B';
			pos = 3;
			pos1 = 2;
			cost = c1;
		}
		string d;
		char x;
		int val = 0;
		for (int i = 0; i < n; i++) {
			int k = 0;
			for (int j = 0; j < m; j++) {
				if (a[i][j] == c) {
					if(j == 0 || a[i][j-1] == c) {
						k++;
						continue;
					} else {
						if (j - k >= cost) {
							d = its(pos) + " " + its(i + 1) + " " + its(j + 1);
							if(c == 'W') a[i][j] = 'B';
							else a[i][j] = 'W';
							s[val++] = d;
						} else {
							int h = j;
							while (h != 0 && a[i][h-1] != c) {
								x = a[i][h];
								a[i][h] = a[i][h-1];
								a[i][h-1] = x;
								d = "1 " + its(i + 1) + " " + its(h) + " " + its(i + 1) + " " + its(h + 1);
								s[val++] = d;
								h--;
							}
						}
					}
				}
			}
		}
		int b1 = 0, w1 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 'B') b1++;
				else w1++;
			}
		}
		if (b1 != 0 && w1 != 0) {
			for (int i = 0; i < n; i++) {
				int l = 0;
				for (int j = 0; j < m; j++) {
					if(a[i][j] == c) {
						l++;
					}
				}
				if(l == 0) {
					a[i][0] = c;
					d = its(pos1) + " " + its(i + 1) + " " + its(1);
					s[val++] = d;
				}
			}
		}
		
		cout << val << endl;
		
		for (int i = 0; i < val; i++) {
			cout << s[i] << endl;
		}
		/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << a[i][j];

			}
			cout << endl;
		}*/
	}
        return 0;
}


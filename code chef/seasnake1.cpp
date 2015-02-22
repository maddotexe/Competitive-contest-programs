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
#define PB(x) push_back(x)
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
int mx = 0, px = 1, my = 2, py = 3;
int a[1000000];
int pos = 0;
int main()
{
	int n, m, x1, y1, x2, y2, x, y;
	cin >> n >> m;
	int i = 0; 
	int j = 1;
	bool swtch, f;
	int val = 0;
	int sx = 0, sy1 = 1, sy2 = m - 2;
	
	swtch = false;
	bool change = false;
	if (n % 2 == 1 && n != 1) {
		int tmp = n;
		n = m;
		m = tmp;
		change = true;
		py = 1;
		my = 0;
		px  = 3;
		sy1 = m - 1;
		swtch = true;
		sy2 = n - 2;
	}
	if (n == 1) {
		int sum = 0;
		int val = 0;
		for (int i = 0; i < m * n - 1; i++) {
			cin >> x >> y;
			if (y < val) {
				sum += m - val + y;
			} else {
				sum += y - val;
			}
			val = y;
		}
		cout << sum << endl;
		
		for (int i = 0; i < sum; i++) {
			printf("%d ", 3);
		}
		cout << endl;
	} else {
		for (int k = 0; k < m * n - 1; k++) {
			
			cin >> x >> y;
			if (change) {
				x = m - 1 - x;
				y = n - 1 - y;
			}
			f = false;
			for (i = sx; i < n; i++) {
				if (swtch && j == m - 1){
				
				//	cout << i << " outer1 " << j << endl;
					a[pos++] = px;
					if (i == x && j == y) {
						sx = i;
						sy2 = --j;
					/*	cout << a[0];
						for (int g = 1; g < pos; g++) {
							printf(" %d", a[g]);
						}
						cout << endl;*/
						break;
					}
				} else if (!swtch && j == 0) {
				//	cout << i << " outer2 " << j << endl;
					a[pos++] = px;
					if (i == x && j == y) {
						sx = i;
						sy1 = ++j;
				/*		cout << a[0];
						for (int g = 1; g < pos; g++) {
							printf(" %d", a[g]);
						}
						cout << endl;*/
						break;
					}
				}
				
				if (!swtch) {
					for (j = sy1; j < m; j++) {
					//	cout << i << " inner1 " << j << endl;
						a[pos++] = py;
						if (i == x && j == y) {
							f = true;
							sx = i;
							sy1 = j + 1;
				/*			cout << a[0];
							for (int g = 1; g < pos; g++) {
							printf(" %d", a[g]);
						}
						cout << endl;*/
							break;
						}
					}
					sy2 = m - 2;
					j = m - 1;
				} else {
					for (j = sy2; j >= 0; j--) {
				//		cout << i << " inner2 " << j << endl;
						a[pos++] = my;
						if (i == x && j == y) {
							f = true;
							sx = i;
							sy2 = j - 1;
				/*			cout << a[0];
							for (int g = 1; g < pos; g++) {
							printf(" %d", a[g]);
						}
						cout << endl;*/
							break;
						}
					}
					sy1 = 1;
					j = 0;
				}
				
				if (f) break;
				if (swtch) {
					swtch = false;
					if (i == n - 1 && j == 0) {
						i = -1;
					}
				} else {
					swtch = true;
					if (j == m - 1 && i == n - 1) {
						i = -1;
					}
				}
				
			}
		}
		cout << pos << endl;
		cout << a[0];
		for (int g = 1; g < pos; g++) {
			printf(" %d", a[g]);
		}
		cout << endl;
	}
	
        return 0;
}


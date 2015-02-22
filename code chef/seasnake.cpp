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


	
int a[1000000];
int main()
{
	int n, m, x1, y1, x2, y2;
	cin >> n >> m;
	int x = 0, y = 0, pos = 0, j = 0, k = 0;
	for (int i = 0; i < (n * m) - 1; i++) {
		cin >> x1 >> y1;
		
		bool f = false;
		
		while (1) {
			if (j % n == x1 && k % m == y1) {
				break;
			}
			
			if (j & 1) {
				while (1) {
					k++;
					a[pos++] = 2;
					if ((m - (k % m) - 2) == y1 && j % n == x1) {
						f = true;
						break;
					}
						
					if ((m - (k % m)  - 2) == 0) {
						k += 2;
						break;
					}
				}
			} else {
				while (1) {
					
					k++;
					a[pos++] = 3;
					if (k % m == y1 && j % n == x1) {
						f = true;
						break;
					}
					
					if (k % m == m - 1) break;
					//cout << j << " " << k << " " << a[pos-1]<< endl;
				}
			}
			if (f) break;
			if (k % m == 0 || (k % m == m - 1)) {
				a[pos++] = 1;
				j++;
			}
		}
	}
	cout << pos << endl;
	for (int i = 0; i < pos; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
        return 0;
}


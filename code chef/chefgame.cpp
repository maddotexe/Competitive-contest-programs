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
#define eps 1e-9
#define vi(x) vector<x>
#define pb(x) push_back(x)
#define mem(x,i) memset(x,i,sizeof(x))
#define fori(i,s,n) for(int i=(s);i<(n);i++)
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

vector <vector <int> > vv;

int main()
{
	vector <int> v;
	
	int t, n, k, x;
	
	cin >> t;
	
	double po[52];
	po[0] = 1.0;
	double tmp = 1.0;
	for (int i = 1; i <= 50; i++) {
		po[i] = po[i-1] / 2.0;
	} 
	while (t--) {
		vv.clear();
		cin >> n;
		fori(i, 0, n) {
			cin >> k;
			v.clear();
			fori(j, 0, k) {
				scanf("%d", &x);
				v.pb(x);
			}
			sort(v.begin(), v.end());
			vv.pb(v);
		}
		double sumx = 0.0;
		double sumy = 0.0;
		int pos;
		bool oe;
		for (int i = 0; i < n; i++) {
			fori(j, 0, vv[i].size()) {
				if (j == 0) {
					if (vv[i][j] & 1) {
						oe = false;
						sumy += 1.0;
						pos = j;
					} else {
						oe = true;
						sumx += 1.0;
						pos = j;
					}
				} else {
					if ((vv[i][j] & 1)) {
						if (j - pos == 1 && oe == false) {
							sumy += 1.0;
							pos = j;
						} else {
							sumy += po[j - pos];
						}
					} else {
						if (j - pos == 1 && oe == true) {
							sumx += 1.0;
							pos = j;
						} else {
							sumx += po[j - pos];
						}
					}
				}
				//cout << prev << " " << sumx << " " << sumy << endl;
			}
		}
		//cout << sumx << " " << sumy << endl;
		if (sumx > sumy) {
			cout << "EVEN\n";
		} else if (sumx < sumy) {
			cout << "ODD\n";
		} else {
			cout << "DON'T PLAY\n";
		}
	}
        return 0;
}


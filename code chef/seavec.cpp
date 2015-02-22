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
#include <ctime>

using namespace std;

#define ull unsigned long long
#define ll int
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

inline void fastRead(int *a)
{
  register char c=0;
  while (c<33) c=getchar_unlocked();
  *a=0;
  while (c>33)
    {
      *a=*a*10+c-'0';
      c=getchar_unlocked();
    }
}


vector <ll> vv[100001], vvv[100001];
vector <ll> v, a;
vector <ll> ans;
ll sum;
ll n, x, k, t, val;

void func(ll pos, vector <ll> v) {
	if (pos == n) {
		if (ans.size() < v.size()) {
			ans = v;
	//		sum = curr;
		}
		return;
	}
	
	func(pos+1, v);
	
	fori(j, 0, k) {
		if (vv[pos][j] > a[j]) {
			return;
		}
	}
	
	fori(j, 0, k) {
		a[j] -= vv[pos][j];
	//	curr += vv[pos][j];
	}
	v.pb(pos);
	func(pos+1, v);
	fori(j, 0, k) {
		a[j] += vv[pos][j];
	//	curr -= vv[pos][j];
	}
	//v.resize(v.size() - 1);
		
	
	
}
int main()
{
	
	cin >> t;
	while (t--) {
		vector <ll> tmp;
		map<ll, ll> m;
		
		tmp.clear();
		ans.clear();
		a.clear();
		
		sum = 0, val = 0;
		
		fastRead(&n);
		fastRead(&k);
		
		fori(i, 0, n) {
			vvv[i].clear();
			fori(j, 0, k) {
				fastRead(&x);
				vvv[i].pb(x);
			}
		}
		fori(j, 0, k) {
			fastRead(&x);
			a.pb(x);
		}
		bool f;
		/*fori(i, 0, n) {
			fori(j, 0, k) {
				cout <<vvv[i][j] << " ";
			}
			cout << endl;
		}*/
		fori(i, 0, n) {
			f = false;
			fori(j, 0, k) {
				if (vvv[i][j] > a[j]) {
					f = true;
					break;	
				}
			}
			
			if (!f) {
				vv[val++] = vvv[i];
				m[val-1] = i;
			}
		}
		swap(n, val);
		if (n > 100) {
			fori(i, 0, n) {
				f = false;
				fori(j, 0, k) {
					if (vv[i][j] > a[j]) {
						f = true;
						break;
					}
				}
				
				if (!f) {
					ans.pb(i);
					fori(j, 0, k) {
						a[j] -= vv[i][j];
					}
				}
			}
		} else {
			func(0, tmp);
		}
		cout << ans.size() << endl;
		if (ans.size()) {
			fori(j, 0, ans.size()) {
				printf("%d ", m[ans[j]] + 1);
			}
			printf("\n");
		}
	}
        return 0;
}


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
	int n, m, p, j;
	cin >> n >> m >> p;
	int a[n], b[m];
	map<int, int> mm1, mm;
	vector <int> ans;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		mm[b[i]]++;
	}
	
	for (int i = 0; i < p; i++) {
		mm1.clear();
		for (j = 0; j < m && i + p * j < n; j++) {
			mm1[a[i + p * j]]++;
		}
		if (j != m) continue;
		if (mm == mm1) {
			ans.pb(i+1);
		}
		
		int val = i + j * p;
		int prev = i;
		while (val < n) {
			mm1[a[val]]++;
			mm1[a[prev]]--;
			
			if (mm1[a[prev]] == 0) {
				mm1.erase(mm1.find(a[prev]));
			}
			prev += p;
			val += p;
			if (mm == mm1) {
				ans.pb(prev+1);
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}


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

struct node {
	int maxval;
	int c;
	
	void fillval(int val) {
		maxval = val;
		c = 1;
	}
	
	void merge (node &left, node &right) {
		if (left.maxval > right.maxval) {
			maxval = left.maxval;
			c = left.c;
		} else if (left.maxval < right.maxval) {
			maxval = right.maxval;
			c = right.c;
		} else {
			maxval = left.maxval;
			c = left.c + right.c;
		}
	}
};

vector<node> tree[100002];

vector <int> v;
int n, m;
vector <int> fact[100002], fidx[100002];

void prime_factors()
{
	for (int i = 2; i <= 100000; i++) {
		int x = i;
		for (int j = 2; j * j <= x; j++) {
			if (x % j == 0) {
				fact[i].pb(j);
				while (x % j == 0) x /= j;
			}
		}
		if (x > 1) {
			fact[i].pb(x);
		}
	}
}

void build(int f, int pos, int s, int e)
{
	if (s == e) {
		tree[f][pos].fillval(v[fidx[f][s]]);
		//cout << f << " " << pos << tree[f][pos].maxval << tree[f][pos].c << endl;
		return;
	}
	build(f, 2 * pos + 1, s, (s + e) / 2);
	build(f, 2 * pos + 2, (s + e) / 2 + 1, e);
	tree[f][pos].merge(tree[f][2*pos+1], tree[f][2*pos + 2]);
}

node query(int f, int pos, int s, int e, int l, int r)
{
	//cout << f << pos;
	if (s == l && r == e) {
		return tree[f][pos];
	}
	node left, right, ans;
	if (r <= (s + e) / 2) {
		ans = query(f, 2*pos + 1, s, (s+e) / 2, l, r);
	} else if (l > (s + e) / 2) {
		ans = query(f, 2*pos + 2, (s+e)/2 + 1, e, l, r);
		
	} else {
		left = query(f, 2*pos + 1, s, (s+e)/2, l, (s+e)/2);
        	right = query(f, 2*pos + 2, (s+e)/2 + 1, e, (s+e)/2 + 1, r);
        	ans.merge(left, right);
	}
	return ans;
}

int main()
{

	int x, g, y;
	node temp; 
	vector <int>::iterator it, it1;
	prime_factors();
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		S(x);
		v.pb(x);
		for (int j = 0; j < fact[x].size(); j++) {
			fidx[fact[x][j]].pb(i);
		}
	}
	
	for (int i = 2; i <= 100000; i++) {
		if (fidx[i].size()) {
			tree[i].resize(4 * fidx[i].size());
			build(i, 0, 0, fidx[i].size() - 1);
		}
	}
	
	
	for (int i = 0; i < m; i++) {
		S(g);
		S(x);
		S(y);
		x--;
		y--;
		
		int ans = -1;
		int c = -1;
		
		for (int j = 0; j < fact[g].size(); j++) {
			if (fidx[fact[g][j]].size()) {
				int f = fact[g][j];
				it = lower_bound(fidx[f].begin(), fidx[f].end(), x);
				it1 = upper_bound(fidx[f].begin(), fidx[f].end(), y);
				
				if (it == fidx[f].end()) continue;
				if (it1 == fidx[f].begin()) continue;
				it1--;
				
				int tx = it - fidx[f].begin();
				int ty = it1 - fidx[f].begin();
				
				if (tx > ty) continue;
				//cout << "kk";
				temp = query(f, 0, 0, fidx[f].size() - 1, tx, ty);
				
				if (temp.maxval > ans) {
					ans = temp.maxval;
					c = temp.c;
				} 
			}
			
		}
		
		cout << ans << " " << c << endl;
		
	}
	return 0;
}



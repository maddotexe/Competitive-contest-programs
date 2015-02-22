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
	int sum;
	
	void fillval(int val) {
		sum = val;
	}
	
	void merge(node &left, node &right) {
		sum = left.sum + right.sum;
	}
};
int a[100010];
node tree[300001];

void initialize(int pos, int b, int e)
{
	if (b == e) {
		tree[pos].fillval(a[b]);
		return;
	}
	
	initialize(pos*2, b, (b+e)/2);
	initialize(pos*2+1, (b+e)/2 + 1, e);
	tree[pos].merge(tree[pos*2], tree[pos*2+1]);
}


void update (int pos, int b, int e, int l, int r)
{
	int d;
	if(b == l && r == e) {
		d = tree[b].sum/2;
	}
	if (r <= (b+e)/2) {
		update(pos*2, b, (b+e)/2, l, r);
	} else if (l > (b+e)/2) {
		update(pos*2+1, (b+e)/2+1, e, l, r);
	} else {
		update(pos*2, b, (b+e)/2, l, (b+e)/2);
		update(pos*2+1, (b+e)/2+1, e, (b+e)/2+1, r);
	}
	tree[b].fillval(d);
	tree[b].merge(tree[pos*2], tree[pos*2+1]);
}

node rangesum(int pos, int b, int e, int l, int r)
{
	if(b == l && r == e) {
		return(tree[pos]);
	}
	node left = tree[pos*2];
	node right = tree[pos*2+1];
	node ans;
	if (r <= (b+e)/2) {
		ans = rangesum(pos*2, b, (b+e)/2, l, r);
	} else if (l > (b+e)/2) {
		ans = rangesum(pos*2+1, (b+e)/2+1, e, l, r);
	} else {
		left = rangesum(pos*2, b, (b+e)/2, l, (b+e)/2);
		right = rangesum(pos*2+1, (b+e)/2+1, e, (b+e)/2+1, r);
		ans.merge(left, right);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, x, y, z;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	initialize(1, 1, n);
	int q;
	cin >> q;
	
	for (int i = 0; i < q; i++) {
		cin >> x >> y >> z;
		
		if (x == 1) {
			update(1, 1, n, y, z);
		} else {
			cout << rangesum(1, 1, n, y, z).sum << endl;
		}
	}
	return 0;
}


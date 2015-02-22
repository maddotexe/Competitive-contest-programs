#include <iostream>
#include <cstdio>
#include <vector>

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

struct node {
	int l;
	int r;
};

bool comp(node a, node b) {
	return (a.l < b.l);
}

int main()
{
	int n, m;
	cin >> n >> m;
	int a[n+1], v[m+1];
	node r[m+1];
	for (int i = 1; i <= n; i++) {
		fastRead(&a[i]);
	}
	
	for (int i = 1; i <= m; i++) {
		fastRead(&r[i].l);
		fastRead(&r[i].r);
		v[i] = r[i].r - r[i].l + 1;
	}
	
	int ans = 0;
	
	//sort(r+1, r+m+1, comp);
	
	//for (int i = 1; i < m + 1; i++) cout << r[i].l << r[i].r << endl;
	int p;
	
	int d;
	S(d);
	int res = 0;
	for (int i = 0; i < d; i++) {
		fastRead(&p);
		p += ans;
		if (!a[p] || p < 0) {
			cout << res << endl;
			continue;
		}
		//cout << "p = " << p << endl;
		if (a[p]) a[p]--;
		//for (int k = 0; k < n; k++) cout << a[k+1] << " " ;cout << endl;
		if (!a[p]) {
			int j = 1;
			res = 0;
			while (j <= m) {
				if (p >= r[j].l && p <= r[j].r) {
					//cout << "n " << j <<  endl;
					if (v[j]) v[j]--;
					
				}
				if (!v[j]) res++;
				j++;
			}
			printf("%d\n", res);
			//for (int ik = 0; ik < m; ik++) cout << v[ik+1] << " "; cout << endl;
		} else {
			printf("%d\n", res);
		}
		ans = res;
		
	}
	
        return 0;
}


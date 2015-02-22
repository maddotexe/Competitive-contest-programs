#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>

using namespace std;

#define ull unsigned long long
#define ll long long
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define Sl(x) scanf("%lld",&x)
#define Su(x) scanf("%llu",&x)
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define S(x) scanf("%d",&x)
#define IS(x) cin>>x
#define ISF(x) getline(cin,x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mii map<int,int>
#define p(x) cout<<(x)
#define V(x) vector<x>
#define pb(x) push_back(x)
#define mem(x,i) memset(x,i,sizeof(x))
#define fori(i,s,n) for(i=(s);i<(n);i++)
#define ford(i,s,n) for(i=(n);i>=(s);--i)

int abs(int x) {if(x < 0) return -x; return x;}

double a[200][200];
double c[200][200], b[200][200];
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    IS(n);
    int i,j;
    fori(i,0,n) {
        fori(j,0,n) {
            IS(a[i][j]);
        }
    }
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++);
    fori(i,0,n) {
        fori(j,i,n) {
            c[i][j] = c[j][i] = (a[i][j]+a[j][i])/2.0;
        }
    }
//printing
    fori(i,0,n) {
        fori(j,0,n) {
            b[i][j] = a[i][j]-c[i][j];
            cout << c[i][j] << " ";
        }
        p(endl);
    }
	//printing
    fori(i,0,n) {
        fori(j,0,n) {
            p(b[i][j]), p(" ");
        }
        p(endl);
    }


}

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

int main()
{
	int n, k, t;
	string s, s1;
	
	cin >> t;
	string ss[20000];
	int d = 1;
	while (t--) {
		scanf("%d%d", &n, &k);
		
		cin >> s;
		s1 = s;
		ss[0] = s;
		int l = 1;
		while (1) {
			if (s1[0] == '+') {
				if (s1[n-1] == '-') s1[n-1] = '+';
				else s1[n-1] =  '-';
				s1.erase(s1.begin());
				s1 += '-';
				ss[l++] = s1;
			} else {
				s1.erase(s1.begin());
				s1 += '+';
				ss[l++] = s1;
			}
			
			if (s == ss[l-1]) break;
		}
		
		cout <<  "Experiment #" << d++ << ":\n";
		for (int i = 0; i < k; i++) {
			scanf("%d", &n);
			n = n % (l - 1);
			cout << ss[n] << endl;
		}
	}
				
        return 0;
}


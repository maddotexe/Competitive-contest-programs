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
	string s, s1;
	cin >> s >> s1;
	
	int c = ((s[0]-'0') * 10 + (s[1]-'0') ) * 60 + (s[3] - '0') * 10  + (s[4] - '0');
	int c1 = ((s1[0]-'0') * 10 + (s1[1]-'0') ) * 60 + (s1[3] - '0') * 10  + (s1[4] - '0');
	
	
	c = c - c1;
	if (c < 0) {
		c = abs(c);
		c = 1440 - c;
		c1 = c % 60;
		c = c / 60;
		//cout << c << " " << c1;
		if (c < 10) {
			cout << 0 << c << ":";
		} else {
			cout << c << ":";
		}
		
		if (c1 < 10) {
			cout << 0 << c1;
		} else {
			cout << c1;
		}
		
		
	} else if (c == 0) {
		cout << "00:00\n";
	} else {
		
		c1 = c % 60;
		c = c / 60;
		//cout << c << " " << c1;
		if (c < 10) {
			cout << 0 << c << ":";
		} else {
			cout << c << ":";
		}
		
		if (c1 < 10) {
			cout << 0 << c1;
		} else {
			cout << c1;
		}
	}
	return 0;
}


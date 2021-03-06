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
    int t;

    cin >> t;

    while(t--) {
    	//cout << t-- << endl;
        int v1, v2, req;
        cin >> req >> v1 >> v2;
        if(req%v1 == 0 || req%v2 == 0) {
            cout << "Yes" << endl;
            continue;
        }
        if(req >= v1 && req <= v2) {
            cout << "Yes" << endl;
            continue;
        }
        for (int i = 0; i < 10; i++ ) {
        	//cout << v2 - v1 << endl;
	}
        if(v2-v1 == 0) {
            if(req % v1 == 0) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
            continue;
        }
        if(req < v1) {
            cout << "No" << endl;
            continue;
        }
        if(v2 >= v1*2) {
            cout << "Yes" << endl;
            continue;
        }
        for (int i = 0; i < 10; i++ ) {
        	//cout << v2 - v1 << endl;
	}
        if(req > v2) {
            int a1, a2;
            a1 = req/v1;
            a2 = req%v1;
            if(a1*(v2-v1) >= a2) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
            continue;
        }
    }
}

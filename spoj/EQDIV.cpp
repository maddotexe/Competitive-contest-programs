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
 
int dx[] ={0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
    
int n, c;
int a[103][103];
 
bool check (int x, int y, int i) {
        if (x < 1 || y < 1 || x > n|| y > n || a[x][y] != i) return false;
        return true;
}
 
bool dfs(int x, int y, int i, int z) {
        bool f;
        if (check (x + dx[0], y + dy[0], i)) {
                a[x+dx[0]][y+dy[0]] = -999999;
                c++;
                f = dfs(x+dx[0], y+dy[0], i, z);
        }
        
        if (check (x + dx[1], y + dy[1], i)) {
                a[x+dx[1]][y+dy[1]] = -999999;
                c++;
                f = dfs(x+dx[1], y+dy[1], i, z);
        }
        
        if (check (x + dx[2], y + dy[2], i)) {
                a[x+dx[2]][y+dy[2]] = -999999;
                c++;
                f = dfs(x+dx[2], y+dy[2], i, z);
        }
        if (check (x + dx[3], y + dy[3], i)) {
                a[x+dx[3]][y+dy[3]] = -999999;
                c++;
                f = dfs(x+dx[3], y+dy[3], i, z);
        }
        if (z - 1 == c) {
                return false;
        } else {
                return true;
        }
}
 
int main()
{
        int z = 0, x, y;
        stringstream ss;
        string s;
        while (1) {
                cin >> n;
                getchar();
                if (n == 0) {
                        return 0;
                }
                
                bool f = false;
                for (int i = 1; i < n; i++) {
                        z = 0;
                        c = 0;
                        getline (cin, s);
                        ss.clear();
                        ss << s;
                        for (int j = 1; j <= n; j++) {
                                ss >> x >> y;
                                a[x][y] = i;
                                z++;
                        }       
                        if (f == false) {
                                a[x][y] = -999999;
                                f = dfs(x, y, i, z);
                        }
                }
                
                for (int i = 0; i <=n ; i++) {
                	for (int j = 0; j <= n; j++) {
                		cout << a[i][j] << " ";
                	}
                	cout << endl;
                }
                
                if (f == false) {
                        printf("good\n");
                } else {
                        printf("wrong\n");
                }
        }
        
        return 0;
}

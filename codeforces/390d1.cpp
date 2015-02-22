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
#define pii pair<int,int>
int abs(int x) {if(x < 0) return -x; return x;}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dz[] = {0, 0, -1, 1};

int vis[1001][1001];

int n, m, k;
bool check(int x, int y) // condition checked
{
        if(x < 0 || y < 0 || x >= n || y >= m || vis[x][y] == 1) return false;
        return true;
}

int main()
{

    cin >> n >> m >> k;
    
    vis[0][0] = 1;
    
    queue<pii> q;
    
    q.push(pii(0, 0));
    
    k--;
    
    while(!q.empty())
    {
        int x, y;
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int xx, yy;
            xx = x+dx[i];
            yy = y+dy[i];
            if(!k)break;
            if(check(xx, yy)) {
                vis[xx][yy] = 1;
                q.push(pii(xx, yy));
                k--;
            }
            if(!k) break;
        }
        if(!k) break;
    }
    int ans = 0;
    stringstream ss;
    for(int i = m-1; i >= 0; i--) {
        for(int j = n-1; j >= 0; j--) {
            if(vis[j][i] == 1) {
                ans += (i+j+1);
                int xx, yy;
                xx = 0; yy = 0;
                while(yy != i) {
                    ss << "(" << xx+1 << "," << yy+1 << ")" << " ";
                    yy++;
                }
                while(xx != j) {
                    ss << "(" << xx+1 << "," << yy+1 << ")" << " ";
                    xx++;
                }
                ss << "(" << j+1 << "," << i+1 << ")" << " " << endl;
            }
        }
    }
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << vis[i][j] << " " ;
		}
		cout << endl;
	}*/
    cout << ans << endl;

    string s;

    while(ss.good()) {
        getline(ss, s);
        cout << s << endl;
    }

}

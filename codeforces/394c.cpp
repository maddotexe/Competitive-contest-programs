#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;



char s1[1005][1005];
char s2[1005][1005];
int vis[1005][1005];
int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int c1, c2, c3;
    c1 = c2 = c3 = 0;
    string s;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> s;
            if(s == "01" || s == "10") c1++;
            else if(s == "11") c2++;
            else c3++;
        }
    }

    int pos = 0;
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(c2) {
                s1[i][j] = '1';
                s2[i][j] = '1';
                vis[i][j] = 1;
                c2--;
            }
            else {
                break;
            }
        }
        if(!c2) break;
    }
    j = j%m;
    for(int k = 0; k < j; k++) {
        if(i+1 < n && c3) {
                c3--;
                s1[i+1][k] = '0';
                s2[i+1][k] = '0';
                vis[i+1][k] = 1;
        }
    }
    bool flag = true;
    if(j != 0) for(int k = j; k < m; k++) {
        if(c1) {
            s1[i][k] = '1';
            s2[i][k] = '0';
            vis[i][k] = 1;
            c1--;
        }
        if(i+1 < n && c1) {
            s1[i+1][k] = '0';
            s2[i+1][k] = '1';
            vis[i+1][k] = 1;
            c1--;
        }
    }
    for(int i = n-1; i >= 0; i--) {
        if(!c1) break;
        flag = !flag;
        for(int j = m-1; j >= 0; j--) {
            if(vis[i][j]) continue;
            if(!flag) {
                s1[i][j] = '1';
                s2[i][j] = '0';
            }
            else {
                s1[i][j] = '0';
                s2[i][j] = '1';
            }
            vis[i][j] = 1;
            c1--;
            if(!c1) break;
        }
        if(!c1) break;
    }
	//printing
	 for (int i = 0; i < n; i++) {
	 	for (int j = 0; j < m; j++) {
	 		//cout << vis[i][j] ;
	 	}
	 }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j] == 0) cout << "00 ";
            else cout << s1[i][j] << s2[i][j] << " ";
        }
        cout << endl;
    }
}

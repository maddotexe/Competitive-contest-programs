#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
 
using namespace std;
 
struct tree {
    int maxval;
    int cc;
};
int n, m;
vector<int> v[100005], com[100005], fact[100005];
int v1[100005];
 
vector<tree> vv[100010];
 
void pre() {
    for(int i = 2; i <= 100000; i++) {
        int val = i;
        for(int j = 2; j * j <= val; j++) {
            if(val % j == 0) {
                fact[i].push_back(j);
                while(val % j == 0) {
                    val /= j;
                }
            }
        }
        if(val > 1) {
            fact[i].push_back(val);
        }
    }
}
 
void build(int fact, int pos, int s, int e) {
	cout << fact << pos;
    if(s == e) {
        vv[fact][pos].maxval = v1[com[fact][s]];
        vv[fact][pos].cc = 1;
        cout << fact << " " << pos << " " << vv[fact][pos].maxval << " " << vv[fact][pos].cc << endl;
        return;
    }
    build(fact, pos*2 + 1, s, (s+e)/2);
    build(fact, pos*2 + 2, (s+e)/2 + 1, e);
    if(vv[fact][pos*2 + 1].maxval > vv[fact][pos*2 + 2].maxval) {
        vv[fact][pos] = vv[fact][pos*2 + 1];
    }
    else if(vv[fact][pos*2 + 1].maxval < vv[fact][pos*2 + 2].maxval) {
        vv[fact][pos] = vv[fact][pos*2 + 2];
    }
    else {
        vv[fact][pos] = vv[fact][pos*2 + 1];
        vv[fact][pos].cc = vv[fact][pos*2 + 2].cc + vv[fact][pos*2 + 1].cc;
    }
}
 
tree query(int fact, int pos, int s, int e, int x, int y)
{
        if(s == x && e == y) {
            return vv[fact][pos];
        }
        if(y <= (s+e)/2) {
            return query(fact, pos*2 + 1, s, (s+e)/2, x, y);
        }
        else if(x > (s+e)/2) {
            return query(fact, pos*2 + 2, (s+e)/2 + 1, e, x, y);
        }
        else {
            tree l, r, res;
            l = query(fact, pos*2 + 1, s, (s+e)/2, x, (s+e)/2);
            r = query(fact, pos*2 + 2, (s+e)/2 + 1, e, (s+e)/2 + 1, y);
            if(l.maxval > r.maxval) {
                return l;
            }
            else if(l.maxval < r.maxval) {
                return r;
            }
            else {
                res = l;
                res.cc = r.cc + l.cc;
                return res;
            }
        }
 
}
 
int main()
{
   // ios_base::sync_with_stdio(false);
    cin >> n >> m;
    pre();
    for(int i = 0; i < n; i++) {
        //v1[i] = 90090;
        cin >> v1[i];
        for(int j = 0; j < fact[v1[i]].size(); j++) {
            com[fact[v1[i]][j]].push_back(i);
        }
    }
 
    for(int i = 2; i <= 100000; i++) {
        if(com[i].size()) {
            vv[i].resize(4*(com[i].size()));
            build(i, 0, 0, com[i].size()-1);
        }
    }
    tree aa;
    int val, x, y;
    vector<int> :: iterator left, right;
    for(int i = 0; i < m; i++) {
        cin >> val >> x >> y;
        x--, y--;
        if(y < x) swap(x, y);
        int ans = -1;
        int co = -1;
        for(int j = 0; j < fact[val].size(); j++) {
            if(com[fact[val][j]].size()) {
                int pp = fact[val][j];
                left = lower_bound(com[fact[val][j]].begin(), com[fact[val][j]].end(), x);
                right = upper_bound(com[fact[val][j]].begin(), com[fact[val][j]].end(), y);
                if(right == com[pp].begin()) continue;
                right--;
                int xx, yy;
                if(left == com[pp].end()) continue;
                xx = left - com[pp].begin();
                yy = right - com[pp].begin();
               if(xx > yy) continue;
               // cout << com[pp][x] << " " << com[pp][y] << endl;
                aa = query(fact[val][j], 0, 0, com[fact[val][j]].size()-1, xx, yy);
                //cout << fact[val][j] << " " << aa.maxval << endl;
                if(aa.maxval > ans) {
                    ans = aa.maxval;
                    co = aa.cc;
                }
            }
        }
        //cout << v1[99994] << endl;
        //cout << vv[7][0].maxval << " " << vv[7][0].cc << endl;
        cout << ans << " " << co << endl;
    }
}

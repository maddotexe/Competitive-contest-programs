#include <iostream>
#include <map>
#include <cstdio>
 
using namespace std;
 
int findval[200005];
int cc[200005];
int rank[200005];
map<string, int> m;
 
int find_set(int pos)
{
    if(pos != findval[pos]) return find_set(findval[pos]);
    return pos;
}
int main()
{
    int t;
 
    scanf("%d", &t);
    char name[22];
    while(t--) {
        int n;
        m.clear();
        scanf("%d", &n);
        string s1, s2;
        //getchar();
        int val = 1;
        while(n--) {
            scanf("%s", name);
            s1 = name;
            scanf("%s", name);
            s2 = name;
            if(m[s1] == 0) {
                m[s1] = val++;
                findval[val-1] = val-1;
                cc[val-1] = 1;
                rank[val-1] = 0;
            }
            if(m[s2] == 0) {
                m[s2] = val++;
                findval[val-1] = val-1;
                cc[val-1] = 1;
                rank[val-1] = 0;
            }
            int x = find_set(m[s1]);
            int y = find_set(m[s2]);
           // cout << x << " " << y << endl;
            if(x == y) {
                printf("%d\n", cc[x]);
            }
            else if(x != y) {
                if(rank[y] < rank[x]) {
                    cc[x] += cc[y];
                    findval[y] = x;
                    printf("%d\n", cc[x]);
                }
                else {
                    cc[y] += cc[x];
                    findval[x] = y;
                    printf("%d\n", cc[y]);
                }
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
}

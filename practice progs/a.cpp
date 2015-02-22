#include <bits/stdc++.h>

using namespace std;

#define frl(a, b, c) for( (a) = (b);( a) < (c); (a++))
#define fru(a, b, c) for( (a) = (b); (a) <= (c); (a++))
#define frd(a, b, c) for( (a) = (b); (a) >= (c); (a--))
#define mst(a, b) memset(a, b, sizeof(a))
#define si(a) scanf("%d", &a)
#define ss(a) scanf("%s", a)
#define sc(a) scanf("%c", &a)

#define pb(a) push_back(a)
#define mp make_pair
#define nwl puts("");
#define sp << " " <<

#define sz size()
#define bg begin()
#define en end()
#define X first
#define Y second

#define vi vector <int>
#define vs vector <string>
#define ll long long int
#define dec int i = 0, j= 0, k = 0;

#define i(n) cin >> n;
#define p(s) cout << s;
#define pau system("pause");

const int dx8[] = {-1, -1, -1,  0, 0,  1, 1, 1};
const int dy8[] = {-1,  0,  1, -1, 1, -1, 0, 1};



int a[100];
vector<int> v;
int vis[10000006];
int x;
void make(int t)
{
    queue <int> q;
    dec;
    frl(i, 0, 10)
        if(a[i])
            q.push(i), vis[i] = 1;
    j = 0;
    int cnt = 0;
    while(!q.empty()){
        j = q.front();
        q.pop();
        frl(i, 0, 10){
            if(a[i] && ((j*10 + i) <= x) && (!vis[j*10 +i] || (vis[j*10 + i]  > vis[j] +1)))
                q.push(j *10 + i), vis[j*10 + i] = vis[j]+ 1;//, cnt++;
        }
//        pau;
    }
//    cout << cnt << endl;
//    cout << "done\n";
    frl(i, 1, x){
       if(vis[i]){
            for(j = 1; j * i <= x; j++){
                if(vis[j]){
                    if(vis[i*j])
                        vis[i*j] = min(vis[i*j], vis[i] + vis[j] + 1);
                    else
                        vis[i*j] = vis[i] + vis[j] + 1;
                }
            }
       }
    }
    if(vis[x]){
        cout << "Case #" << t << ": " << vis[x]+1 << endl;
    } else {
        cout << "Case #" << t << ": " << "Impossible\n";
    }
}


int main(){
    freopen("inp.in","r",stdin);
    freopen("out1.txt","w",stdout);
    int tt, t;
    cin >> tt;
    dec;

    frl(t, 1, (tt+1)){
        mst(vis, 0);
        frl(i, 0, 10){
            cin >> a[i];
            if(a[i])
                v.pb(i);
        }
        cin >> x;
        make(t);
//        while(!q.empty()){
//            num = q.front().first;
//            cnt = q.front().second;
//            q.pop();
//            if(vis[num] < cnt){
//                continue;
//            }
//            cout << num << " " << cnt << endl;
//            int temp ;
//            frl(i, 0, n){
//                temp = num * v[i];
//                if(temp <= x && ((!vis[temp] ) || (vis[temp] > cnt +2))){
//                    q.push(mp(temp, cnt+2));
//                    vis[temp] = cnt+2;
//                }
//            }
//        }
//        cout << "cmpl\n";
//        if(vis[x] < 1000000)
//            cout << vis[x] << endl;
//        else
//            cout << -1 << endl;
////            pau;
    }

}
































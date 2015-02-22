#include <iostream>
#include <cstdio>

using namespace std;

int a[2002][2002], a1[2002][2002], a2[2002][2002];
char ar[2002][2002];
int main()
{
    int n, m ,s;

    cin >> n >> m >> s;
    double val = 0;
    for(int i = 0; i <= m; i++) {
        a1[0][i] = a2[0][i] = a[0][i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        a[i][0] = a1[i][0] = a2[i][0] = 0;
        for(int j = 1; j <= m; j++) {
            cin >> ar[i][j];
            if(ar[i][j] == 'X') {
                a[i][j] = a[i][j-1]+1;
            }
            else {
                a[i][j] = a[i][j-1];
            }
            if(j >= s) {
                a1[i][j] = a[i][j]-a[i][j-s];
            }
            else {
                a1[i][j] = a[i][j];
            }
            a2[i][j] = a1[i][j]+a2[i-1][j];
            if(i >= s && j >= s) {
                val += a2[i][j]-a2[i-s][j];
            }
           // cout << a2[i][j] << " ";
        }
       // cout << endl;
    }
    printf("%.6f\n", val/((double)(n-s+1)*(m-s+1)));
}



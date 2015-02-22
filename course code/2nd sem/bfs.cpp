#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
int d[100];
int bfs(int a[4][4], int i, int j, int n)
{
     int k,u;
     for( k = 0; k <n; k++){
             d[k] = 999;
             }
     queue <int> q;
     int s;
     int b[10] = {0};
     q.push(i);
     b[0] = 1;
     d[0] =0;
     if(i==j){
             return 1;
     }
     else
     {
         u = q.front();
         q.pop();
         for (k = 0; k < n; k++)
         {
             if(b[k] == 0 && a[u][k] == 1)
             {
                     q.push(k);
                     d[k] = d[u] +1;
                     b[k] = 1;
             }
         }
         if (d[j] == 999)
            return -1;
         else
             return 1;
     }
}



int main()
{
    int a[4][4];
    int i,j,l,s,n;
    for (l = 0; l < 4; l++)
    {
        for (s = 0; s < 4; s++)
        {
            scanf("%d", &a[l][s]);
        }
    }
    scanf("%d%d", &i, &j);
    n = bfs(a, i , j,4);
    cout<< "\n";
    if(n==1)
    cout << "\nconnected";
    else
    cout << "\nnot";
    for (l = 0; l < 4; l++)
    {
        for (s = 0; s < 4; s++)
        {
            printf("%d ", a[l][s]);
        }
        printf("\n");
    }
    getchar();
    getchar();
getchar();    return 0;
}

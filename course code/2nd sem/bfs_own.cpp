#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

void bfs(int a[10][10], int i, int j, int n)
{
     int k,b[10],u;
     queue <int> q;
     for ( k = 0; k < n ;k++)
     {
         b[k] = 0;
     }
     q.push(i);
     b[i] = 1;
     if(i == j)
          return ;
     else {
          while(!q.empty())
          {
                u = q.front();
                q.pop();
                for ( k = 0 ; k < n; k++)
                { 
                    if(b[k]==0 && a[u][k]==1)
                    { 
                               q.push(k);
                               b[k] = 1;
                    }
                }
                if(u == j)
                {
                     printf("connected");
                }
          }
     }
}
          

int main()
{
    int a[10][10], i, j, n;
    cin >> n;
    for ( i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    cin >> i >> j;
    bfs(a, i, j, n);
    getchar();
    getchar();
    return 0;
} 

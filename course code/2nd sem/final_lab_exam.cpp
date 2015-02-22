#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

void bfs(int a[10][10], int i, int j, int n,int b[10])
{
     int k,u;
     queue <int> q;
    
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
    int a[10][10], i, j, n,b[10],k;
    cin >> n;
    for ( i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
     for ( k = 0; k < n ;k++)
     {
         b[k] = 0;
     }
    cin >> i >> j;
    if(a[i][j]==1) {
                   cout << "freinds";
         return 0;
    }
    bfs(a, i, j, n,b);
    if(b[j]==1)
    {
               cout << "friends of friends";
    }
    else
    {
        cout << "isolated";
    }
    getchar();
    getchar();
    return 0;
} 

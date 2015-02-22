#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
int d[100];
int p = 0;
int bfs(int a[10][10], int i, int j, int n)
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
              p =1;
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
    int a[10][10];
    int n,k=0,w[100],ni[100],nj[100],i,t,j,min,sum =0;
    cin >> n;   
    for( i = 0; i < n; i++)
    {
         for ( j= 0; j < n; j++)
         {
             cin >> a[i][j];
         }
    }
    for( i =0; i < n; i++)
    {
         for(j = i + 1 ; j < n; j++)
         {
           w[k] = a[i][j];
               ni[k] = i;
               nj[k] = j;
               k++;
         }
    }
    for( i =0; i < k; i++)
    {
         t = w[j];
         min = j;
         for( j = 1; j < k; j++)
         {
              if(t > w[j])
              {
                     t = w[j];
                     min = j;
              }
         }
         if(bfs(a, ni[min], nj[min], n))
         {
                   w[min] = 999;
         }
         else
         {
             a[ni[min]][nj[min]] = a[nj[min]][ni[min]] = 1;
             sum += t;
         }
    }
    cout << sum;
}
              
    

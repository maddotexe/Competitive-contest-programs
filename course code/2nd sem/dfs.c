#include <stdio.h>

void dfs(int a[100][100],vector <int> v, int i, int j,int l,int s)
{
     int c, f;
     vector<int> :: iterator *it:
     if(a[i][j]==1)
     {
                   printf("connected\n");
                   return;
     }
     else
     {
         c = i;
         push(c);
         for ( k =0; k < s; k++)
         {
             f=0;
             for(it = v.begin(); it!=v.end(); it++)
             {
                    if(*it == k)
                    {
                           f=1;
                           break;
                    }
             if(a[c][k]==1 && f==0)
             {
                           push(k);
                           bfs(a,v,k,j,l,s);
             }
         }
     }
}
                           

int main()
{
    int i, j;
    int a[100][100];
    int n, m;
    vector <int> v;
    scanf("%d%d", &m, &n);
    for (l = 0; l < n; l++)
    {
        for (s = 0; s < m; s++)
        {
            scanf("%d", &a[l][s]);
        }
    }
    scanf("%d%d", &i, &j);
    dfs(a,v, i, j,l,s);
    return o;
}
            

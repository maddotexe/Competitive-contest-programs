#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void dfs(int a[10][10], vector <int> v, int i, int j, int n)
{
     int c, z, f;
     vector <int> :: iterator it;
     if(a[i][j] == 1)
     {
                printf("connected");
                return;
     }
     else
     {
         c = i;
         for (z = 0; z < n; z++)
         {
             f=0;
             for (it = v.begin(); it != v.end(); it++)
             {
                 if(z == (*it)) {
                           f==1;
                           break;
                 }
             }
             if(a[c][z]==1 && f==0)
             {
                           v.push_back(z);
                           dfs(a, v, z, j, n);
             }
         }
     }
}

int main()
{
    int i, j , n;
    int a[10][10];
    vector <int> v;
    cin >> n;
    for ( i=0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d %d", &i, &j); 
    dfs(a, v, i, j, n);
    return 0;
}

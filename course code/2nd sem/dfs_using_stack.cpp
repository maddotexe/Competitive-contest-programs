#include <iostream>
#include <stack>

void dfs(int a[10][10], int i, int j, int n)
{
     stack <int> s;
     if(a[i][j]==1)
     return ;
     s.push(i);
     while(!s.empty())
     {
                      
     
     

int main()
{
    int a[10][10], n,i,j;
    cin >> n;
    for ( i = 0; i < n; i++) {
        for (j =0 ;j < n;j++) {
            cin >> a[i][j];
        }
    }
    dfs(a, i, j, n);
    getchar();
    getchar();
    return 0;
}

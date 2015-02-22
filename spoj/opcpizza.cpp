#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

bool bin_search(int a[], int c, int b, int f) 
{
     int mid;
     int i;
     int j;
     i = c;
     j = b;
     while (i <= j) {
           
           mid = (i + j) / 2;
           if(a[mid] == f) 
                     return true;
                     
           if(a[mid] > f) 
                     j = mid -1;
           else 
                     i = mid + 1;
     }
     return false;
}

int main()
{
    int n, i;
    int k,p,c=0,t;
    scanf("%d", &t);
    while(t--) {
               scanf("%d%d", &n, &k);
               c= 0;
               int a[n];
               for( i = 0; i < n; i++)
               {
                         scanf("%d", &a[i]);
               }
               sort(a, a+n);
               for(i = 0; i < n ; i++) {
                       if(bin_search(a, 0, n, (k - a[i]))) {
                                       c++;
                       }
               }
               printf("%d\n",c/2);
    }
    return 0;
}

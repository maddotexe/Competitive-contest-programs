#include <iostream>
using namespace std;

void quicksort(int a[100], int l , int h, int n)
{
     int l1 =l;
     int h1 = h;
     if(l > h)
     return;
     int p, temp; 
     p = a[l];
     while(l < h)
     {
             while( a[l] < p)
             {
                 l++;
             }
             while( a[h] > p)
             {
                 h--;
             }
     temp = a[h];
     a[h] = a[l];
     a[l] = temp;
     }
     
     quicksort(a, l1, h-1,n);
     quicksort(a, h+1,h1,n);
     
}
     
     
     
     
     
     

int main()
{
    int n,i;
    int a[100];
    cin >> n;
    for ( i= 0; i < n ;i++)
    {
        cin >> a[i];
    }
    quicksort(a, 0,n-1,n);
    for ( i= 0; i < n;i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}

#include <iostream>

using namespace std;

void merge (int a[], int l, int h)
{
     int i = l, j ,k = l;
     int c[100000];
     int mid = (l + h) / 2;
     j = mid + 1;
     while(i <=mid &&  j <= h)
     {
         if(a[i] < a[j])
         {
                 c[k] = a[i];
                 i++;
//                 cout << " r";
                 k++;
         }
         else
         {
                 c[k] = a[j];
  //               cout << " l";
                 j++;
                 k++;
         } 
     }
     while( i <= mid)
     {//cout << " p";
            c[k] = a[i];
            
            k++;
            i++;
     }
      while( j <= h)
     {
            c[k] = a[j];
            k++;
            j++;
     }
     for (i = l; i < k; i++)
     {
        // cout << c[i] << " ";
         a[i] = c[i];
     }
}
       
void mergesort(int a[], int l, int h)
{
     int mid;
     if (l >= h)
     return;
     mid = (l + h)/ 2;
     mergesort(a, l,mid);
     mergesort(a, mid+1,h);
     merge(a, l, h);
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
    mergesort(a, 0,n-1);
    for ( i= 0; i < n;i++)
    {
        cout << a[i] << " ";
    }
    getchar();
    getchar();
    return 0;
}

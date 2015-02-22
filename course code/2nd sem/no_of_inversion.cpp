#include <iostream>

using namespace std;

long long int s = 0;
void merge (long longint a[], long long int l, long long int h)
{
     long long int i = l, j ,k = l;
     long long int c[100000];
     long long int mid = (l + h) / 2;
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
                 s += mid - i;
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
       
void mergesort(long long int a[], long long int l, long long int h)
{
     long long int mid;
     if (l >= h)
     return s;
     mid = (l + h)/ 2;
     mergesort(a, l,mid);
     mergesort(a, mid+1,h);
     merge(a, l, h);
}


         
     
     


long long int main()
{
    long long int n,i;
    long long int a[100];
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
    cout << s;
    getchar();
    getchar();
    return 0;
}

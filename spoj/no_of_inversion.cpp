#include <iostream>
#include <cstdio>

using namespace std;

long long int s = 0;

void merge (long long int a[], long long int l, long long int h)
{
     long long int i = l, j ,k = l;
     long long int c[100000];
     long long int mid = (l + h) / 2;
     j = mid + 1;
     while(i <=mid &&  j <= h)
     {
         if(a[i] <= a[j])
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
                 if (i <= mid)
                 	s += mid - i + 1;
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
     return;
     mid = (l + h)/ 2;
     mergesort(a, l,mid);
     mergesort(a, mid+1,h);
     merge(a, l, h);
}


int main()
{
    long long int n,i, t;
    long long int a[200001];
    scanf("%lld", &t);
    while (t--) {
    	s = 0;
		scanf("%lld", &n);
    	for ( i= 0; i < n ;i++)
    	{
   			scanf("%lld", &a[i]);
    	}
    	mergesort(a, 0,n-1);
    	cout << s << endl;
    }
    return 0;
}
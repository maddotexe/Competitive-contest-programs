#include <stdio.h>

void make_heap(int a[100], int size)
{
     int k=1;
     int temp;
     if(size==0) 
     {
     	return;
     } 
     else 
     {
         while(k != 0){
                     k = (size-1)/2;
                     if(a[k] < a[size])
                     {
                             temp = a[k];
                             a[k] = a[size];
                             a[size] = temp;
                     }
                     size = k;
         }
     }
}

void heap_sort(int a[100], int i)
{
     int temp = a[0],j;
     a[0] = a[i-1];
     a[i-1] = temp;
     for ( j = 0; j < i-1; j++)
     {
         make_heap(a,j);
     }
     for (j = 0; j <= i; j++) {
		printf("%d ", a[j]);
	}
		puts("");
}
     

int main()
{
    int a[100];
    int n,i,j,b[100];;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        make_heap(a,i);
        for (j = 0; j <= i; j++) {
		printf("%d ", a[j]);
	}
		puts("");
    }
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    j = n;
    for(i = 0 ; i < n; i++)
    {
         //b[i] = a[0] ;
         heap_sort(a,j);
         j--;
    }
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    return 0;
}
        

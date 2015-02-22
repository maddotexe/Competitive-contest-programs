#include <stdio.h>
#include <stdlib.h>

void make_heap (int a[], int size)
{
     int k = 1;
     int temp;
     
     if(size == 0)
     return;
     
     while (k != 0) {
             k = (size - 1) / 2;
             if (a[k] < a[size]) {
                      temp = a[size];
                      a[size] = a[k];
                      a[k] = temp;
             }
             size = k;
             }
             
}

void heap_sort (int a[], int size)
{
     int temp = a[0];
     a[0] = a[size - 1];
     a[size - 1] = temp;
     for (int i = 0; i < size - 1; i++) {
         make_heap(a, i);
         }
}

int main()
{
    int a[100];
    int b[100];
    int n;
    int j;
    
    printf("How many numbers you want to enter?\n");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        make_heap(a, i);
        }
        
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
        }
    
    printf("\n");
    j = n;
    
    for (int i = 0; i < n; i++) {
        b[i] = a[0];
        heap_sort(a, j);    
        j--;
        }
    
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
        }
    
    getchar();
    getchar();
    
    return 0;
}

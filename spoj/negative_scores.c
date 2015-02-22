#include <stdio.h>

int main()
{
    long long int t, n, q, k=1,q1,q2,s,j,i;
    scanf("%ld", &t);
    
    while(t--)
    {
              printf("Scenario#%lld:\n\n", k);
              scanf("%lld%lld", &n, &q);
              long long int a[n];
              for (i = 0; i < n ;i++)
              {
                  scanf("%lld", &a[i]);
              }
              while(q--) {
                            scanf("%lld%lld", &q1, &q2);
                            s = a[q1-1];
                            for (j = q1; j < q2; j++)
                            {
                                 if( s > a[j])
                                 s = a[j];
                            }
                            printf("%lld\n\n", s);
              }
              k++;
    }
    return 0;
}
   
                      
                  
              

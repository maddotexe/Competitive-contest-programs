#include <stdio.h>
#include <string.h>
int main()
{
    int t,l,s,j,d,b[9]={1,4,9,16,25,36,49,64,81};
    char a[801];
    scanf("%d", &t);
    while (t--)
    {
          scanf("%s", &a);
          l = strlen(a);
          if(l%2==1)
          {
                    s = a[0] -48;
                    j=0;
                    while(b[j] < a[0])
                    {
                               j++;
                    }
                    printf("%d" , j);
                    d = a[0]-b[j];
          }
                    
    }
    return 0;
}

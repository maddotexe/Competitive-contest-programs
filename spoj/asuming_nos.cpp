#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int t,n,i,j,a,d,c,l;
    char b[10000];
    scanf("%d", &t);
    while (t--)
    {
          i =0;
          
          a = 5;
          c = 56;
          scanf("%d", &n);
          while(1)
          {
              if(n==2)
          { printf("%d\n", 6);
          break;
          }
              d = 0;
              itoa(a, b, 10);
              l = strlen(b);
              for( j = 0; j < l; j++)
              {
                   if(b[j] == '5' || b[j] == '6')
                           d++;
                   
              }
              if(d==l)
                      i++;
              if(n==i)
                      break;
              a+=5;
              d=0;
              itoa(c, b, 10);
              l = strlen(b);
              for( j = 0; j < l; j++)
              {
                   if(b[j] == '5' || b[j] == '6')
                           d++;
                   
              }
              if(d==l)
                      i++;
              if(n==i)
                      break;
              c= c +4;
          }
          if(n!=2)
          printf("%s\n",b);
    }
    return 0;
    
}

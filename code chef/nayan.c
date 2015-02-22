#include<stdio.h>
#include<math.h>
main()
{
      int test;
      long int sum,c;
      scanf("%d",&test);
      while(test--)
      {
      scanf("%ld",&c);
      sum=sqrt(c);
      while(sum>=1)
      {
      if(c%sum==0)
      {
      sum=c/sum-sum;
      break;
      }
      sum--;
      }
      printf("%ld\n",sum);
      }
}

#include <stdio.h>
typedef unsigned int u32;
typedef  long long int u64;
 
int main(){
  u32 nbCas, z, d, n;
  u64 s;
  register u32 U,u,R,r;
  scanf("%u", &nbCas);
  for(;nbCas--;){
    scanf("%d", &z);
    s=0;
    U=z;
    R=0;
    for(d=1;;){
      u=U;
      r=R<<1;
      ++d;
      U=z/d;
      R=z%d;
      n = u - U;
      if(!n)break;
      s += ((r+(u64)(n-1)*(d-1))*n)>>1;
    }
    for(d=1;d++<u;)s+=z%d;
    printf("%Lu\n", (u64)z*(z-1)/2-s);
  }
  return 0;
}

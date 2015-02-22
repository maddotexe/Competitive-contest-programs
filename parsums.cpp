#include <cstdio>
	
#include <vector>
	
#include <iostream>
	
using namespace std;
	
	
int main()
	
{
	
    vector<int> data;

    vector<char> okay;
	
    while(true)
	
    {
	
        int n;
	
        scanf("%d", &n);
	
        if(n == 0)
	
            break;
	
        data.resize(n);
	
        okay.assign(n, 1);
	
        for(int i = 0; i != n; ++i)
	
        {
	
            scanf("%d", &data[i]);
	
        }
	
        int res = n;
	
        int firstnonneg = -1; // first non-negative after a negative one
	
        for(int i = 0; i != n; ++i)
	
        {
	
            if(data[i] >= 0 && data[(i-1+n)%n] < 0)
	
           {
	
                firstnonneg = i;
	
                goto found;
	
            }
	
        }
	
        if(data[0] < 0)
	
            printf("0\n"); // all < 0
	
       else
	
          printf("%d\n", n); // all > 0
	
        continue;
	
      found:
	
      bool inneg = false;
	
        int sum = 0;

        int i = firstnonneg;
	
        bool onemoretime = false;
	
        while(true)
	
        {
	
            if(inneg)
	
            {
	
                sum += data[i];
	
                if(sum >= 0)
	
                    inneg = false;
	
                else
	
                {
	
//                     cerr << "impossible" << i << endl;
	
                   if(!onemoretime || okay[i])
	
                        --res;
	
                    okay[i] = false;
	
                }
	
            }
	
            else
	
            {
	
                if(onemoretime)
	
                    break;
	
                if(data[i] < 0)
	
               {
	
                   inneg = true;
	
                  sum = data[i];
	
//                     cerr << "impossible" << i << endl;
	
                    --res;
	
                    okay[i] = false;
	
                }
	
            }
	
            --i;
	
            if(i < 0)
	
                i = (i+n)%n;
	
           if(i == firstnonneg)
	
            {
	
                if(onemoretime)
	
                    break;
	
                onemoretime = true;
	
            }
	
        }
	
        
	
        printf("%d\n", res);
	
    }
	
}

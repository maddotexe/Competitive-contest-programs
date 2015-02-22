#include <iostream>
#include <string>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <list>
#include <cmath>
#include <stack>
using namespace std;

#define scan(x) scanf("%d",&x)
#define print(x) printf("%d ",x)
#define println(x) printf("%d\n",x)
#define For(i,a,j,k) for (i = a; i < j; i+= k)
#define For_back(i,a,j,k) for (i = j; i >= a; i-= k)
#define min_queue_int_vector priority_queue<int,vector<int>,greater<int> >
#define min_queue_int priority_queue<int,greater<int> >
#define SET(a,x) memset(a,x,sizeof(a))
#define array_size(A) sizeof(A)/sizeof(A[0])
#define mod 1000000007
#define inf 0x7fffffff
#define Max 100001
typedef pair<int,int> pii;
typedef pair<pii,int> piii;


inline void fi(int *a)
{
    register char c = 0;
    while (c < 33)
	c = getchar();
    *a = 0;
    while (c > 33) {
	*a = *a * 10 + c - '0';
	c = getchar();
    }
}

int main()
{
     int t;
     fi(&t);

     while( t-- ) {
     	int n;
   	fi(&n);
   
        int arr1[n];
        int arr2[n];		
        int i,j;
        int k = 1;
        memset(arr1, 0, sizeof(arr1));
        for (i = 0; i < n; i++) {
		scanf("%d", &j);
		arr1[j] = k++;
	}
	for (i = 0; i < n; i++) {
		scanf("%d", &arr2[i]);
	}
          
        int LIS[n];
        
	LIS[0] = arr2[0];
        
	int count = 1;
          		
        for (i = 1; i < n; i++) {
          		
			  
			  
		if (arr1[arr2[i]] < arr1[LIS[0]]) {
			LIS[0] = arr2[i];
		} else if (arr1[arr2[i]] > arr1[LIS[count-1]]) {
			LIS[count++] = arr2[i];
		} else {
          		int l = 0,r = count-1,m;
	          	int idx = r;
          			        
	          	while( r-l > 0 ) {  
	                	m = (l + r)/2;
	                        if(arr1[LIS[m]] > arr1[arr2[i]]){
	                        	r = m;
	                                idx = r;
	                        } else if(arr1[LIS[m]] == arr1[arr2[i]]){
	     	                        idx = m;
	                                break;
	                        } else l = m+1;
	                        if (m == l) break;             
                	}
                     
              		LIS[idx] = arr2[i];
        	}
	}
   	printf("%d\n", count);
     }	
	return 0;
}

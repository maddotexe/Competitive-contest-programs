#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int r, c;
	char a[20][20], b[25][25];
	int k;
	int i, j, f, h, t ,g;
	
	scanf("%d%d", &r, &c);
	
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}
	
	scanf("%d", &k);
	
	
	k = k / 45;
	
	while (k > 0) {
		if (k >= 2) {
			for (i = 0; i < r; i++) {
				for (j = 0; j < c; j++) {
					b[j][r - i - 1] =  a[i][j];
				}
			}
			k -= 2;
			if (r != c) {
				r = r + c;
				c = r - c;
				r = r - c;
			}
			for (i = 0 ; i < r; i++) {
				for (j = 0; j < c; j++) {
					a[i][j] = b[i][j];
				}
			}
			if (k == 0) {
				for (i = 0; i < r; i++) {
				for (j = 0; j < c; j++) {
					cout << a[i][j];
				}
				
				cout << endl;
				}
			}
		
				
			continue;
			
		}
		int d = r - 1;
		f = r - 1;
		h = c - 1;
		int l = h, y = 0;
		if (k == 1) {
			for (i = 0; i < r + c - 1; ++i) {
        		    int z1 = i < c ? 0 : i - c + 1;
        		    int z2 = i < r ? 0 : i - r + 1;
        		    for (t = 0; t < f; t++) {
     		    			cout << " ";
			    }
 						if (f == -1) {
 							g = 0;
 							y = c- 2;
 						}
 						if (g == 0) {
 							t = 999;
 							for (l = h - y; l > 0; l--) {
 								cout << " ";
 							}
 							l = h - y;
 							
 						}
        		    	for (j = i - z2; j >= z1; --j) {
        		    		
        		    		
		       		    cout << a[j][i - j];
		       		    if (t <= d) {
		       		    	cout << " ";
		       		    	t++;
		       		    } 
		       		    if (l <= h) {
		       		    	cout << " ";
		       		    	l++;
		       		    	
		       		    }
  	    		    	 }
  	    		    	 f--;
  	    		    	 y--;
	                    printf("\n");
        		 }
        		 k--;
		 }
			
		
	}
	
	return 0;
}	

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
        int n, t1, m;
        //enter the no. of data sets
	scanf("%d", &t1);
	
	while (t1--) {
              scanf("%d%d", &n, &m); 

              double x[300];
              double f[300];
              int b[300];
        //enteries of sets

        for (int i = 0; i < n; i++) {
        	x[i] = i + 1;
                cin >> f[i];
        }

        //enter the point
        
            double sum = 0;
            double t = 1;
            int y = n + 1;
            int z = 0;
            y = n + 3;
            for (int i = 0; i < n; i++) {
                t = 1;
                
                for (int j = 0; j < n; j++) {
                        if (i != j) {
                                t = t * (y - x[j]) / (x[i] - x[j]);
                        }

                }

                sum = sum + t * f[i];
                b[i] = sum;
            }
        //output
	    
	
	for ( int i = 0; i < n; i++) {
		cout << sum<< " ";
	}
}

	

        return 0;
}

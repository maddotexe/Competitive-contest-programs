#include <stdio.h>

int main()
{
    int n,d,i,x;
    FILE *fp = fopen("pocri.txt", "w");
	
	for (int j = 12; j <= 100; j++) {
		for (int d = 1; d ; d++) {
        		x = 1;
       		 	for(i = 2; i <= j ; i++) {
        	    		x = ((x+d-1)%i) +1;
        		}
        		if (x == 12) {
        			fprintf(fp, "%d,", d);
        			break;
        		}
    		}
    	}
    return 0;
}


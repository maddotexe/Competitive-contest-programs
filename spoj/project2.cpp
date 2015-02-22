#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    float x[10][10],feature[4];
    int lev[]={4,8,8,8,3,0,0,0,0,0},type,i,j,k,layer;
    float w[10][10][10];
    FILE *fp;
    fp=fopen("data.txt","r");
    //fscanf("");
    
    
    
    
    
    for (i = 0; i < layer; i++) 
    {
        
		srand((unsigned)time(0));
		
		for (j = 0; j < lev[i]; j++) 
        {
			printf("\n random weights of lev %d - ", i);
			for (k = 0; k < lev[i+1]; k++) 
            {
				w[i][j][k] = rand();
				w[i][j][k] = ((int)w[i][j][k] % 9) / 10.0 + 0.1;
				printf("%f ", w[i][j][k]);
			}
			printf("\n");
		}
    }
   
   
   

    
    
    
    
    
    return 0;}

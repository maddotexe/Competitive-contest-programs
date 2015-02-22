#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    float x[10][10],feature[4];
    int lev[]={4,8,8,8,8,3,0,0,0,0},type,i,j,k,layer=5;
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
				printf("\n w[%d][%d][%d]  = %8.5f", i,j,k,w[i][j][k]);
			}
			printf("\n");
		}
    }
   
   
   

    
    
    
    
       
while(fp)
{//while
fscanf(fp,"%f%f%f%f%d",&feature[0],&feature[1],&feature[2],&feature[3],&type);
    printf("\n input vector sample %4.5f %4.5f %4.5f %4.5f %d %d ",feature[0],feature[1],feature[2],feature[3],type);
}// end of while 
   
   
system("pause");
    
    return 0;}

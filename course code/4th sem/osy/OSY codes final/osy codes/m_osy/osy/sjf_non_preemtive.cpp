#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int Twt,Ttt,A[20],Wt[20],n,Bu[20];
float Att,Awt;
char pname[20][20];

void Getdata()
{
	int i;
	printf("Enter no  processes: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("process name: ");
		scanf("%s",&pname[i]);
		printf("BurstTime for P %s = ",pname[i]);
		scanf("%d",&Bu[i]);
		printf("Arrival Time for p %s = ",pname[i]);
		scanf("%d",&A[i]);
	}
}

void Gantt_chart()
{
	int i;
	printf("\nGANTT CHART\n");
	for(i=1;i<=n;i++)
		printf("|\t%s\t",pname[i]);
	printf("\t \n");
	for(i=1;i<=n;i++)
		printf("%d\t\t",Wt[i]);
	printf("%d",Wt[n]+Bu[n]);
	printf("\n");
 }

void Sjf()
{
	int w,t,i,B[10],Tt=0,temp,j;
	char S[10],c[20][20];
	int temp1;

	Twt=Ttt=0;
	w=0;
	for(i=1;i<=n;i++)
	{
		B[i]=Bu[i];
		S[i]='T';
		Tt=Tt+B[i];
	}
	for(i=1;i<=n;i++)
	{
		for(j=3;j<=n;j++)
		{
			if(B[j-1]>B[j])
			{
				temp=B[j-1];
				temp1=A[j-1];
				B[j-1]=B[j];
				A[j-1]=A[j];
				B[j]=temp;
				A[j]=temp1;
				strcpy(c[j-1],pname[j-1]);
				strcpy(pname[j-1],pname[j]);
				strcpy(pname[j],c[j-1]);
			}
		}
	}
	//For the 1st process
	Wt[1]=0;
	w=w+B[1];
	t=w;
	S[1]='F';
	while(w<Tt)
	{
		i=2;
		while(i<=n)
		{
			if(S[i]=='T'&&A[i]<=t)
			{
				Wt[i]=w;
				S[i]='F';
				w=w+B[i];
				t=w;
				i=2;
			}
			else
				i++;
		}
	}
	//CALCULATING AVERAGE WAITING TIME AND AVERAGE TURN AROUND TIME
	for(i=1;i<=n;i++)
	{
		Twt=Twt+(Wt[i]-A[i]);
		Ttt=Ttt+((Wt[i]+Bu[i])-A[i]);
	}
	Att=(float)Ttt/n;
	Awt=(float)Twt/n;
//	printf("Average Turn around time=%3.2f ms ",Att);
	printf("Average Waiting Time=%3.2f ms",Awt);
	Gantt_chart();
}
int main()
{
	Getdata();
	printf("\n");
	Sjf();
}

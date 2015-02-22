#include<stdio.h>
 
struct proc
{
	int id;
	int arrival;
	int burst;
	int rem;
	int wait;
	int finish;
	int ti;
	int turnaround;
	float ratio;
}process[10];
 
int no,k;
int chkprocess(int);
 
int main()
{
	int i, j,t,time = 0,n;
	struct proc temp;
 
	int nextprocess(int);
 

	printf("Enter the number of processes: ");
	scanf("%d", &n);
	printf("Enter the time quantum");
	scanf("%d", &t);
 
	for(i = 1; i <= n; i++)
	{
		process[i].id = i;
 
		printf("Enter the arrival time for process %d: ", i);
		scanf("%d", &(process[i].arrival));
 
		printf(" Enter the burst time for process %d: ", i);
		scanf("%d", &(process[i].burst));
 
		process[i].rem = process[i].burst;
		process[i].ti=0;
		process[i].wait=0;
		process[i].finish=0;
 
	}
 
	for(i = 1; i <= n; i++)
	{
		for(j = i + 1; j <= n; j++)
		{
			if(process[i].arrival > process[j].arrival)
			{
				temp = process[i];
				process[i] = process[j];
				process[j] = temp;
			}
		}
	}
 
	no = 0;
	j = 1;
 
	while(chkprocess(n) == 1)
	{
 
		if(process[no + 1].arrival == time)
			no++;
 
		if((process[j].ti<=t)&&(process[j].rem !=0))
		{
			process[j].rem--;
			process[j].ti++;
 
			for(i = 1; i <= no; i++)
			{
				if((i!=j) && (process[i].rem != 0))
					process[i].wait++;
			}
		}
 
 
		if(process[j].rem==0)
			process[j].finish=time;
 
		if((process[j].ti >= t)||(process[j].rem==0))
		{
 
			process[j].ti = 0;
			j=nextprocess(j);
		}
	 time++;
 
	}
	process[n].finish = time;
 
	printf("\n\n Process  Arrival  Burst   Waiting  Finishing turnaround\n");
	printf("%5s %9s %7s %10s %8s %s\n", "id", "time", "time", "time", "time", "  time");
 
 	double awt=0,atat=0;
	for(i = 1; i <= n; i++)
	{
 
		process[i].turnaround = (process[i].wait-1) + process[i].burst;
		process[i].ratio = (float)process[i].turnaround / (float)process[i].burst;
 
		printf("%5d %8d %7d  %8d %10d %9d ", process[i].id, process[i].arrival,
						  process[i].burst,
						  process[i].wait - 1, process[i].finish,
						  process[i].turnaround); // process[i].ratio);
		
		atat+=process[i].turnaround;
 		awt+=process[i].wait -1;
		printf("\n");
	}
	printf("average waiting time : %f\naverage turn around time : %f\n", awt/n, atat/n);
}
 
 
int chkprocess(int s)
{
	int i;
	for(i = 1; i <= s; i++)
	{
		if(process[i].rem != 0)
			return 1;
	}
	return 0;
}
 
 int nextprocess(int k)
{
	int i;
 
	i=k+1;
 
	while(chkprocess(i) && i!=k)
 
	 {
		if(process[i].rem != 0)
 
			return(i);
		else
			i=(i+1)%no;
	}
 }

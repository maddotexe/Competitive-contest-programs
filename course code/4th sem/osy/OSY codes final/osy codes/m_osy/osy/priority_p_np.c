#include<stdio.h>
 
struct proc
{
	int id;
	int pri;
	int arrival;
	int burst;
	int rem;
	int wait;
	int start;
	int finish;
	int turnaround;
	float ratio;
}process[10], temp;
 
int chkprocess(int);
int nextprocess();
void display();
 
int no,n;
 
main()
{
	int i,a,j,k,time=0;
 
//	printf("\n ---PRIORITY SCHEDULING---\n \n ");
	printf("Enter the number of processes: ");
	scanf("%d", &n);
 
	for(i = 1; i <= n; i++)
	{
		process[i].id = i;
 
		printf("Enter the arrival time for process %d: ", i);
		scanf("%d", &(process[i].arrival));
 
		printf("Enter the burst time for process %d: ", i);
		scanf("%d", &(process[i].burst));
 
		printf("Enter the priority of the process %d:", i);
		scanf("%d", & (process[i].pri));
 
		process[i].rem = process[i].burst;
 
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
 
 
	printf("Choices:");
	printf(" 1.Preemptive Priority Scheduling");
	printf(" 2.Non Preemptive Priority Scheduling");
//	printf("\n \n Enter your choice:");	
	scanf("%d", &a);
 	switch(a)
  	{
    		case 1:
 
      		{
			while(chkprocess(n) == 1)
			{
				if(process[no + 1].arrival == time)
				{
					no++;
 
					if(process[j].rem==0)
			    			process[j].finish=time;
					j = nextprocess();
				}
 
				if(process[j].rem != 0)
				{
					process[j].rem--;
					for(i = 1; i <= no; i++)
					{
						if(i != j && process[i].rem != 0)
							process[i].wait++;
					}
				}
				else
				{
 
					process[j].finish = time;
					j=nextprocess();
					time--;
					k=j;
 
				}
 
				time++;
			}
			process[k].finish = time;
     		}
 
     		case 2:
      		{
			process[1].start = process[1].arrival;
 
			while(chkprocess(n) == 1)
			{
				if(process[no + 1].arrival == time)
				no++;
 
				if(process[j].rem != 0)
				{
					process[j].rem--;
					for(i = 1; i <= no; i++)
					{
						if(i != j && process[i].rem != 0)
						process[i].wait++;
					}
				}
				else
				{
 
					process[j].finish = time;
					j = nextprocess();
					time--;
					process[j].start = time + 1;
				}
 
				time++;
			}
			process[j].finish = time;
      		}
	}
 
	display();
 
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
 
int nextprocess()
{
	int min, l, i;
	min = 0;
	for(i = 1; i <= no; i++)
	{
		if( process[i].rem!=0 && process[i].pri > min)
		{
			min = process[i].pri;
			l = i;
		}
	}
	return l;
}
 
void display()
{
	int i;
 
//	printf("\n\n\t\t\t---PRIORITY SCHEDULING---");
	printf("\nProcess  Arrival  Burst Priority Starting  Waiting  Finishing turnaround \n"); // Tr/Tb \n");
	printf("%5s %9s %7s %15s %10s %8s %9s\n\n", "id", "time", "time", "time", "time", "time", "time");
 
 	double awt=0, atat=0;
	for(i = 1; i <= n; i++)
	{
 
		process[i].turnaround = process[i].wait + process[i].burst;
		process[i].ratio = (float)process[i].turnaround / (float)process[i].burst;
 
		printf("%5d %8d %7d %4d %7d %8d %10d %9d  ", process[i].id, process[i].arrival,
						  process[i].burst, process[i].pri,process[i].start,
						  process[i].wait, process[i].finish,
						  process[i].turnaround);                           // process[i].ratio);
 		awt+=process[i].wait;
		atat+=process[i].turnaround;
		printf("\n");
	}
	printf("average waiting time : %f\naverage turn around time : %f\n", awt/n, atat/n);
}

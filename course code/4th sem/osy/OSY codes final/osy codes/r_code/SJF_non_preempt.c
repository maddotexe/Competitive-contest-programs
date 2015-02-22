#include <stdio.h>
#include <stdlib.h>

struct process {

	int pid;
	int arrival_time;
	int burst_time;
	int waiting_time;
	int turnaround_time;
};

void sort(struct process a[],int n)
{ 

	int i;
	int j;

	for (i = 0;i < n;i++) { 

		for (j = 0;j < n-1;j++) { 

			if (a[j].arrival_time > a[j].arrival_time) { 

				struct process temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	} 
}

int main()
{

	int n;
	int i;
	int j;
	int k;
	int count;
	int c;
	int offset;
	int start_time;
	int total_wait = 0;
	int flag = 0;

	printf("Enter the number of processes:\n");

	scanf("%d",&n);

	struct process a[n];

	for (i = 0;i < n;i++) { 

		scanf("%d",&a[i].arrival_time);
		scanf("%d",&a[i].burst_time);
		a[i].pid = i+1;
		a[i].waiting_time = 0;
	} 

	sort(a,n); 
	 
	int in_queue[n+1];

	for (i = 0;i < n+1;i++) { 

		in_queue[i] = 0;
	}

	count = 1;
	c = 1;
	struct process queue[n];
	queue[0] = a[0];
	in_queue[a[0].pid] = 1;
	i = 0;
	offset = 1;
	start_time = a[0].arrival_time;
	queue[0].waiting_time = 0;
	queue[0].turnaround_time = queue[0].burst_time;
	
	while (count != n) { 
			
			while (queue[i].burst_time + start_time >= a[offset].arrival_time) { 
				
				flag = 1;

				if (in_queue[a[offset].pid] == 0) { 

					queue[count++] = a[offset];
					in_queue[a[offset].pid] = 1;
					offset++;
					if (offset >= n) { 

						break;
					}
				} 

								
			} 
				 

		for (j = i+1;j < count;j++) {

			for (k = i+1;k < count-1; k++) { 

				if (queue[k].burst_time > queue[k+1].burst_time) { 

					struct process temp = queue[k];
					queue[k] = queue[k+1];
					queue[k+1] = temp;
				}
			}
		} 
		

		i++;
		start_time = 0;	 
		for (k = 1; k <= i;k++) { 

			start_time = start_time + queue[k-1].burst_time;
		} 
		

	} 

	for (i = 0; i < n; i++) { 

		for (j = 1; j <= i; j++) { 

			queue[i].waiting_time = queue[i].waiting_time + queue[j-1].burst_time;
		} 

		queue[i].waiting_time = queue[i].waiting_time - queue[i].arrival_time; 

		if (queue[i].waiting_time < 0) { 
			
			queue[i].waiting_time = 0;
		} 
 
		total_wait = total_wait + queue[i].waiting_time;

		printf("The waiting time of %d is %d \n ",queue[i].pid,queue[i].waiting_time);
	}  

		printf("The total waiting time is %d\n",total_wait);
		printf("The average waiting time is %d\n",total_wait/n);

			

	return 0;
}
	

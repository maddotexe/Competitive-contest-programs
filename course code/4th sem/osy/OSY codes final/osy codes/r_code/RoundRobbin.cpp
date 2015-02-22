#include <iostream>
#include <cmath>

using namespace std;

struct jobs {

	int pid;
	int turnaround_time;
	int arrival_time;
	int burst_time;
	int waiting_time;
};

void sort(struct jobs a[],int n)
{

	for (int  i = 0; i < n; i++) {

		for (int j = 0;j < n-1; j++) {

			if (a[j].arrival_time > a[j+1].arrival_time) {

				struct jobs temp = a[j];
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
	int total_wait;
	int quantum;
	int total_burst;

	cout << "Enter the total number of processes:" << endl;
	cin >> n;

	total_wait = 0;
	total_burst = 0;

	cout << "Enter the Time Quantum: " << endl;
	cin >> quantum;

	struct jobs a[n];
	struct jobs rrq[100];
	struct jobs finish_queue[n];

	for (i = 0;i < n;i++) {

		cin >> a[i].arrival_time;
		cin >> a[i].burst_time;
		a[i].pid = i+1;
		a[i].waiting_time = 0;
		total_burst = total_burst + a[i].burst_time;
	}

	sort(a,n);
	total_wait = a[0].arrival_time;
	rrq[0] = a[0];
	i = 1;
	int initial = 0;
	int fin = 0;
	int c = 1;

	while (total_wait < total_burst) {

		total_wait = total_wait + quantum;

		while (a[i].arrival_time <= total_wait && i != n) {

			rrq[c++] = a[i];

			if (i < n) {

				i++;
			}

			if (i == n) {

				break;
			}
		}

		if(rrq[initial].burst_time-quantum > 0) {

			rrq[c] = rrq[initial];
			rrq[c].burst_time = rrq[c].burst_time - quantum;
			c++;
		}

		if (rrq[initial].burst_time-quantum <= 0) {

			finish_queue[fin] = rrq[initial];
			total_wait = total_wait + (rrq[initial].burst_time-quantum );
			finish_queue[fin].turnaround_time = total_wait-finish_queue[fin].arrival_time;
			finish_queue[fin].waiting_time = finish_queue[fin].turnaround_time - finish_queue[fin].burst_time;
			fin++;
		}


		initial++;
      	}
        cout << "The Round Robbin Ready Queue is :\n";
	cout << endl;

	for (int i = 0;i < c;i++) {

		cout <<"P"<< rrq[i].pid << " " ;
	}

	cout << endl << endl;

	for (int i = 0;i < fin;i++) {

		cout << "P"<<finish_queue[i].pid << "  " << finish_queue[i].turnaround_time<< " " << finish_queue[i].waiting_time << endl;
	}

	return 0;
}










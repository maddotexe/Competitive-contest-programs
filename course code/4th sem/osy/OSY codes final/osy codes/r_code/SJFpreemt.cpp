#include <iostream>
#include <cmath>

using namespace std;

struct jobs {

	int burst_time;
	int waiting_time;
	int arrival_time;
	int original_burst_time;
	int turnaround_time;
	int pid;
};

void sort(struct jobs a[],int n)
{
	for (int i = 1; i < n ; i++) {

		int key = a[i].arrival_time;
		int j = i;
		while (j > 0 && a[j-1].arrival_time > key) {

			struct jobs temp = a[j];
			a[j] = a[j-1];
			a[j-1] = temp;

			j--;
		}
	}
}
int main()
{
	int n;
	int c = 0;
	int index = 0;
	cout << "Enter the number of process\n";
	cin >> n;

	struct jobs a[n];
	struct jobs end[n];

	for (int i = 0;i < n; i++) {

		cin >> a[i].arrival_time;
		cin >> a[i].burst_time;
		a[i].pid = i+1;
		a[i].original_burst_time = a[i].burst_time;
	}

	for (int i = 0; i < n;i++) {

		a[i].waiting_time = 0;
	}

	sort(a,n);
	int i;
	for (i = 0; i < n-1; i++) {

		int t = a[i+1].arrival_time-a[i].arrival_time;

		if ((a[i+1].arrival_time - a[i].arrival_time) <= a[i].burst_time && (a[i].burst_time-t) > a[i+1].burst_time) {

				a[i].burst_time = a[i].burst_time - t;
				end[c++] = a[i];
		} else {

			end[c++] = a[i];
		}
	}

	end[c++] = a[i];

	for (int i = 0;i < c;i++) {

		for (int j = 0;j < c-1;j++) {

			if (end[j].burst_time > end[j+1].burst_time) {

				struct jobs temp = end[j];
				end[j] = end[j+1];
				end[j+1] = temp;
			}
		}
	}

	for (int i = 0;i < c; i++) {

		for (int j = 1;j <= i;j++) {

			end[i].waiting_time = end[i].waiting_time + end[j-1].burst_time;
		}

		if (i != 0) {

			end[i].waiting_time = fabs(end[i].waiting_time - end[i].arrival_time);
		}

		end[i].turnaround_time = end[i].burst_time + end[i].waiting_time;
	}


	cout << "P.Id " << "W.T " << "T.A.T " << endl;

	for (int j = 0;j < c;j++) {

		cout << "# " << end[j].pid << "  " <<end[j].waiting_time <<"  " <<  end[j].turnaround_time << endl;
	}

	return 0;
}


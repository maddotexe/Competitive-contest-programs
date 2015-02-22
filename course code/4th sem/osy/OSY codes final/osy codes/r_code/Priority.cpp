#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

struct jobs {

        int arrival_time;
        int burst_time;
        int pid;
        int waiting_time;
        int priority;
        int turnaround_time;
};

void sort(struct jobs a[],int n)
{
        for (int i = 0;i < n; i++) {
                      int min_index = i;
                for (int j = i+1; j < n; j++) {

                        if (a[min_index].arrival_time > a[j].arrival_time) {

                                min_index = j;
                        }
                }

                struct jobs temp = a[i];
                a[i] = a[min_index];
                a[min_index] = temp;
        }
}
void priority_schedule(struct jobs a[],int n)
{
        sort(a,n);

        struct jobs rq[n];
        int c = 0;
        int i;
        for ( i = 0;i < n-1; i++) {

                        int interval = a[i+1].arrival_time - a[i].arrival_time;

                        if (a[i].burst_time > interval && a[i].priority < a[i+1].priority) {

                                a[i].burst_time = a[i].burst_time - interval;
                                rq[c++] = a[i];
                        } else {

                                rq[c++] = a[i];
                        }
        }

         rq[c++] = a[i];

         for (int i = 0;i < c;i++) {

                for (int j = 0;j < c-1;j++) {

                        if (rq[j].priority < rq[j+1].priority) {

                                struct jobs temp = rq[j];
                                rq[j] = rq[j+1];
                                rq[j+1] = temp;
                        }
                }
         }

         for (int i = 0;i < n;i++) {

                cout << rq[i].pid << "  ";
         }
}
int main()
{
        int n;

        cout << "Enter the number of processes\n";
        cin >> n;

        struct jobs a[n];

        for (int i = 0;i < n;i++) {

                cin >> a[i].arrival_time;
                cin >> a[i].burst_time;
                cin >> a[i].priority;
                a[i].pid = i+1;

        }

        priority_schedule(a,n);

        return 0;
}

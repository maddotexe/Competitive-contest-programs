#include <iostream>
#include <vector>
#include <algorithm>
#include "FCFS.hpp"

using namespace std;
struct process {

        int arrival_time;
        int burst_time;
        int pid;
        int waiting_time;

};

int main()
{
        int n;
        cin >> n;
        vector <process> v(n);

        for (int i = 0;i < n; i++) {

                cin >> v[i].arrival_time;
                cin >> v[i].burst_time;
                v[i].pid = i+1;
        }

        FCFS_non_preempt(v);

        return 0;
}

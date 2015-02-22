#include <vector>
using namespace std;
template <typename T>

void FCFS_non_preempt(vector <T> &v)
{
        int n;
        int i;
        int j;

        int total_waiting_time = 0;
        n = v.size();
        v[0].waiting_time = 0;

        for (int i = 0;i < v.size();i++) {

                for (int j =0; j < v.size()-1;j++) {

                        if (v[j].arrival_time > v[j+1].arrival_time) {

                                T temp = v[j];
                                v[j] = v[j+1];
                                v[j+1] = temp;
                        }
                }
        }
        for ( i = 0;i < v.size()-1; i++) {

                cout << v[i].pid << "  ";
                total_waiting_time = total_waiting_time + v[i].burst_time;
        }

        cout << v[i].pid <<" " << endl;

        for (int i = 1;i < n; i++) {

                v[i].waiting_time = v[i-1].waiting_time + v[i-1].burst_time;
        }

        cout << "The total waiting time is : " << total_waiting_time << endl;
        cout << "The Average waiting time is : "  << (float)((total_waiting_time*1.0)/n);

}

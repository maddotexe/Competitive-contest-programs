#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;

int main()
{
        int n;
        int resources;
        cout << "Enter the number of processes\n";
        cin >> n;
        cout << "Enter the number of resources\n";
        cin >> resources;

        int allocation[n][resources];
        int max_allocate[n][resources];
        int need[n][resources];
        bool served[n];
        int available[resources];
        int processes[n];
        int c = 0;
        int cnt = 0;

        cout << "Enter the Allocation Matrix : " << endl;

        for (int i = 0;i < n;i++) {

                for (int j = 0;j < resources;j++) {

                        cin >> allocation[i][j];
                }

                served [i] = false;
        }

        cout << "Enter the Max Allocation Matrix\n";

         for (int i = 0;i < n;i++) {

                for (int j = 0;j < resources;j++) {

                        cin >> max_allocate[i][j];
                        need[i][j] = max_allocate[i][j] - allocation[i][j];
                }

         }

         cout << "Enter the available resources:\n";

         for (int i = 0;i < resources;i++) {

                cin >> available[i];
         }
                int i = 0;

                for (;c != n;) {

                        for (int j = 0;j < resources;j++) {

                                if (served[i] == false)  {

                                        int t = available[j] - need[i][j];

                                        if ( t >= 0)  {

                                                cnt++;
                                        }
                                }
                        }

                        if (cnt == resources) {

                                served[i] = true;
                                processes[c++] = i;
                                cout << "Process  P" << i << "  is in a safe state hence served" << endl;

                                for (int k = 0;k < resources;k++) {

                                        available[k] = available[k] + allocation[i][k];
                                }

                                i = -1;
                        } else {

                                cout << "Process P" << i << "  is not safe hence it is not served" << endl;
                        }

                        cnt = 0;
                        i++;

                        if (i >= n) {

                                cout << "There is no safe state possible deadlock problem" <<endl;
                                cout << "Hence cannot be solved by Banker's Algo" << endl;
                                break;
                        }

                }

         for (int i = 0;i < c;i++) {

                cout << "P"<<processes[i] << "  ";
         }

        return 0;
}


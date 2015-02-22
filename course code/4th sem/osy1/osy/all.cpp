#include <iostream>
#include <queue>
#include <map>
#include <climits>
#include <vector>
#include "scheduling.hpp"


using namespace std;

int main()
{
    int ch;

    while(1) {
        cout << " 1. for first job first serve\n";
        cout << " 2. for shortest job first non-preemtive\n";
        cout << " 3. for shortest job first preemtive\n";
        cout << " 4. for priority non-preemtive\n";
        cout << " 5. for priority preemtive\n";
        cout << " 6. for round robin\n";
        cin >> ch;
        if(ch == 0) return 0;

        switch(ch) {

            case 1: {
                fjfs();
                break;
            }

            case 2: {
                sjfs_non();
                break;
            }

            case 3: {
                sjfs_pree();
                break;

            }

            case 4: {
                priority_non();
                break;
            }

            case 5: {
                priority_pree();
                break;
            }

            case 6: {
                round_robin();
                break;
            }
            default: {
                cout << "quitting \n";
            }
        }

    }

	return 0;

}

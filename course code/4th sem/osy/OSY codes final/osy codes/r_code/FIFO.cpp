#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void FIFO(vector <int> v,int queue_size)
{
        vector <int> queue(queue_size,-999);
        int page_faults = 0;
        int c = 0;
        int flag = 0;

        for (int i = 0; i < v.size(); i++) {

                for (int j = 0;j < queue.size(); j++) {

                        if (queue[j] == v[i]) {

                                flag = 1;
                                break;
                        }
                }

                if (c == queue_size) {

                                c = 0;
                }

                if (flag == 0) {

                                queue[c++] = v[i];
                                page_faults++;
                                flag = 0;
                }

                cout << "For the process  " << i << endl;

                for (int k = 0;k < queue_size; k++) {

                        if (queue[k] != -999) {

                                cout << queue[k] << "  ";
                        }
                }
                cout << endl;
                flag = 0;
        }

        cout << "The Total Number of Page Faults are : " << page_faults << endl;
 }

 int main()
 {
        int n;
        int size;
        srand(time(NULL));

        cout << "Enter queue size : " << endl;
        cin >> size;

        cout << "Enter the number of elements in the page string: " << endl;
        cin >> n;
        vector <int> v(n);
        for (int i = 0; i < n; i++) {

                        v[i] =  abs(rand()%10);
                        cout << v[i] << "  ";
        }

        cout << endl;
        FIFO(v,size);

        return 0;
}

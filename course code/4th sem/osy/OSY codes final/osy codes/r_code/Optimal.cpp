#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cmath>

using namespace std;

void optimal(vector <int> v,int buffer_size)
{
        vector <int> queue(buffer_size,-999);
        int flag = 0;
        int c = 0;
        int index = 0;
        int i;
        int index_flag = 0;
        int jth_index;
        int page_faults = 0;
        int temp;
        int temp_index = 999;
        int j;

        for ( i = 0;i < v.size(); i++) {

                for ( j = 0;j < queue.size(); j++) {

                                if (v[i] == queue[j]) {

                                        flag = 1;
                                        break;
                                }
                }

                if (flag == 0 && c < queue.size()) {

                        queue[c++] = v[i];
                        page_faults++;
                }

              else if (flag == 0 && c >= queue.size()) {

                        for (int k = 0; k < queue.size(); k++) {

                                if (queue[k] != -999) {

                                        temp = queue[k];

                                        for ( j = i;j < v.size();j++) {

                                                        if (v[j] == temp) {

                                                                temp_index = j;
                                                                index_flag = 1;
                                                                break;
                                                        }
                                        }

                                        if (index_flag == 1) {

                                                        if (temp_index > index) {

                                                                index = temp_index;
                                                                jth_index = j;
                                                        }
                                                index_flag = 0;
                                        }

                                        temp_index = -9999;
                                        index_flag = 0;
                                }

                                queue[jth_index] = v[i];
                                page_faults++;
                                c = 0;
                        }
                }

                if (c > queue.size()) {

                        c = 0;
                }

                flag = 0;
                cout << "The Allocation squence for process " << i << endl;
                for (int m = 0;m  < queue.size();m++) {

                        if (queue[m] != -999) {

                                cout << queue[m] << "  " ;
                        }

                }

                cout << endl;
        }

        cout << "The total number of page faults are : " << page_faults;

}

int main()
{
        int n;
        int size;
        srand(time(NULL));

        cout << "Enter the number of requests " << endl;
        cin >> n;

        cout << "Enter the buffer_size : " << endl;
        cin >> size;

        vector <int> v;

        for (int i = 0;i < n; i++) {

                v.push_back(abs(rand()%10));
        }

         for (int i = 0;i < n; i++) {

                cout << v[i] << "  ";
        }

        cout << endl;

        optimal(v,size);

        return 0;
}


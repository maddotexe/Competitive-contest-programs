#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>

using namespace std;

void CLook(vector <int> &v,int size)
{
        int tracks;
        int start;
        int temp_start;
        int index;
        srand(time(NULL));

        vector <int> order;
        vector <int> dummy;
        tracks = 0;


         for (int i = 0;i < v.size(); i++) {

                dummy.push_back(v[i]);
        }

        start = abs(rand()%size);
        v.push_back(start);
        temp_start  =start;
        sort(v.begin(),v.end());

        for (int i = 0;i < v.size(); i++) {

                        if (v[i] == start) {

                        index = i;
                        }
        }

        if (index > 0) {

                if (start-v[index-1]  < v[index+1] - start) {

                        for (int i = index-1; i >= 0; i--) {

                                tracks = tracks + abs(start - v[i]);
                                start = v[i];
                                order.push_back(v[i]);
                        }

                        start = v[v.size()-1];
                        order.push_back(start);

                        for (int i = v.size()-2; i  >= index +1; i--) {

                                tracks = tracks + abs(start - v[i]);
                                start = v[i];
                                order.push_back(v[i]);
                        }

                } else {

                        for (int i = index+1; i < v.size(); i++) {

                                tracks = tracks + abs(v[i] - start);
                                start = v[i];
                                order.push_back(v[i]);
                        }

                        start = v[0];
                        order.push_back(start);

                        for (int i = 1;i <= index - 1; i++) {

                                tracks = tracks + abs(v[i] - start);
                                start = v[i];
                                order.push_back(v[i]);
                        }
                }
        } else {

                tracks = v[v.size()-1] - start;
                for (int i = 0;i < v.size(); i++)  {

                        if (v[i] != start) {

                                order.push_back(v[i]);
                        }
                }
        }

        cout << "The Starting Track is : " << temp_start << endl;
        cout << "The Order of Request is : " << endl;

        for (int i = 0; i < dummy.size(); i++) {

                cout << dummy[i] <<"  " ;
        }

        cout << endl;
        cout << "The Order in which the request is granted is : " << endl;

        for (int i = 0; i < order.size(); i++) {

                cout << order[i] << "  ";
        }

        cout << endl;

        cout << "The Total Number of tracks is : " << tracks << endl;

}

int main()
{
        int n;
        int size;
         vector <int> v;
         srand(time(NULL));

        cout << "Enter the number of requests" << endl;
        cin >> n;

        cout << "Enter the size of the disk" << endl;
        cin >> size;

        for (int i = 0; i < n; i++) {

                v.push_back(abs(rand()%size));
        }

        CLook(v,size);

        return 0;
}

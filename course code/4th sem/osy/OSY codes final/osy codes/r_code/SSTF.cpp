#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

void SSTF(vector <int> v,int size)
{
        srand(time(NULL));
        vector <bool> b(v.size(),false);
        vector <int> out;
        int tracks;
        int total_tracks;
        int start;
        int min_dist = 9999;
        int index;
        int temp;

        tracks = 0;
        start = abs(rand()%200);
        total_tracks = 0;

        while (total_tracks != v.size()) {

                for (int i = 0; i < v.size(); i++) {

                        if (!b[i]) {

                                        temp = abs(start - v[i]) ;

                                        if (temp < min_dist) {

                                                min_dist = temp;
                                                index = i;
                                        }
                        }
                }

                start = v[index];
                b[index] = true;
                tracks = tracks + min_dist;
                out.push_back(v[index]);
                total_tracks++;
                min_dist = 99999;
        }

        cout << "The Start Track is : " << start << endl;
        cout << "The Order of the Seek Requests is : " << endl;

        for (int i = 0; i < v.size(); i++) {

                cout << v[i] << "  ";
        }

        cout << endl;

        for (int i = 0;i < out.size(); i++) {

                cout << out[i] << "  ";
        }

        cout << endl;

        cout << "The total number of tracks covered are :  " << tracks << endl;
}

int main()
{
        int n;
        int size;
        srand(time(NULL));

        cout << "Enter the number of requests " << endl;
        cin >> n;

        cout << "Enter the size of the disk" << endl;
        cin >> size;

        vector <int> v;

        for (int i = 0; i < n; i++) {

                v.push_back(abs(rand()%size));
        }

        SSTF(v,n);

        return 0;
}


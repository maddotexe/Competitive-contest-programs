#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void FCFS(vector <int> v,int size);

void FCFS(vector <int> v,int size)
{
        int tracks;
        int start;
        srand(time(NULL));

        start = (int)(abs(rand()%size));

        tracks = abs(v[0] - start);

        for (int i = 1; i < v.size() - 1; i++) {

                tracks = tracks + abs(v[i] - v[i+1]);
        }

        cout << "The Start Track is :" << start << endl << endl;

        cout << "The order in which the tracks are processed are :-" << endl;

        for (int i = 0; i < v.size(); i++) {

                cout << v[i] << "  ";
        }

        cout << endl;

        cout << "The total tracks covered are :- " << endl;
        cout << tracks;

}

int main()
{
        int n;
        int size;
        srand(time(NULL));

        cout << "Enter the number of seeks" << endl;
        cin >> n;

        cout << "Enter the size of the disk : " << endl;
        cin >> size;

        vector <int> v;
        vector <int> v1(n,10);

        for (int i = 0; i < n; i++) {

                v.push_back(abs(rand()%size));
        }

        FCFS(v,n);

        return 0;
}

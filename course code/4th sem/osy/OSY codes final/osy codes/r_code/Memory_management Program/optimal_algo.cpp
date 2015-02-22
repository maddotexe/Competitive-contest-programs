#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int find_val(vector<int> v, int rn)
{
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == rn) {
            return i;
        }
    }

    return -1;
}

int find_farthest(vector<int> v, int j, vector<int> s) {

    vector<int>::iterator it = find(s.begin() + j, s.end(), v[0]);
    int max = 0;

    for (int i = 1; i < v.size(); i++) {
            if (it < find(s.begin() + j, s.end(), v[i])) {
                it = find(s.begin() + j, s.end(), v[i]);
                max = i;
            }
    }

    return max;
}

void print_vector(vector<int> v)
{
    cout << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "  ";
    }
}

int main()
{
    vector<int> v;
    vector<int> s;
    int n;
    int num;
    int ctr;
    int rn;

    ctr = 0;

    cout << "Enter the size of the table : ";
    cin >> n;

    cout << "Enter The size of the string : ";
    cin >> num;

    cout << "Enter The String ";
    for (int i = 0; i < num; i++) {
        cin >> rn;

        s.push_back(rn);
    }

    for (int i = 0; i < num; i++) {

        if (v.size() < n) {

            int k = find_val(v, s[i]);

            if (k == -1) {
                v.push_back(s[i]);
                ctr++;
            }
        } else if (v.size() == n) {
            int k = find_val(v, s[i]);

            if (k == -1) {
                int max = find_farthest(v, i, s);
                v[max] = s[i];
                ctr++;
            }
        }

        print_vector(v);
    }

    cout << endl << "Total number Of page faults are : " << ctr;

    return 0;
}

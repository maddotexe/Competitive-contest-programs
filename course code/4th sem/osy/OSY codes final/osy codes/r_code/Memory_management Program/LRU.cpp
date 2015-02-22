#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef vector<pair<int, int> > vector_pair;

int find_val(vector_pair v, int rn)
{
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first == rn) {
            return i;
        }
    }

    return -1;
}

int find_lru(vector_pair v)
{
    int min = v[0].second;
    int j = 0;

    for (int i = 1; i < v.size(); i++) {
        if (min > v[i].second) {
            min = v[i].second;
            j = i;
        }
    }

    return j;
}

void print_vector(vector_pair v)
{
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << "  ";
    }
    cout << endl;
}

int main()
{
    vector_pair v;
    int n;
    int num;
    int ctr;

    ctr = 0;

    cout << "Enter The Size of the Table : ";
    cin >> n;

    cout << "Enter the size of the String : ";
    cin >> num;

    cout << "Enter the String : " << endl;

    for (int i = 0; i < num; i++) {
        int rn;
        pair<int, int> p;

        cin >> rn;
        p.first = rn;
        p.second = i;

        if (v.size() < n) {
            int k = find_val(v, rn);

            if (k != -1) {
                v[k].second = i;
                cout << "Page Hit   ";
            } else if (k == -1) {
                v.push_back(p);
                cout << "Page Miss  ";
                ctr++;
            }
        } else if (v.size() == n) {
            int k = find_val(v, rn);

            if (k != -1) {
                v[k].second = i;
                cout << "Page Hit   ";
            } else if (k == -1) {
                int min = find_lru(v);
                cout << "Page Miss  ";

                v[min].first = rn;
                v[min].second = i;
                ctr++;
            }
        }

        print_vector(v);
    }

    cout << endl << endl << "The number Of Page fault : " << ctr;

    return 0;
}

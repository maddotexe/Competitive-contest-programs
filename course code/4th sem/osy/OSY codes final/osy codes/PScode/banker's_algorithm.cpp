#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n_proc = 0;
    int n_res = 0;
    vector<int> v;
    cout << "enter number of process" << endl;
    cin >> n_proc;
    cout << "enter number of resources" << endl;
    cin >> n_res;

    cout << "enter allocation matrix" << endl;
    int alloc[n_proc][n_res];
    for (int i = 0; i < n_proc; i++) {
        for (int j = 0; j < n_res; j++) {
                cin >> alloc[i][j];
        }
    }
    cout << endl;

    cout << "enter maximum matrix" << endl;
    int m[n_proc][n_res];
    for (int i = 0; i < n_proc; i++) {
        for (int j = 0; j < n_res; j++) {
            cin >> m[i][j];
        }
    }
    cout << endl;

    cout << "enter available matrix" << endl;
    int avail[n_res];
    for (int i = 0; i < n_res; i++) {
        cin >> avail[i];
    }
    cout << endl;

    cout << "the need matrix is" << endl;
    int need[n_proc][n_res];
    for (int i = 0; i < n_proc; i++) {
        for (int j = 0; j < n_res; j++) {
            need[i][j] = m[i][j] - alloc[i][j];
            cout << need[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    int flag = false;
    int cnt = n_proc * n_res;
    int k;
    int g;
    int lk = 0;
    while (1) {
        flag = false;
        k = 0;
        for (int i = 0; i < n_proc; i++) {
            for (int j = 0; j < n_res; j++) {
                if (need[i][j] == 999) {
                    k++;
                }
            }
        }
        if (k == cnt) {
            flag = true;
        }
        if (flag) {
            break;
        }

        for (int i = 0; i < n_proc; i++) {
            lk = 0;
            for (int j = 0; j < n_res; j++) {
               if (avail[j] - need[i][j] >= 0) {
                 lk++;
               }
            }
            if (lk == n_res) {
                for (int m = 0; m < n_res; m++) {
                    avail[m] = avail[m] + alloc[i][m];
                    need[i][m] = 999;
                }
                v.push_back(i);
                i = n_proc;
            }
        }
    }
    cout << "the output sequence is " << endl;
    cout << "< ";
    for (int i = 0; i < v.size() - 1; i++) {
        cout << v[i] << " , ";
    }
    cout << v[v.size() - 1] << " ";
    cout << ">" << endl;

    return 0;
}

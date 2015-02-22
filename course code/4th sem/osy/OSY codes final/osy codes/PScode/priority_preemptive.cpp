#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int emp(vector<int> v)
{
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != 0) {
            return 0;
        }
    }
    return 1;
}

int swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int min_index(vector<int> v, int t, vector<int> att, vector<int> bt)
{
    int max = -9999;
    int index = 0;
    int prev = 8888;
    for (int i = 0; i < v.size(); i++) {
        if (att[i] <= t) {
            if (v[i] > max && bt[i] != 0) {
                if (v[i] != max) {
                    index = i;
                    max = v[i];
                    prev = att[i];
                } else {
                    if (att[i] < prev) {
                        index = i;
                        prev = att[i];
                    }
                }
            }
        }
    }
    return index;
}

int main()
{
    int n;
    cin >> n;
    vector<int> att(n);
    vector<int> bt(n);
    vector<int> ct(n);
    vector<int> pt(n);
    vector<int> tat(n);
    vector<int> pr(n);
    vector<int> wt(n);
    vector<int> var(n);
    vector<int> var2(n);
    for (int i = 0; i < n; i++) {
        cin >> pt[i] >> pr[i] >> att[i] >> bt[i];
        var[i] = pt[i];
        var2[i] = bt[i];
    }
    int min_at = *min_element(att.begin(), att.end());
    int time = min_at;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (att[j - 1] > att[j]) {
                swap(att[j - 1], att[j]);
                swap(bt[j - 1], bt[j]);
                swap(pt[j - 1], pt[j]);
            }
        }
    }
    int min;
    while (1) {
        if (emp(bt)) {
            break;
        }
        min = min_index(pr, time, att, bt);
        bt[min]--;
        time++;
        if (bt[min] == 0) {
            ct[min] = time;
        }
    }
    double wtime = 0;
    double ttime = 0;

    for (int i = 0; i < n; i++) {
        pt[i] = var[i];
        bt[i] = var2[i];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - att[i];
        wt[i] = tat[i] - bt[i];
    }
    for (int i = 0; i < n; i++) {
        wtime += wt[i];
        ttime += tat[i];
    }
    cout << "avg waiting time " << wtime / double(n) << endl;
    cout << "avg total time " << ttime / double(n) << endl;

    return 0;
}

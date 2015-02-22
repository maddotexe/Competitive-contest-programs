#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

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

int set_queue(list<int> &q, int &time, vector<int> &att, vector<int> &pt, vector<bool> &tell)
{
    for (int i = 0; i < att.size(); i++) {
        if (tell[i] == false) {
            if (att[i] <= time) {
                q.push_back(pt[i]);
                tell[i] = true;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int time_q;
    cout << "enter time quantum" << endl;
    cin >> time_q;

    vector<int> att(n);
    vector<int> bt(n);
    vector<int> pt(n);
    vector<int> ct(n);
    vector<int> tat(n);
    vector<int> wt(n);
    vector<int> var(n);
    vector<int> var2(n);
    list<int> q;
    vector<bool> tell(n);


    for (int i = 0; i < n; i++) {
        cin >> pt[i] >> att[i] >> bt[i];
        tell[i] = false;
        var[i] = pt[i];
        var2[i] = bt[i];
        pt[i] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (att[j - 1] > att[j]) {
                swap(att[j - 1], att[j]);
                swap(bt[j - 1], bt[j]);
                swap(pt[j - 1], pt[j]);
            }
        }

    }

    int time = att[0];
    q.push_back(pt[0]);
    tell[0] = true;
    int counter = 0;
    list<int>::iterator it = q.begin();
    list<int>::iterator it2;
    bool complete = false;
    int pretime = 0;
    bool isit = false;
    bool doneit = false;
    while (1) {
        doneit = false;
        if (emp(bt)) {
            break;
        }
        counter = 0;
        while (1) {
            if (isit) {
                break;
            }
            if (counter == time_q) {
                break;
            }
            counter++;
            if (! q.empty() && bt[*it] != 0) {
                bt[*it]--;
                time++;
                if (bt[*it] == 0) {
                    ct[*it] = time;
                    it2 = it;
                    it++;
                    doneit = true;
                    q.erase(it2);
                    isit = true;
                    break;
                }
            }
            set_queue(q, time, att, pt, tell);
        }
        isit = false;
        if (doneit == false) {
            q.push_back(*it);
            it++;
        }
    }
    for (int i = 0; i < n; i++) {
        pt[i] = var[i];
        bt[i] = var2[i];
    }
    double wtime = 0;
    double ttime = 0;
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

    return  0;
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;
//functions
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
int min_index(vector<int> v, int t, vector<int> att)
{
    int min = 9999;
    int index = 0;
    int prev = 8888;
    for (int i = 0; i < v.size(); i++) {
        if (att[i] <= t) {
            if (v[i] < min && v[i] != 0) {
                if (v[i] != min) {
                    index = i;
                    min = v[i];
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
int emp(vector<int> v)
{
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != 0) {
            return 0;
        }
    }
    return 1;
}
void sort(vector<int> pt, vector<int> bt, vector<int> att, vector<int> pn, int s, int e)
{
    for (int i = s; i < e; i++) {
        for (int j = s + 1; j < e; j++) {
            if (pt[j - 1] < pt[j]) {
                swap(bt[j - 1], bt[j]);
                swap(att[j - 1], att[j]);
                swap(pt[j - 1], pt[j]);
                swap(pn[j - 1], pn[j]);
            }
        }
    }
}
int max(vector<int> a, int n, int t)
{
    int m = t;
    for (int i = n; i < t; i++) {
        if (m < a[i]) {
            return i - 1;
        }
    }

    return m;
}

int max(vector<int> a, int n)
{
    int m = a[0];
    for (int i = 1; i < n; i++) {
        if (m < a[i]) {
            m = a[i];
        }
    }

    return m;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}




int main()
{
    int n;
    int s;
    while (1) {
            if (true) {
                cout << " ENTER 0 TO EXIT " << endl;
                cout << " 1 : FCFS (first come first served)" << endl;
                cout << " 2 : SJF  (shortest job first) :: NON pre-emptive" << endl;
                cout << " 3 : SJF  (shortest job first) :: pre-emptive" << endl;
                cout << " 4 : PRIORITY                  :: NON pre-emptive" << endl;
                cout << " 5 : PRIORITY                  :: pre-emptive" << endl;
                cout << " 6 : RR   (round robin)" << endl;
                cin >>  n;
            }
            if  (! n ) {
                break;
            } else {
                    cout << "enter SIZE" << endl;
                    cin >> s;
                    vector<int> att(s);
                    vector<int> bt(s);
                    vector<int> pn(s);
                    vector<int> ct(s);
                    vector<int> tat(s);
                    vector<int> pt(s);
                    vector<int> wt(s);
                    vector<int> var(s);
                    vector<int> var2(s);
                    for (int i = 0; i < s; i++) {
                        cin >> pn[i] >> att[i] >> bt[i];
                        var[i] = pn[i];
                        var2[i] = bt[i];
                    }

                switch(n) {
                case 1:
                case 2:
                case 3:
                case 6:

                    //swap arrival time
                    for (int i = 0; i < s; i++) {
                        for (int j = 1; j < s; j++) {
                            if (att[j - 1] > att[j]) {
                                swap(att[j - 1], att[j]);
                                swap(bt[j - 1], bt[j]);
                                swap(pt[j - 1], pt[j]);
                            }
                        }
                    }

                    if (n == 1) {
                        ct[0] = att[0] + bt[0];
                        for (int i = 1; i < s; i++) {
                            ct[i] = ct[i - 1] + bt[i];
                        }
                        double attime = 0;
                        double awtime = 0;
                        cout << "COMPLETION TIME " << endl;
                        for (int i = 0; i < s; i++) {
                            cout << ct[i] << " ";
                        }
                        for (int i = 0; i < s; i++) {
                            tat[i] = ct[i] - att[i];
                            wt[i] = tat[i] - bt[i];
                            awtime += wt[i];
                            attime += tat[i];
                        }
                        if (true) {
                            cout << endl;
                            cout << "AVG waiting TIME" << endl;
                            cout << awtime / double(s) << endl;
                            cout << "AVG total time " << endl;
                            cout << attime / double(s) << endl;
                        }

                    } else if (n == 2) {
                        int maxat = max(att, s);
                        int flag = 0;
                        int s1 = 0;
                        do {
                            if (flag == 0) {
                                flag++;
                                ct[s1] = bt[s1] + att[s1];
                            } else {
                                ct[s1] = bt[s1] + ct[s1 - 1];
                            }
                        } while (maxat > ct[s1 - 1]);
                        s1++;
                        for (int i = 0; i < s; i++) {
                            for (int j = s1 + 1; j < s; j++) {
                                if (bt[j - 1] > bt[j]) {
                                swap(bt[j - 1], bt[j]);
                                swap(att[j - 1], att[j]);
                                swap(pn[j - 1], pn[j]);
                                }
                            }
                        }

                        for (int i = s1; i < s; i++) {
                            ct[i] = bt[i] + ct[i - 1];
                        }
                        double awtime = 0;
                        double attime = 0;
                        //compute waiting and arrival
                        for (int i = 0; i < s; i++) {
                            tat[i] = ct[i] - att[i];
                            wt[i] = tat[i] - bt[i];
                            awtime += wt[i];
                            attime += tat[i];
                        }
                        //print
                        if (true) {
                            cout << "COMPLETION TIME " << endl;
                            for (int i = 0; i < s; i++) {
                                cout << ct[i] << " ";
                            }
                            cout << endl;
                            cout << "AVG waiting TIME" << endl;
                            cout << awtime / double(s) << endl;
                            cout << "AVG total time " << endl;
                            cout << attime / double(s) << endl;
                        }
                    } else if (n == 3) {
                            int min_at = *min_element(att.begin(), att.end());
                            int time = min_at;
                            for (int i = 0; i < s; i++) {
                                for (int j = 1; j < s; j++) {
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
                                min = min_index(bt, time, att);
                                bt[min]--;
                                time++;
                                if (bt[min] == 0) {
                                ct[min] = time;
                                }

                            }
                            for (int i = 0; i < s; i++) {
                                bt[i] = var2[i];
                            }
                        if (true) {
                            cout << "COMPLETION TIME " << endl;                                //pn[i] = var[i];

                            for (int i = 0; i < s; i++) {
                                cout << ct[i] << " ";
                            }
                            double awtime = 0;
                            double attime = 0;
                        //compute waiting and arrival
                            for (int i = 0; i < s; i++) {
                                tat[i] = ct[i] - att[i];
                                wt[i] = tat[i] - bt[i];
                                awtime += wt[i];
                                attime += tat[i];
                            }
                            cout << endl;
                            cout << "AVG waiting TIME" << endl;
                            cout << awtime / double(s) << endl;
                            cout << "AVG total time " << endl;
                            cout << attime / double(s) << endl;
                        }
                    } else if (n == 6) {
                            int time_q;
                            cout << "enter time quantum" << endl;
                            cin >> time_q;
                            list<int> q;
                            vector<bool> tell(s);


                            for (int i = 0; i < s; i++) {
                                tell[i] = false;
                                pt[i] = i;
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
                            for (int i = 0; i < s; i++) {
                                pn[i] = var[i];
                                bt[i] = var2[i];
                            }
                        if (true) {
                            cout << "COMPLETION TIME " << endl;
                            for (int i = 0; i < s; i++) {
                                cout << ct[i] << " ";
                            }
                            double awtime = 0;
                            double attime = 0;
                        //compute waiting and arrival
                            for (int i = 0; i < s; i++) {
                                tat[i] = ct[i] - att[i];
                                wt[i] = tat[i] - bt[i];
                                awtime += wt[i];
                                attime += tat[i];
                            }
                            cout << endl;
                            cout << "AVG waiting TIME" << endl;
                            cout << awtime / double(s) << endl;
                            cout << "AVG total time " << endl;
                            cout << attime / double(s) << endl;
                        }
                    }

                break;
                    //swap arrival time

                case 4:
                case 5:
                    for (int i = 0; i < s; i++) {
                        for (int j = 1; j < s; j++) {
                            if (att[j - 1] > att[j]) {
                                swap(att[j - 1], att[j]);
                                swap(bt[j - 1], bt[j]);
                                swap(pt[j - 1], pt[j]);
                            }
                        }
                    }
                    if (n == 4) {
                            for (int i = 0; i < s; i++) {
                                cin >> pt[i];
                            }

                                        int maxat = max(att, n);
                                        int flag = 0;
                                        int s1 = 0;
                                        do {
                                            if (flag == 0) {
                                            flag++;
                                            ct[s1] = bt[s1] + att[s1];
                                            s1++;
                                            } else {
                                                int prev;
                                                prev = max(att, s1, n);
                                                sort(pt, bt, att, pn, s1, prev + 1);
                                                ct[s1] = bt[s1] + ct[s1 - 1];
                                                s1++;
                                            }
                                        } while (maxat >= ct[s1 - 1]);

                                        for (int i = s1; i < s; i++) {
                                            for (int j = s1 + 1; j < s; j++) {
                                                if (pt[j - 1] < pt[j]) {
                                                swap(bt[j - 1], bt[j]);
                                                swap(att[j - 1], att[j]);
                                                swap(pt[j - 1], pt[j]);
                                                swap(pn[j - 1], pn[j]);
                                                }
                                            }
                                        }

                                        for (int i = s1; i < s; i++) {
                                            ct[i] = bt[i] + ct[i - 1];
                                        }

                                        for (int i = 0; i < s; i++) {
                                            tat[i] = ct[i] - att[i];
                                            wt[i] = tat[i] - bt[i];
                                        }
                                        for (int i = 0; i < s; i++) {
                                pn[i] = var[i];
                                bt[i] = var2[i];
                            }
                        if (true) {

                            cout << "COMPLETION TIME " << endl;
                            for (int i = 0; i < s; i++) {
                                cout << ct[i] << " ";
                            }
                            double awtime = 0;
                            double attime = 0;
                        //compute waiting and arrival
                            for (int i = 0; i < s; i++) {
                                tat[i] = ct[i] - att[i];
                                wt[i] = tat[i] - bt[i];
                                awtime += wt[i];
                                attime += tat[i];
                            }
                            cout << endl;
                            cout << "AVG waiting TIME" << endl;
                            cout << awtime / double(s) << endl;
                            cout << "AVG total time " << endl;
                            cout << attime / double(s) << endl;
                        }
                    } else if (n == 5) {

                            for (int i = 0; i < s; i++) {
                                cin >> pt[i];
                            }
                        int min_at = *min_element(att.begin(), att.end());
    int time = min_at;
    for (int i = 0; i < s; i++) {
        for (int j = 1; j < s; j++) {
            if (att[j - 1] > att[j]) {
                swap(att[j - 1], att[j]);
                swap(bt[j - 1], bt[j]);
                swap(pt[j - 1], pt[j]);
                swap(pn[j - 1], pn[j]);
            }
        }
    }
    int min;
    while (1) {
        if (emp(bt)) {
            break;
        }
        min = min_index(pn, time, att, bt);
        bt[min]--;
        time++;
        if (bt[min] == 0) {
            ct[min] = time;
        }
    }
    double wtime = 0;
    double ttime = 0;

    for (int i = 0; i < s; i++) {
        pn[i] = var[i];
        bt[i] = var2[i];
    }

    for (int i = 0; i < s; i++) {
        tat[i] = ct[i] - att[i];
        wt[i] = tat[i] - bt[i];
    }
                        if (true) {
                            cout << "COMPLETION TIME " << endl;
                            for (int i = 0; i < s; i++) {
                                cout << ct[i] << " ";
                            }
                            double awtime = 0;
                            double attime = 0;
                        //compute waiting and arrival
                            for (int i = 0; i < s; i++) {
                                tat[i] = ct[i] - att[i];
                                wt[i] = tat[i] - bt[i];
                                awtime += wt[i];
                                attime += tat[i];
                            }
                            cout << endl;
                            cout << "AVG waiting TIME" << endl;
                            cout << awtime  + 1/ double (s) << endl;
                            cout << "AVG total time " << endl;
                            cout << attime + 1/ double (s) << endl;
                        }

                    }
                break;
                }
            }
    }

    return 0;
}

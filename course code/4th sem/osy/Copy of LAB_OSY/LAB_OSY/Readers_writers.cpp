#include <iostream>
#include <vector>

using namespace std;

class variable {
    public :
        int n;
        int read_time;
        int write_time;
        int locked;
        int name;
        variable(int i) {
            locked = 1;
            name = i;
            n ++;
            locked = 0;
        }
        variable() {
            locked = 1;
            name = -1;
            n = 0;
            locked = 0;
        }
};
void remove_deadlock()
{
    cout << "removing deadlock" << endl;
}
void check_wait(int p)
{
    cout << "checking wait conditions for process " << p << endl;
}
int sum(vector<variable > v)
{
    int s = 0;
    for (int i = 0; i < v.size(); i ++) {
        s = s + v[i].n;
    }
    return s;
}
void check_deadlock_condition(int k)
{
    cout << "Checking deadlock condition : " << endl;
}
void remove_lock(int k)
{
    cout << "removing lock for variable " << k << endl;
}
int main()
{
    int n, k;
    int r;
    vector<variable> v(100);
    int read_time = 3; // milli_seconds
    int write_time = 4; // milli_seconds

    while (1) {
        cout << "1. only Readers\t2. only Writers\t 3. Exit \t 4.Pass unit time" << endl;
        cin >> k;
        if (k == 3) {
            return 0;
        }
        switch(k) {
            case 1: cout << "enter no of reader processes : " << endl;
                    cin >> r;
                    for (int i = 0; i < r; i ++) {
                        cout << "Enter variable number: ( < 100) :";
                        cin >> k;
                        check_deadlock_condition(k);
                        if (v[k].locked == 0 || v[k].locked == 2)  {
                            v[k].locked = 2;
                            v[k].read_time = read_time;
                            cout << "reading : " << k << endl;
                        } else {
                            cout << "variable : " << k << " : locked : read not permitted : " << endl;
                        }
                    }
                    break;

            case 2: cout << "enter no of writers : " << endl;
                    cin >> r;
                    for (int i = 0; i < r; i ++) {
                        cout << "Enter variable numbers: ( < 100) :";
                        cin >> k;
                        check_deadlock_condition(k);
                        if (v[k].locked == 0)  {
                            v[k].locked = 1;
                            cout << "writing : " << k << endl;
                            v[k].write_time = write_time;
                        } else {
                            cout << "variable : " << k << " : locked : write not permitted : " << endl;
                        }
                    }
                    break;
            case 4: cout << "Unit time Passed" << endl << endl;
            default: break;
        }
        for (int i = 0; i < 100; i ++) {
            if (v[i].write_time != 0) {
                v[i].write_time --;
            } else {
                continue;
            }
            if (v[i].write_time == 0) {
                    cout << "write_lock : ";
                    v[i].locked = 0;
            }
        }
        for (int i = 0; i < 100; i ++) {
            if (v[i].read_time != 0) {
                v[i].read_time --;
            } else {
                continue;
            }
            if (v[i].read_time == 0) {
                cout << "read_lock : ";
                v[i].locked = 0;
                remove_lock(i);
            }
        }
    }
    return 0;
}

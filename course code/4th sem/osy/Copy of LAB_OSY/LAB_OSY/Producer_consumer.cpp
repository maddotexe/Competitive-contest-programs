#include <iostream>
#include <vector>

using namespace std;

class process {
    public :
        int n;
        bool locked;
        int name;
        process(int i) {
            locked = 1;
            name = i;
            n ++;
            locked = 0;
        }
        process() {
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
int sum(vector<process > v)
{
    int s = 0;
    for (int i = 0; i < v.size(); i ++) {
        s = s + v[i].n;
    }
    return s;
}
int main()
{
    int n, k;
    vector<process> v(100);

    cout << "Enter size: ";
    cin >> n;

    while (1) {
        cout << "1. Producer\t2. Consumer\t3. Exit\t any other. Time pass\n";
        cin >> k;
        if (k == 3) {
            return 0;
        }
        switch(k) {
            case 1: if (sum(v) == 0) {
						cout << "Producer now awake " << endl;
						cout << "Consumer now awake " << endl;
					}
					if (sum(v) < n) {
                        cout << "Enter process number: ( < 100) :";
                        cin >> k;
                        v[k].n ++;
                        if (sum(v) == n) {
							cout << "producer now sleeping" << endl;
						}
                    } else {
                        cout << "Overflow\n";
                        cout << "removing error : enter again " << endl;
                    }
                    
                    break;

            case 2: if (sum(v) == 0) {
                        cout << "Underflow\n";
                        cout << "consumer is sleeping" << endl;
                    } else {
                        cout  << "Enter process whose resource required" << endl;
                        cin >> k;
                        if (v[k].n == 0) {
                            check_wait(k);
                            cout << "underflow for resources of process (won't let wait here) : " << k << endl;
                        } else {
                            v[k].n --;
                        }
                        if (sum(v) == n) {
                            cout << "It's a deadlock : " << endl;
                            remove_deadlock();
                        }
                        if (sum(v) == 0) {
	//                        cout << "Underflow\n";
                        	cout << "consumer now sleeping" << endl;
                    	}
                    }
                    break;
            default: break;
        }
    }
    return 0;
}

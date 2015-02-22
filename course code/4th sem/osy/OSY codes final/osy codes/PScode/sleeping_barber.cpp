#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int EMPTY(int a[], int n)
{
    for (int i = 0; i < n; i++) {
	if (a[i] > 0) {
		return 0;
	}
    }
    return 1;
}

class slept
{
    public:
    	bool sleep;
    	bool awake;
};

int main()
{
    int n;
    cin >> n;
    slept sa;
    sa.awake = false;
    sa.sleep = true;
    vector<int> lst;
    int s = 5;

    int customer[10];
    int hair[10] = {1, 3, 1, 4, 6, 4, 7, 8, 3, 9};
    int m = 10;
    for ( ; ; ) {
        if (EMPTY(hair, n) == 1) {
            break;
        }

        int cust = rand() % 6;
if (cust < 5) {
        if (hair[cust] != 0) {
            if (lst.size() <= 4) {
                lst.push_back(cust);
                if (lst.size() == 1) {
                    cout << "customer           " << cust << " WAKES barber " << endl;
                    sa.awake = true;
                    sa.sleep = ! sa.awake;
                }
            }
        }
        }
        if (! lst.empty()) {
            int doit = lst[0];
            hair[doit]--;
	    if (hair[doit] <= 0) {
		lst.erase(lst.begin());
	    }
            cout << "customer           " << doit << " is getting haircut " << endl;
	    cout << (int) lst.size() - 1 << " customers are sitting " << endl;
        }
        if (lst.empty()) {
            if (! sa.sleep) {
                    cout << endl << "barber is SLEEPING " << endl;
                    sa.sleep = true;
                    sa.awake = false;
            }
        }
    }

    return 0;
}

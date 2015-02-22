#include <iostream>
#include <cstdlib>

using namespace std;

int emp(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            return 0;
        }
    }
    return 1;
}

void think(int emp[], int t[], int n)
{
    cout << endl;
    for (int i = 0; i < n; i++) {
        if (t[i] == 0 || t[(i + 1) % n] == 0) {
            cout << " " << i << " THINKING " << endl;
        }
    }
    cout << endl;
}

int main()
{
    int n = 5;
    int philosopher[5];
    int take_fork[5];
    for (int i = 0; i < 5; i++) {
        take_fork[i] = 0;
    }

    int fork[5];
    int caneat[5];
    for (int i = 0; i < n; i++) {
        caneat[i] = 0;
    }
    int eat[5] = {4, 5, 3, 1, 2};
    int k = 0;
    int m = 0;
	if (m == 3) {
    while (1) {
        if (emp(eat, n) == 1) {
            break;
        }
        if (take_fork[k] == 0 && eat[k] > 0) {
            take_fork[k] = 1;
        }
        if (take_fork[(k + 1) % n] == 0 && eat[k] > 0) {
            take_fork[(k + 1) % n] = 1;
        } else {
            take_fork[k] = 0;
        }

        if (eat[k] > 0 && take_fork[k] == 1 && take_fork[(k + 1) % n] == 1) {
            --eat[k];	    
            cout << " " << k << " EATING " << endl;
        }
	cout << k << " : left the fork " << endl;
        
        think(eat, take_fork, n);

        if (eat[k] == 0) {
            take_fork[k] = 0;
            take_fork[(k + 1) % n] = 0;
        }
        k = (k + 1) % n;
    }
}

	cout << "enter PHILOSOPHER 1" << endl;
	
//	int n;
	cin >> n;
	cout << "enter PHILOSOPHER 2" << endl;
//	int m;
	cin >> m;
	
	if (m > n) {
		if (n == 0) {
			if (m == 4) {
				cout << "they can't eat together" << endl;
				return 0;
			}
		}
	
		if (m - n > 1) {
			cout << "they can eat together" << endl;
			return 0;
		}
	} else {
		if (m == 0) {
			if (n == 4) {
				cout << "they can't eat together " << endl;
				return 0;
			}
		}
		if (n - m > 1) {
			cout << "they can eat together " << endl;
			return 0;
		}
	}
	cout << "they can't eat together" << endl;
	
 int xx; cin >> xx;
    return 0;
}

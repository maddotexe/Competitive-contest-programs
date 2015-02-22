#include <iostream>

using namespace std;

int main()
{
    cout << "PROCESS" << endl;
    int pr;
    cin >> pr;
    cout << "ADJACENCY MATRIX" << endl;
    int a[pr][pr];
    int k = 0;
    for  (int i = 0; i < pr; i++) {
        for (int j = 0; j < pr; j++) {
            cin >> a[i][j];
        }
    }

    bool b = false;

    for (int i = 0; i < pr; i++) {
        for (int j = 0; j < pr; j++) {
            if (i != j) {
                int l = i;
                int k = j;
                if (a[i][j] == 1) {
                    if (a[j][i] == 1) {
                        b = true;
                    } else {
                        for (int m = 0; m < pr; m++) {
                            if (a[k][m] == 1) {
                                if (m == l) {
                                    b = true;
                                }
                                k = m;
                            }
                        }

                    }
                }

            }

        }

    }

    if (b == true) {
        cout << "DEADLOCK" << endl;
    } else {
        cout << "NO DEADLOCK" << endl;
    }


    return 0;
}

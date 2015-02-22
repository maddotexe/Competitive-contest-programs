#include <iostream>

using namespace std;

int swap(int &a, int &b)
{
        int temp = a;
        a = b;
        b = temp;
}

int main()
{
    int n;
    cin >> n;
    int a[n][6];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (a[j - 1][1] > a[j - 1][1]) {
                swap(a[j - 1][1], a[j][1]);
                swap(a[j - 1][2], a[j][2]);
                swap(a[j - 1][0], a[j][0]);
            }
        }
    }

    a[0][3] = a[0][2];

    for (int i = 1; i < n; i++) {
        a[i][3] = a[i - 1][3] + a[i][2];
    }

    for (int i = 0; i < n; i++) {
        a[i][4] = a[i][3] - a[i][1];
        a[i][5] = a[i][4] - a[i][2];
    }

    double wt = 0;
    double tat =  0;

    for (int i = 0; i < n; i++) {
        wt += a[i][5];
        tat += a[i][4];
    }



    cout << "w.t   =  " << wt / n << endl;
    cout << "t.a.t =  " << tat / n << endl;

    return 0;
}

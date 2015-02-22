#include <iostream>

using namespace std;

int max(int a[], int n)
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
    cin >> n;
    int pn[n];
    int wt[n];
    int tat[n];
    int bt[n];
    int at[n];
    int ct[n];
    for (int i = 0; i < n; i++) {
        cin >> pn[i] >> at[i] >> bt[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (at[j - 1] > at[j]) {
                swap(at[j - 1], at[j]);
                swap(bt[j - 1], bt[j]);
                swap(pn[j - 1], pn[j]);
            }
        }
    }

    int maxat = max(at, n);
    int flag = 0;
    int s = 0;
    do {
        if (flag == 0) {
            flag++;
            ct[s] = bt[s] + at[s];
        } else {
            ct[s] = bt[s] + ct[s - 1];
        }
    } while (maxat > ct[s - 1]);
    s++;
    for (int i = 0; i < n; i++) {
        for (int j = s + 1; j < n; j++) {
            if (bt[j - 1] > bt[j]) {
                swap(bt[j - 1], bt[j]);
                swap(at[j - 1], at[j]);
                swap(pn[j - 1], pn[j]);
            }
        }
    }

    for (int i = s; i < n; i++) {
        ct[i] = bt[i] + ct[i - 1];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    double wtime = 0;
    double ttime = 0;

    for (int i = 0; i < n; i++) {
        wtime += wt[i];
        ttime += tat[i];
    }

    cout << "avg total time " << ttime / n << endl;
    cout << "avg waiting time " << wtime / n << endl;

    return 0;
}

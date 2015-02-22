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

int max(int a[], int n, int t)
{
    int m = t;
    for (int i = n; i < t; i++) {
        if (m < a[i]) {
            return i - 1;
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

void sort(int pt[], int bt[], int att[], int pn[], int s, int e)
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

int main()
{
    int n;
    cin >> n;
    int pn[n];
    int wt[n];
    int tat[n];
    int bt[n];
    int att[n];
    int ct[n];
    int pt[n];
    for (int i = 0; i < n; i++) {
        cin >> pn[i] >> pt[i] >> att[i] >> bt[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (att[j - 1] > att[j]) {
                swap(att[j - 1], att[j]);
                swap(bt[j - 1], bt[j]);
                swap(pn[j - 1], pn[j]);
            }
        }
    }

    int maxat = max(att, n);
    int flag = 0;
    int s = 0;
    do {
        if (flag == 0) {
            flag++;
            ct[s] = bt[s] + att[s];
            s++;
        } else {
            int prev;
            prev = max(att, s, n);
            sort(pt, bt, att, pn, s, prev + 1);
            sort(pt, bt, att, pn, s, n);

            ct[s] = bt[s] + ct[s - 1];
            s++;
        }
    } while (maxat >= ct[s - 1]);

    for (int i = s; i < n; i++) {
        for (int j = s + 1; j < n; j++) {
            if (pt[j - 1] < pt[j]) {
                swap(bt[j - 1], bt[j]);
                swap(att[j - 1], att[j]);
                swap(pt[j - 1], pt[j]);
                swap(pn[j - 1], pn[j]);
            }
        }
    }

    for (int i = s; i < n; i++) {
        ct[i] = bt[i] + ct[i - 1];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - att[i];
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

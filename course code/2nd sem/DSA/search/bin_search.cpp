#include <iostream>
#include <cstdlib>
#include <algorithm>

#define MAX 10

using namespace std;

void prt_arr(int a[], int max)
{
    for (int i = 0; i < max; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void bin_search(int a[], int left, int right, int x)
{
    if (right < left) {
        cout << "   Not found " << x << endl;
        return;
    }

    int mid = (left + right) / 2;

    if (a[mid] == x) {
        cout << "   Found " << x << endl;
        return;
    }

    if (a[mid] > x) {
        cout << "      Going left of " << a[mid] << endl;
        bin_search(a, left, mid - 1, x);
    } else {
        cout << "      Going right of " << a[mid] << endl;
        bin_search(a, mid + 1, right, x);
    }
}

int main()
{
    int a[MAX];

    for (int i = 0; i < 10; i++) {
        a[i] = rand() % 1000;
    }

    sort(a, a + MAX);
    prt_arr(a, MAX);

    int tmp = 1;
    while (tmp > 0) {
        cout << "Enter no. to search: ";
        cin >> tmp;
        bin_search(a, 0, MAX-1, tmp);
    }

    return 0;
}


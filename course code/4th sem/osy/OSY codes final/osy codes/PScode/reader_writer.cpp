#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int writeArray[10];
    int readArray[10];
    int s[10] = {0, 2, 4, 2, 1, 4, 3, 4, 6, 7};
    int r[10] = {2, 5, 1, 4, 1, 2, 0, 3, 2, 1};
    int lock = 0;

    for (int i = 0; i < n; i++) {
        readArray[i] = 0;
        writeArray[i] = 0;
    }
    int l = 0;
    int sl = 0;
    int km = 0;
    for ( ; ; ) {
        km = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] <= 0) {
                km++;
            }
            if (r[i] <= 0) {
                km++;
            }
        }
        if (km == 2 * n) {
            break;
        }
        int m = rand() % 5;
        int n = rand() % 5;
        if (lock == 0) {
            readArray[n] = 1;
            if (r[n] > 0) {
                r[n]--;
                cout << " PROCESS -> " <<  n << " : READ " << endl;
            }
        }
        if (lock == 0 && readArray[m] == 1 && s[m] > 0) {
            if (s[m] != 0) {
                writeArray[m] = 1;
                lock = 1;
                l = m;
                for (int i = 0; i < n; i++) {
                    readArray[i] = 0;
                }
            }
        }

        if (s[l] != 0) {
            s[l]--;
            cout << " PROCESS -> " << l << " : WRITE " << endl;
            if (s[l] == 0) {
                lock = 0;
		cout << "lock released by " << l << endl;
            }
        }
    }

    return 0;
}

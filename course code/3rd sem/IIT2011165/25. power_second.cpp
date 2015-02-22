#include <iostream>
#include <cmath>

using namespace std;

int main()
{
        double a[100][100];
        double inverse[100][100];
        cout << "enter dimension" << endl;
        int n;
        cin >> n;

        cout << "enter enteries" << endl;

        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        cin >> a[i][j];
                }
        }

        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        if (i == j) {
                                inverse[i][j] = 1;
                        } else {
                                inverse[i][j] = 0;
                        }
                }
        }

       for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                        double value = (-1) * a[j][i] / a[i][i];
                        for (int k = i; k < n; k++) {
                                a[j][k] = a[j][k] + value * a[i][k];
                                 inverse[j][k] = inverse[j][k] + value * inverse[i][k];

                        }

                }
       }

        for (int i = n - 1; i >= 0; i--) {
                for (int j = i - 1; j >= 0; j--) {
                        double value = (-1) * a[j][i] / a[i][i];
                        for (int k = i; k < n; k++) {
                                a[j][k] = a[j][k] + value * a[i][k];
                                inverse[j][k] = inverse[j][k] + value * inverse[i][k];

                        }
                }
        }

        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        if (fabs(a[i][j]) < 0.001) {
                                a[i][j] = 0;
                        }
                        cout << a[i][j] << "   ";
                }
                cout << endl;
        }

        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        inverse[i][j] = inverse[i][j] / a[i][i];
                }
        }

        cout << "    INVERSE MATRIX " << endl;
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        cout << inverse[i][j] << "  ";
                }
                cout << endl;
        }
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        a[i][j] = inverse[i][j];
                }
        }

        cout << "enter x matrix" << endl;

        double x[100];
        double b[100];

        for (int i = 0; i < n; i++) {
                cin >> x[i];
        }

        for (int i = 0; i < n; i++) {
                b[i] = 0;
        }

        int counter = 0;
        double y1;
        double y2;
        double sum;
        double max;

        while (1) {
                for (int i = 0; i < n; i++) {
                        sum = 0;
                        for (int j = 0; j < n; j++) {
                                sum += a[i][j] * x[j];
                        }
                        b[i] = sum;
                }

                max = 0;

                for (int i = 0; i < n; i++) {
                        if (b[i] > max) {
                                max = b[i];
                        }
                }

                y2 = max;

                for (int i = 0; i < n; i++) {
                        x[i] = b[i] / max;
                }

                if (counter != 0) {
                   if (fabs(y1 - y2) < 0.00001) {
                           cout << "the eigen value is    " << 1 / y1 << endl;
                           return 0;
                   }
                }
                counter++;
                y1 = y2;
        }

        return 0;
}



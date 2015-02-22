#include <iostream>

using namespace std;

double mod(double x)
{
        if (x < 0) {
                return -x;
        }

        return x;
}

int main()
{
        int n;
        //enter dimension
        cout << "enter dimension" << endl;
        cin >> n;
        double inverse[100][100];
        double a[100][100];
        //enteries of data
        cout << "enter enteries" << endl;

        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        cin >> a[i][j];
                }
        }

        //using jordan-inverse
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
                        if (mod(a[i][j]) < 0.001) {
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
        //inverse matrix
        cout << "    INVERSE MATRIX " << endl;
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        cout << inverse[i][j] << "  ";
                }
                cout << endl;
        }
        return 0;
}

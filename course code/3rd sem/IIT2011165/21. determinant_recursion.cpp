#include <iostream>
#include <cmath>

using namespace std;

//Printing the matrix
void print_matrix(int a[100][100], int n)
{
        cout << endl << "      MATRIX   " << endl;
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        cout << a[i][j] << "  ";
                }
                cout << endl;
        }
}

//finding the determinent
int det(int a[100][100], int l, int m, int n)
{
        int b[100][100];
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        b[i][j] = a[i][j];
                }
        }

        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        if (i == l || j == m) {
                                b[i][j] = -100;
                        }
                }
        }

        int c[100][100];

        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        if (b[i][j] != -100) {
                                c[i][j] = b[i][j];
                        }
                }
        }

        if (n == 3) {
                return (c[0][0] * c[1][1] - c[0][1] * c[1][0]);
        }

        n--;
        int sum = 0;
        int d = 1;

        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        sum = sum + c[i][j] * det(c, i, j, n);
                }
        }

        return sum;
}

int main()
{
        int n;
        cout << "enter dimension" << endl;
        cin >> n;

        int a[100][100];

        cout << "enter enteries" << endl;

        //taking the input
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        cin >> a[i][j];
                }
        }

        print_matrix(a, n);

        int d = 1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        sum = sum + a[i][j] * det(a, i, j, n) * d;
                        d = -d;
                }
        }
        if (n == 2) {
                sum = a[0][0] * a[1][1] - a[0][1] * a[1][0];
        }

        cout << "  DETERMINANT IS " << sum << endl;    // printing determinent

        return 0;
}

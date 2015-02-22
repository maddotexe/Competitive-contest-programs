#include <iostream>

using namespace std;
//given function
double fact(double x)
{
        double i = 1;
        double t = 1;
        while (i <= x) {
                t = t * i;
                i = i + 1;
        }

        return t;
}
//final calculations
void func(double f[100][100], double x[100], double y, int n)
{
        double sum = f[0][0];
        double s;
        double t;

        for (int i = 1; i < n; i++) {
                t = 1;
                for (int j = 0; j < i; j++) {
                        t = t * (y - x[j]);
                }

                sum = sum + t * f[0][i];
        }

        cout << "answer is " << sum << endl;
}

int main()
{
        int n;
        double x[100];
        double f[100][100];
        //enter yhe no of data sets
        cout << "enter number of data sets" << endl;
        cin >> n;
        //enteries of table
        cout << "   enter entries x : f{x)" << endl;
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        f[i][j] = 0;
                }
        }

        for (int i = 0; i < n; i++) {
                cin >> x[i] >> f[i][0];
        }

        for (int i = 1; i < n; i++) {
                for (int j = 0; j < n - i; j++) {
                        f[j][i] = (f[j+1][i-1] - f[j][i-1]) / (x[i+j] - x[j]);
                }
        }
        //table printing
        cout << "   TABLE IS " << endl;

        for (int i = 0; i < n; i++) {
                cout << x[i] << "  ";
                for (int j = 0; j < n; j++) {
                        cout << f[i][j] << "   ";
                }
                cout << endl;
        }

        cout << "enter the data point" << endl;
        double y;
        cin >> y;

        func(f, x, y, n);

        return 0;
}

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
//final calculation
void func(double f[100][100], double x[100], double y, int n)
{
        double h = x[1] - x[0];

        double p = (y - x[n-1]) / h;
        double var = p;
        double t = 1;
        double s = p;
        double m = 1;
        double sum = f[n-1][0];

        int i;
        for (int i = 1; i < n; i++) {
                sum = sum + f[n-1][i] * (s / fact(m)) ;
                var = var + 1;
                s = s * var;
                m = m + 1;
        }

        cout << "answer is " << sum << endl;
}

int main()
{
        int n;
        double x[100];
        double f[100][100];
        //no. of sets of data
        cout << "enter number of data sets" << endl;
        cin >> n;
        //enteries of data
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
                for (int j = i; j < n; j++) {
                        f[j][i] = f[j][i-1] - f[j-1][i-1];
                }
        }
        //printing table
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

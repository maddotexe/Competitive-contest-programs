#include <iostream>

using namespace std;

int main()
{
        double a[100][100];
        double b[100];
        double x[100];

        int n;
        //no. of equation
        cout << "enter number of equations" << endl;

        cin >> n;
        //enteries of data
        cout << "enter enteries" << endl;

        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        cin >> a[i][j];
                }
        }
        //value matrix
        cout << "enter B" << endl;

        for (int i = 0; i < n; i++) {
                cin >> b[i];
        }
        //intial value
        int t = 100;
        cout << "enter initial values " << endl;

        for (int i = 0; i < n; i++) {
                cin >> x[i];
        }

        double sum = 0;
        double temp[100];
        //gauss-seidel
        while (t--) {
                for (int i = 0; i < n; i++) {
                        sum = 0;
                        for (int j = 0; j < n; j++) {
                                if (i != j) {
                                        sum = sum + x[j] * a[i][j];
                                }
                        }
                        x[i] = (b[i] - sum) / a[i][i];
                }
        }
        //output
        cout << "the solution is " << endl;
        for (int i = 0; i < n; i++) {
                cout << "x[" << i + 1 << "]" << " = " << x[i] << endl;
        }

        return 0;
}


#include <iostream>

using namespace std;

int main()
{
        int n;
        //enter the no. of data sets
        cout << "enter number of data sets " << endl;

        cin >> n;

        double x[100];
        double f[100];
        //enteries of sets
        cout << "enter x : f(x) " << endl;

        for (int i = 0; i < n; i++) {
                cin >> x[i] >> f[i];
        }

        cout << endl << "x : f(x)" << endl;

        for (int i = 0; i < n; i++) {
                cout << x[i] << "     " << f[i] << endl;
        }
        //enter the point
        cout << "enter the point where you want to find the value " << endl;
        double y;
        cin >> y;
        double sum = 0;
        double t = 1;
        //lagrange calculation
        for (int i = 0; i < n; i++) {
                t = 1;
                for (int j = 0; j < n; j++) {
                        if (i != j) {
                                t = t * (y - x[j]) / (x[i] - x[j]);
                        }

                }

                sum = sum + t * f[i];
        }
        //output
        cout << "the output is " << endl;
        cout << sum << endl;

        return 0;
}

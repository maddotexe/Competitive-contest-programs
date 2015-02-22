//Finding determinent through upper triangular matrix method

#include <iostream>

using namespace std;

int main()
{
        int n;
        cout << "enter dimension " << endl;
        cin >> n;
        double a[100][100];

        cout << "enter enteries" << endl;

        //taking the input
        
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        cin >> a[i][j];
                }
        }

        for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                        int value = (-1) * a[j][i] / a[i][i];
                        for (int k = i; k < n; k++) {
                                a[j][k] = a[j][k] + value * a[i][k];
                        }
                }
        }

        cout << "the determinant is " << endl;

        double det = 1;
        for (int i = 0; i < n; i++) {
                det = det * a[i][i];
        }

        cout << det << endl; // printing determinent
}

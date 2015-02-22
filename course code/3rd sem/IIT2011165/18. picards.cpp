#include <iostream>
#include <cmath>

using namespace std;

int main()
{
        double x0;
        double y0;
        double f[1000];

        double n;
        x0 = 0;
        y0 = 1;

        n = 1;
        f[0] = 1;
        f[1] = 1;
        double iter;
        //input
        
        cin >> iter;
        int m;
        //using picard
        for (double i = 1; i <= iter; i = i + 1) {
                for (double j = n + 1; j >= 1; j = j - 1) {
                        m = j;
                        f[m] = f[m-1] / j;
                }
                n = n + 1;
                f[0] = 1;
        }
        //output
        for (int k = 0; k <= n; k = k + 1) {
                cout << f[k] << " " << "x ^" << k << "   ";
        }

        return 0;
}

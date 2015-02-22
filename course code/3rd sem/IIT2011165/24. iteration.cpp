#include <iostream>
#include <cmath>

using namespace std;

double mod(double x)
{
        if (x < 0) {
                return -x;
        } else {
                return x;
        }
}

double gx(double x)
{
        return (1 / sqrt(x + 1));
}

double gdx(double x)
{
        return (-1 / (pow((x+1), 1.5)));
}

int main()
{
        cout << "the function is x^3 + x ^2 - 1" << endl;
        cout << "enter x " << endl;
        double x;
        cin >> x;

        double y;

        if (mod(gdx(x)) > 1) {
                cout << "derivative is greater than 1 at this place" << endl;
        }

        while (1) {
                y = gx(x);

                if (mod(y - x) < 0.00001) {
                        break;
                }

                x = y;
        }

        cout << "the root is " << x << endl;

        return 0;
}

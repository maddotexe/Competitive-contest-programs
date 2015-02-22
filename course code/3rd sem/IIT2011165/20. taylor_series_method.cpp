#include <iostream>
#include <cmath>

using namespace std;

double fact(double a)
{
        double i = 1;
        while (a) {
                i = i * a;
                a = a - 1;
        }

        return i;
}

int main()
{
        double f;
        double x;
        double x0;
        double y0;
        //input
        cout << "enter x0 and y0" << endl;
        cin >> x0 >> y0;
        cout << "enter the point at which you want to find the value" << endl;
        cin >> x;
        //no. of iteartion
        cout << "enter number of iterations" << endl;
        int iter;
        cin >> iter;
        double y = y0;
        int counter = 0;
        //using taylor series
        while (1) {
                if (counter == 0) {
                        y += (x - x0) * (x0 + y0);
                        counter++;
                } else if (counter == 1) {
                        y += pow((x - x0), 2) * (x0 + y0 + 1) / fact(counter+1);
                        counter++;
                } else if (counter > 1) {
                        y += pow((x-x0), counter + 1) * (x0 + y0 + 1) / fact(counter+1);
                        counter++;
                }

                if (counter == iter) {
                        break;
                }
        }
        //solution
        cout << " the solution is " << y << endl;

        return 0;
}

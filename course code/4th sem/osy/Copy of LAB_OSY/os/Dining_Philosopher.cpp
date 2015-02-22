#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;
int n = 6;
vector<int> assigned;
int cnt = 0;

int check(int a, int b)
{
    if (cnt < (n - 2)) {
        if ((b - a) == 1 || (b - a) == (n - 1)) {
            cout << a << " And " << b << " can't eat together" << endl << endl;
            return -1;
        } else {
            cnt++;
            cout << "Round " << cnt << endl;
            cout << a << " And " << b << " eating " << endl << endl;

            if (a == n - 1)
                a = 0;
            else
                a = a + 1;

            if (b == n - 1)
                b = 0;
            else
                b = b + 1;

            check(a, b);
        }
    }

    return 0;
}

int main()
{
    int a;
    int b;

    here :
    cout << "Enter The Two Eating philosopher : ";
    cin >> a >> b;

    int k = check(a, b);

    if (k == -1)
        goto here;

}

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <ctime>

using namespace std;

queue<int> q;

int barber()
{
    if (q.size() == 0) {
        cout << "Barber Sleeping" << endl << endl;
    } else {
        q.pop();
        cout << "Barber Cutting Hair And Customers Waiting = " << q.size() << endl << endl;
    }

    return 0;
}

int customer()
{
    if (q.size() < 5 && q.size() > 0) {
        q.push(1);
        cout << "Customer goes to waiting room" << endl << endl;
    } else if (q.size() == 5) {
        cout << "Customer leaves because no space" << endl << endl;
    } else if (q.size() == 0) {
        q.push(1);
        cout << "Customer Wakes up barber And have hair cut" << endl << endl;
    }

}

int main()
{
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        int p = (rand() % 2) + 1;

        if (p == 1) {
            barber();
        } else {
            customer();
        }
    }

}

#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>

using namespace std;

queue<int> q;
int max_size;

void produce()
{
    if (q.size() == max_size) {
        cout << "Production Blocked" << endl << endl;
    } else {
        q.push(q.size() + 1);
        cout << "1 unit has been produced : Total Availability : " << q.size() << endl << endl;
    }
}

void consume()
{
    if (q.size() == 0) {
        cout << "Consumption Blocked" << endl << endl;
    } else {
        q.pop();
        cout << "1 unit has been consumed : Total Availability : " << q.size() << endl << endl;
    }

}

int main()
{
    int ch;
    cout << "Enter The Maximum Size : ";
    cin >> max_size;

    /*while (1) {
        cout << "1. Produce \n2. Consume \n3. Exit \nEnter Your Choice : ";
        cin >> ch;

        switch(ch)
        {
            case 1 : produce();
                     break;
            case 2 : consume();
                     break;
            case 3 : return 0;
                     break;
            default : cout << "Wrong Entry\n";
        }
    }*/

    for (int i = 0; i < 20; i++) {
        int p = (rand() % 2) + 1;

        switch(p)
        {
            case 1 : produce();
                     break;
            case 2 : consume();
                     break;
        }
    }

    return 0;
}

#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

queue<int> q;
int max_size;

int produce()
{
    if (q.size() == max_size) {
        cout << "Production Blocked  :  ";
        return 99;
    } else {
        q.push(q.size() + 1);
        cout << "1 unit has been produced : Total Availability : " << q.size() << endl << endl;
    }

    return 0;
}

int consume()
{
    if (q.size() == 0) {
        cout << "Consumption Blocked  :  ";
        return 100;
    } else {
        q.pop();
        cout << "1 unit has been consumed : Total Availability : " << q.size() << endl << endl;
    }

    return 0;
}

int main()
{
    int ch;
    int k;
    cout << "Enter The Maximum Size : ";
    cin >> max_size;

    srand(time(NULL));
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
        int p;

        if (k == 99) {
            cout << "Producer Sleeping\n\n";
            p = 2;
        } else if (k == 100) {
            cout << "Consumer Sleeping\n\n";
            p = 1;
        } else {
            p = (rand() % 2) + 1;
        }

        switch(p)
        {
            case 1 : k = produce();
                     break;
            case 2 : k = consume();
                     break;
        }
    }
	getchar();
	getchar();
    return 0;
}

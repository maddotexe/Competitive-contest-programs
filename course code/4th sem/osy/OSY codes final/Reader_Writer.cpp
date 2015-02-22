#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <ctime>

using namespace std;
map<int, int> m;

void initialise()
{
    m.insert(pair<int, int> (1, 0));
    m.insert(pair<int, int> (2, 0));
    m.insert(pair<int, int> (3, 0));
}

void read(int i)
{
    if (m[i] >= 0) {
        cout << "\nRead Lock - File " << i;
        m[i]++;
    } else {
        cout << "\nRead Lock Not Assigned - File " << i;
    }
}

void write(int i)
{
    if (m[i] == 0) {
        cout << "\nWrite Lock - File " << i;
        m[i] = -1;
    } else {
        cout << "\nWrite Lock Not Assigned - File " << i;
    }
}

void unlock_read(int i)
{
    if (m[i] > 0) {
        cout << "\n1 Read Lock released For File " << i;
        m[i]--;
    }
}

void unlock_write(int i)
{
    if (m[i] == -1) {
        cout << "\nWrite Lock relesed For File " << i;
        m[i] = 0;
    }
}

int main()
{

    int k;
    int l;

    cout << "There are 3 files : F1, F2, F3\n";
    initialise();

    srand(time(NULL));
    for (int i = 0; i < 30; i++) {
        int p = (rand() % 100);

        if (p >= 0 && p < 25) p = 1;
        else if (p >= 25 && p < 50) p = 2;
        else if (p >= 50 && p < 75) p = 3;
        else p = 4;

        switch(p) {
            case 1 : k = (rand() % 3) + 1;
                     read(k);
                     break;
            case 2 : l = (rand() % 3) + 1;
                     write(l);
                     break;
            case 3 : k = (rand() % 3) + 1;
                     unlock_read(k);
                     break;
            case 4 : l = (rand() % 3) + 1;
                     unlock_write(l);
                     break;
        }
    }

    return 0;
}

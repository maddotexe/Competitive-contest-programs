#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    set <int > s;
    s.insert(20);
    s.insert(30);
    set <int>::iterator it;
    it = s.begin();
    cout << max(*it, *(++it));
    getchar();
    getchar();
    return 0;
}

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

bool operator()(const pair<int, int>& l, const pair<int,int>& r)
{
     return l.first > r.first;
     return false;
}

int main()
{
    map<int, int> m;
    map<int, int>::iterator it;
   // pair<int, int>:: pair_type value_type;
    m[1] = 2;
    m[4]= 9;
    it = m.begin();
    cout << *max_element(m.begin(), m.end());
    getchar();
    getchar();
    return 0;
}

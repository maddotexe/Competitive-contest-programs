#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    
    cout << v[0] << " " << v[1] << endl;
    cout << "max : "<< max(v[1], v[0]);
    
    int a;
    cin >> a;
    return 0;
}

    

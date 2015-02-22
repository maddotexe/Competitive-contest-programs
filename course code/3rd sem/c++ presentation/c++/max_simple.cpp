#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool mycmp(int a1, int a2)
{
    if (a2 > a1) {
        return false;
    }
    else {
        return true;
    }
}

int main()
{
    
    cout << "The numbers in which we are searching for max\n" << 0 << " " << 2 << endl;
    cout << "\n\n\The max without predicate : " << max(0, 2) << endl;
    cout  << "\nThe max using predicate : " << max(0, 2, mycmp) << endl;
    
    int a;
    cin >> a;
    return 0;
}

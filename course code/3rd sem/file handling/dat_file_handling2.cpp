#include <sstream>
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main() 
{
    int x;
    int f = 0;
    string s1;
    int i = 0;
    cin >> x;
    ostringstream s;
    s << hex << x;
    s1 = s.str();
    while(i < s1.size()) 
    {
          if((s1[i] >= 65 && s1[i] <= 90) || (s1[i] >= 97 && s1[i] <= 122)) {
                    f = 1;
                    break;
          }
          i++;
    }
    if(f) {
          cout << "contains letter\n";
    }
    else {
          cout << "no letters\n";
    }
    getchar();
    getchar();
    return 0;
}

    
    

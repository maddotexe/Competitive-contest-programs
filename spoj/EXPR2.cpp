#include <iostream>
using namespace std;
main(int c, int a, char o, int b){
    if(cin >> c)
            while(c--)
                if(cin >>a>>o>>b)
                	if(cout << ((o==43)?a+b:(o>44)?a-b:a*b) << "\n"){}
}


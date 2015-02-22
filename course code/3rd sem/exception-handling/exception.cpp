#include <cstdio>
#include <exception>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    fstream fp;
    char c;
    string s;
    try {
        
        fp.open("input.txt");
        //fp = fopen("input.txt", "r");
        if(fp.fail())
                     throw exception() ;
        } catch (exception& e) {
                printf("unable to open");
        }
        while(!fp.eof())
        {
                   fp.get(c);
                   if(c >= 97 && c <= 122) {
                        c = c - 32;
                        cout << c;
                   } else {
                          cout << c;
                   }
        } 
        fp.close();
        getchar();
        getchar();
        return 0;
}

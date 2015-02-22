#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdio>
using namespace std;

struct roo {
       int n;
       float x;
};
int main()
{
    int i;
    ofstream fp;
    fp.open("numbers.dat" , ios::binary);
    roo ob;
    for( i = 0; i++ <10; ) {
         ob.n = i;
         ob.x = sqrt(i);
         fp.write((char *)&ob, sizeof(ob));
    }
    fp.close();
    ifstream fp1;
    fp1.open("numbers.dat", ios::binary);
    fp1.read((char *)&ob, sizeof(ob));
    while(!fp1.eof()) {
               
               cout << ob.n << " " << ob.x << endl;
               fp1.read((char *)&ob, sizeof(ob));
    }
    fp1.close();
    getchar();
    getchar();
    return 0;
}
    

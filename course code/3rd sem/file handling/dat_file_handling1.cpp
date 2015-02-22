#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct student {
       char s[10];
       int n;
};

int main() {
    student ob, ob_max, ob_min;
    /*ofstream fp;
    int i;
    fp.open("student1.dat" , ios::binary);
    for( i = 0; i < 5; i++) {
         cin >> ob.s;
         cin >> ob.n;
         fp.write((char *)&ob, sizeof(ob));
    }
    fp.close();*/
    ifstream fp1;
    int min;
    int max,sum ,t;
    fp1.open("student1.dat", ios::binary);
    fp1.read((char *)&ob, sizeof(ob));
    max = min = ob.n;
    sum = 0;
    t=0;
    while (!fp1.eof()) {
          sum += ob.n;
          if(ob.n != 0) {
                  t++;
          }
          if(min > ob.n) {
                 min = ob.n;
                 ob_min = (ob);
          }
          if( max < ob.n) {
              max = ob.n;
              ob_max = ob;
          }
          fp1.read((char *)&ob, sizeof(ob));
    }
    
    cout << "the minimum marks is of : " << ob_min.s << " and he obtained : " << min << endl;
    cout << "the minimum marks is of : " << ob_max.s << " and he obtained : " << max << endl;
    cout << "mean : " << (float)sum/(float)t << endl;;
    fp1.close();
    getchar();
    getchar();
    return 0;
}

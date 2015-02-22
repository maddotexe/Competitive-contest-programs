#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string a, b;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int l1, l2;
    int ins = 4;
    int del = 5;
    int rep = 8;
    
    cin >> a >> b;
    l1 = a.size();
    l2 = b.size();
    string s1, s2;
    
    int x[l1 + 1][l2 + 1];
    int path[l1 + 1][l2 + 1];
    
    for (int i = 0; i <= l1; i++) {
        x[i][0] = i * del;
        path[i][0] = -1;
    }
    for (int i = 0; i <= l2; i++) {
        x[0][i] = i * ins;
        path[0][i] = 1;
    }
    
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            x[i][j] = x[i - 1][j - 1] + rep * (a[i - 1] != b[j - 1]);
            path[i][j] = 0;
            if (x[i - 1][j] + del < x[i][j]) {
               x[i][j] = x[i - 1][j] + del;
               path[i][j] = -1;
            }
            if (x[i][j - 1] + ins < x[i][j]) {
               x[i][j] = x[i][j - 1] + ins;
               path[i][j] = 1;
            }
        }
    }
    
    for (int i = 0; i <= l1; i++) {
        for (int j = 0; j <= l2; j++) {
            cout << x[i][j] << "  ";
        }
        cout << endl;
    }
    
    cout << x[l1][l2] << endl;
    
    while (l1 || l2) {
          if (path[l1][l2] == 0) {
             s1 = a[l1 - 1] + s1;
             s2 = b[l2 - 1] + s2;
             l1--;
             l2--;
          } else if (path[l1][l2] == 1) {
             s1 = ' ' + s1;
             s2 = b[l2 - 1] + s2;
             l2--;
          } else {
             s1 = a[l1 - 1] + s1;
             s2 = ' ' + s2;
             l1--;
          }
    }
    
    cout << s1 << endl << s2 << endl;
    //cin  >> a;

    return 0;
}

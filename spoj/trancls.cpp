#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

inline void fastRead(int *a)
{
  register char c=0;
  while (c<33) c=getchar_unlocked();
  *a=0;
  while (c>33)
    {
      *a=*a*10+c-'0';
      c=getchar_unlocked();
    }
}

int main() {
    
	int a[101][101];
    int t;
    int n, k, x, y;
    scanf("%d", &t);
    
    for (int y1 = 1; y1 <= t; y1++) {
        memset(a, 0, sizeof(a));
        fastRead(&n);
        int c = 0;
        for (int i = 0; i < n; i++) {
            fastRead(&x);
            fastRead(&y);
            
            a[x][y] = 1;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (a[i][j] || a) {
                        if (a[j][k]) {
                            if (!a[i][k]) {
                          i      a[i][k] = 1;
                                c++;
                            }
                        }
                    }
                    
                }
            }
        }
        cout << "Case #" << y1 << ": " << c <<endl;
    }
	return 0;

}

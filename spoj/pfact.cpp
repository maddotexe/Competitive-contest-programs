#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317};
int main()
{
    int f;
    for (int i = 2; i <= 100000; i++) {
        f = 1;
        printf("%d: ", i);
        for (int j = 0; a[j] <= i && a[j] < 317; j++) {
            if (i % a[j] == 0) {
                printf("%d ", a[j]);
                f = 0;
            }
            
        }
            if (f) {
                printf("%d ", i);
            }
            
            printf("\n");
            
        
    }
    return 0;
    
}

#include  <iostream>
#include <math.h>

using namespace std;

//given function
float f(float x, float a[], int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum = sum + (pow(x,i)) * a[i];
    }
    return sum;
}

//function derivation
float f1(int x, float a[], int size)
{
    float sum = 0;

    for (int i = 1; i < size; i++) {
        sum = sum + (i * pow(x, (i-1)))*a[i];
    }
    return sum;
}

int main()
{
    int d;
    //enter degree
    cout << "degree : " << endl;
    cin >> d;
    float a[d+1];
    //entering cofficients
    cout << "enter coefficients : " << endl;
    for (int i = d; i >= 0; i--) {
        cin >> a[i];
    }
    
    float p, q;
    cout << "enter point : " << endl;
    cin >> p;
    
    //newton-raphson calculator
    q = p - (f(p, a, d+1) / f1(p, a, d+1));
    while (q - p > .001 || p - q > .001) {
          p = q;
          q = p - (f(p, a, d+1) / f1(p, a, d+1));
    }
    //output
    cout << "ans : " << q;
    
    getchar();
    getchar();
    
    return 0;
}

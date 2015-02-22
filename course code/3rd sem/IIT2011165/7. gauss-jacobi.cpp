#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float a[3][3];
    float c[3] ,d[3];
    float b[3];
    int n ;
    //enter the degree
    cin >> n;
    //enter the coefficients
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
        c[i] = 0;
    }
    //value matrix
    cout << "enter matrix b:\n";
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    cout << endl;
    //gauss-jacobi operation
    for(int it = 0; it < 200 ;it++){
        for(int i = 0; i < n; i++){
            float s = 0;
            for(int j = 0; j < n; j++){
                s = s + a[i][j] * c[j];
            }
            c[i] = (b[i] - s + a[i][i]*c[i])/a[i][i];
        }
        for(int i = 0; i < n; i++){
            cout << c[i] <<  "  ";
        }
        cout << endl;
    }

    return 0;
}

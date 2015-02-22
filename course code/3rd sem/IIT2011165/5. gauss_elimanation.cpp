#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float a[10][10];
    float b[10];
    float c[10];
    int n;
    //enter the degree
    cout << "enter n: ";
    cin >> n;
    //enter the coefficients
    cout << "enter the coff matrix" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n ; j++){
            cin >> a[i][j];
        }
    }
    //value matrix
    cout << " enter the value matrix "<< endl;
    for(int i = 0; i < n; i++){
        cin >> b[i];
        c[i] = 0;
    }
    
    //gauss-elemination operation
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j > i){
                float ratio = a[j][i]/a[i][i];
                for(int k = 0; k < n; k++){
                    a[j][k] = a[j][k] - ratio * a[i][k];

                }
                b[j] = b[j] - ratio*b[i];
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(fabs(a[i][j]) < 0.001 ){
                a[i][j] = 0;
            }
        }
    }
    cout<< "after opeartion 1" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n + 1; j++){
            cout << a[i][j]<< " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << b[i] << endl;
    }
    cout << endl;
    // back substitution
    for(int i = n -1 ; i >= 0; i--){
        float s = 0;
        for(int k = 0; k < n; k++){
            s = s + a[i][k]*c[k];
        }
        c[i] = (b[i] - s)/a[i][i];
    }
    //output
    for(int i = 0; i < n; i++){
        cout << c[i] << " ";
    }
    cout << endl;

    return 0;
}

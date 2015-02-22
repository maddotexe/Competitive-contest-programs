#include <iostream>
#include <cmath>

using namespace std;

int n;
//print the matrix
void print(float a[][10]){
    cout << endl;
    for(int i = 0; i < n; i++){
        for(int j  = 0; j < n; j++){
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{
    float a[10][10];
    float id[10][10];
    //enter the degree
    cout << "enter n:\n";
    cin >> n;
    //enter the coefficients
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            id[i][j] = 0;
        }
        id[i][i] =1;
    }
    cout << "a = ";
    print(a);
    cout << "id = ";
    print(id);
    //gauss-jordan operation
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j){
                float ratio = a[j][i]/a[i][i];
                for(int  k = 0; k < n; k++){
                    a[j][k] = a[j][k]- ratio*a[i][k];
                    id[j][k] = id[j][k] - ratio*id[i][k];
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        float ratio = a[i][i];
        for(int j = 0; j < n; j++){
            a[i][j] = a[i][j]/ratio;
            id[i][j] = id[i][j]/ratio;
        }
    }
    //output
    cout << "a = " << endl;
    print(a);
    cout << "inverse = " << endl;
    print(id);
    return 0;
}

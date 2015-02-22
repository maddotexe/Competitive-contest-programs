#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int row;
	int col;
	//enter the size
	
	cout << "Enter the size of matrix A: ";
	cin >> row;
	col = row;
	
	int a[row][col];
	int b[col];
	//enter the matrix
    cout << "Enter the coefficients of equations:\n";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col + 1; j++) {
			if (j == col) {
				cin >> b[i];
			} else {
				cin >> a[i][j];
			}
		}
	}
	
	
	cout << "\nMatrix B:\n";
	for (int i = 0; i < col; i++) {
		cout << b[i] << endl;
	}

	double u[row][col];
	double l[row][col];
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (j < i) {
				u[i][j] = 0;
			} else if (j == i) {
				l[i][j] = 1;
			} else {
				l[i][j] = 0;
			}
		}
	}
	//using lu decomposition
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (i == j) {
				double m = 0;
				for (int k = 0; k < j; k++) {
					m += l[j][k]*u[k][j];
				}
				u[i][j] = a[i][j] - m;
			}
			
			if (i < j) {
				double m = 0;
				for (int k = 0; k < i; k++) {
					m += l[i][k]*u[k][j];
				}
				u[i][j] = a[i][j] - m;
			}
			
			if (i > j) {
				double m = 0;
				for (int k = 0; k < j; k++) {
					m += l[i][k]*u[k][j];
				}
				l[i][j] = (a[i][j] - m) / u[j][j];
			}
		}
	}
	//matrix u
	cout << "\nMatrix U:\n";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << u[i][j] << "  ";
		}
		cout << endl;
	}
	//printing matrix l
	cout << "\nMatrix L:\n";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << l[i][j] << "  ";
		}
		cout << endl;
	}
	
	double v[row];
	for (int i = 0; i < row; i++) {
		double m = 0;
		for (int j = 0; j < i; j++) {
			m += l[i][j]*v[j];
		}
		v[i] = (b[i] - m)  / l[i][i];
	}
	//back subsituting
	//matrix v
	cout << "\nMatrix V:\n";
	for (int i = 0; i < row; i++) {
		cout << v[i] << endl;
	}
	
	double x[row];
	for (int i = row-1; i >= 0; i--) {
		double m = 0;
		for (int j = row - 1; j > i; j--) {
			m += u[i][j]*x[j];
		}
		x[i] = (v[i] - m)  / u[i][i];
	}
	//matrix  x
	cout << "\nMatrix X:\n";
	for (int i = 0; i < row; i++) {
		cout << x[i] << endl;
	}
	getchar();
	getchar();
	return 0;
}

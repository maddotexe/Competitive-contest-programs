#include <iostream>
#include <cmath>

using namespace std;

void init(double a[100][100], int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
}

int main()
{
	cout << "enter the dimension of the matrix " << endl;
	int n;
	cin >> n;

	double a[100][100];

	init(a, n);
	double x[100];
	cout << "enter the initial values x" << endl;
	int i;
	int j;
	for (i = 0; i < n; i++) {
		cin >> x[i];
	}

	double y1;
	double y2;
	double b[100];

	for (i = 0; i < n; i++) {
		b[i] = 0;
	}

	int counter = 0;
	double sum;
	double max;

	while (1) {
		max = 0;
	
		for (i = 0; i < n; i++) {
			sum = 0;
			for (j = 0; j < n; j++) {
				sum = sum + x[j] * a[i][j];
			}
			b[i] = sum;
		}

		for (i = 0; i < n; i++) {
			if (b[i] > max) {
				max = b[i];
			}
		}
		for (i = 0; i < n; i++) {
			b[i] = b[i] / max;
			x[i] = b[i];
		}


		y1 = max;
		if (counter != 0) {
			if (fabs(y2 - y1) < 0.001) {
				cout << "highest eigen value is " << endl;
				cout << y1 << endl;
				break;
			}
		}

		counter++;
		y2 = y1;
	}
    	system("pause");
	return 0;
}

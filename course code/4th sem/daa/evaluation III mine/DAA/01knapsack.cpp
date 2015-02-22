#include <iostream>

using namespace std;

double estimate(double w[], double p[], double weight, int n, int index)
{
	int i;
	double tp = 0;
	double tw = 0;
	for (i = index; (i < n) && (weight >= tw + w[i]); i++) {
			tw += w[i];
			tp += p[i];
	}

	if (i < n) {
		tp += ((weight - tw)/w[i]) * p[i];
	}
	return tp;
}

void knapsack(double w[], double p[], double weight, double& curb, double curp, double curw, int n, int index)
{
	if (index == n) return;

	double e;

	for (int i = index+1; i < n; i++) {
		e = estimate(w, p, weight-curw, n, i);
		cout << " e = " << e << endl;
		if ((curb < e + curp) && (weight >= w[i] + curw)) {
			curp += p[i];
			curb = curp;
			curw += w[i];
			cout << "index = " << i << endl;
			cout << "best = " << curb  << endl;
			knapsack(w, p, weight, curb, curp, curw, n, i);
		} else return;
	}

	knapsack(w, p, weight, curb, p[index+1], w[index+1], n, index+1);
	
}

int main()
{
	int n;
	double curb, curp, curw;
	cout << "enter no. of elements: ";
	cin >> n;
	double w[n];
	double p[n];

	for (int i = 0; i < n; i++) {
		cin >> w[i] >> p[i];
	}

	cout << "enter weight of knapsack: ";
	double weight;
	cin >> weight;

	curb = 0;
	knapsack(w, p, weight, curb, p[0], w[0], n, 0);
	cout << curb << endl;
}

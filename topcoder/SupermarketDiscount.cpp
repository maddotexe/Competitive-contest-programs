#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class SupermarketDiscount {
public:
	int minAmount(vector <int>);
};

int SupermarketDiscount::minAmount(vector <int> a) {
	sort(a.begin(), a.end());
	int k = 0, sum = 0, s, c = 0;
	for (int i = 0; i < a.size() ;i++) sum += a[i];
	for (int i = a.size() - 1; i >= k; i--) {
	cout << i << endl;
		s = a[i];
		if (a[i] >= 50) {
			c++;
		} else {
			while ((s < 50) && (k < i)) {
				s += a[k];
				//cout << s << endl;
				k++;
			}
			if (s >= 50) c++;
		}
	}
	return sum - c * 10;
}


double test0() {
	int t0[] = {46, 62, 9};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SupermarketDiscount * obj = new SupermarketDiscount();
	clock_t start = clock();
	int my_answer = obj->minAmount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 97;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {50, 62, 93};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SupermarketDiscount * obj = new SupermarketDiscount();
	clock_t start = clock();
	int my_answer = obj->minAmount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 175;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {5, 31, 15};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SupermarketDiscount * obj = new SupermarketDiscount();
	clock_t start = clock();
	int my_answer = obj->minAmount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 41;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {5, 3, 15};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SupermarketDiscount * obj = new SupermarketDiscount();
	clock_t start = clock();
	int my_answer = obj->minAmount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 23;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

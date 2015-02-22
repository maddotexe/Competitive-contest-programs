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

class SlimeXSlimonadeTycoon {
public:
	int sell(vector <int>, vector <int>, int);
};

int SlimeXSlimonadeTycoon::sell(vector <int> m, vector <int> c, int s) {
	int ans = 0, k = 0;
	for (int i = 0; i < m.size(); i++) {
		if (i + 1> s) {
			m[k] = 0;
			k++;
		}
		
		for (int j = k; c[i] > 0 && j <= i; j++) {
			if (c[i] > m[j]) {
				ans += m[j];
				c[i] -= m[j];
				m[j] = 0;
			} else {
				ans += c[i];
				m[j] -= c[i];
				c[i] = 0;	
			}
		}
		cout << ans << endl;
	}
	
	return ans;
}


double test0() {
	int t0[] = {5, 1, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 2, 3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 2;
	SlimeXSlimonadeTycoon * obj = new SlimeXSlimonadeTycoon();
	clock_t start = clock();
	int my_answer = obj->sell(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {10, 20, 30};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {30, 20, 10};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 1;
	SlimeXSlimonadeTycoon * obj = new SlimeXSlimonadeTycoon();
	clock_t start = clock();
	int my_answer = obj->sell(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 40;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {1, 2, 3, 4, 5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {5, 5, 5, 5, 5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 5;
	SlimeXSlimonadeTycoon * obj = new SlimeXSlimonadeTycoon();
	clock_t start = clock();
	int my_answer = obj->sell(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 15;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {10000, 0, 0, 0, 0, 0, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 2, 4, 8, 16, 32, 64};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 4;
	SlimeXSlimonadeTycoon * obj = new SlimeXSlimonadeTycoon();
	clock_t start = clock();
	int my_answer = obj->sell(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 15;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
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

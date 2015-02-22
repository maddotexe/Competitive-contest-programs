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

class BuildingHeightsEasy {
public:
	int minimum(int, vector <int>);
};

int BuildingHeightsEasy::minimum(int m, vector <int> v) {
	int a[100]; 
	if (m == 1) return 0;
	for (int i = 0; i < 100; i++) a[i] = 0;
	
	for (int i = 0; i < v.size(); i++) {
		a[v[i]]++;
	}
	
	int ans = 9999999;
	
	for (int i = 1; i < 52; i++) {
		if (a[i] == 0) continue;
		if (a[i] >= m) {
			ans = 0;
			break;
		}
		int x = m - a[i];
		cout << x << endl;
		int t = 0, c = 0;
		for (int j = i - 1; j >= 1; j--) {
			
			if (a[j] == 0) continue;
			for (int k = 1; k <= a[j]; k++) {
				if (c < x) {
					t += i - j;
					c++;
				}
			}
		}
		cout << "t = " << t << endl;
		if (t == 0) t = 9999999;
		if (c >= x) ans = min(ans, t);
	}
	
	return ans;
}


double test0() {
	int p0 = 2;
	int t1[] = {1, 2, 1, 4, 3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	BuildingHeightsEasy * obj = new BuildingHeightsEasy();
	clock_t start = clock();
	int my_answer = obj->minimum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 3;
	int t1[] = {1, 3, 5, 2, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	BuildingHeightsEasy * obj = new BuildingHeightsEasy();
	clock_t start = clock();
	int my_answer = obj->minimum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 1;
	int t1[] = {43, 19, 15};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	BuildingHeightsEasy * obj = new BuildingHeightsEasy();
	clock_t start = clock();
	int my_answer = obj->minimum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 3;
	int t1[] = {19, 23, 9, 12};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	BuildingHeightsEasy * obj = new BuildingHeightsEasy();
	clock_t start = clock();
	int my_answer = obj->minimum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 15;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 12;
	int t1[] = {25, 18, 38, 1, 42, 41, 14, 16, 19, 46, 42, 39, 38, 31, 43, 37, 26, 41, 33, 37, 45, 27, 19, 24, 33, 11, 22, 20, 36, 4, 4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	BuildingHeightsEasy * obj = new BuildingHeightsEasy();
	clock_t start = clock();
	int my_answer = obj->minimum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 47;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

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
#include <cstring>

using namespace std;

class KnightTour {
public:
	string checkTour(vector <string>);
};

string KnightTour::checkTour(vector <string> v) {
	int a[6][6];
	memset(a, 0, sizeof(a));
	a[v[0][1] - '1'][v[0][0] - 'A']++;
	bool f = true;
	for (int i = 1; i < v.size(); i++) {
		int k = abs(v[i][1] - '1' - (v[i-1][1] - '1'));
		int k1 = abs(v[i][0] - 'A' - (v[i-1][0] - 'A'));
		if (((k == 1 && k1 == 2) || (k == 2 && k1 == 1)) && !a[v[i][1] - '1'][v[i][0] - 'A'])
			a[v[i][1] - '1'][v[i][0] - 'A']++;
		else f = false;
	}
	int k = abs(v[v.size() - 1][1] - '1' - (v[0][1] - '1'));
	int k1 = abs(v[v.size() -1][0] - 'A' - (v[0][0] - 'A'));
	if ((k == 1 && k1 == 2) || (k == 2 && k1 == 1)) {
	} else f = false;
	
	if (f) return "Valid";
	else return "Invalid";
}


double test0() {
	string t0[] = {"A1", "B3", "A5", "C6", "E5", "F3",
 "D2", "F1", "E3", "F5", "D4", "B5",
 "A3", "B1", "C3", "A2", "C1", "E2",
 "F4", "E6", "C5", "A6", "B4", "D5",
 "F6", "E4", "D6", "C4", "B6", "A4",
 "B2", "D1", "F2", "D3", "E1", "C2"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	KnightTour * obj = new KnightTour();
	clock_t start = clock();
	string my_answer = obj->checkTour(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Valid";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"A1", "C2", "E3", "F5", "D4", "B3",
 "A1", "C2", "E3", "F5", "D4", "B3", 
 "A1", "C2", "E3", "F5", "D4", "B3", 
 "A1", "C2", "E3", "F5", "D4", "B3", 
 "A1", "C2", "E3", "F5", "D4", "B3", 
 "A1", "C2", "E3", "F5", "D4", "B3"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	KnightTour * obj = new KnightTour();
	clock_t start = clock();
	string my_answer = obj->checkTour(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Invalid";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"D4", "F5", "D6", "B5", "A3", "B1", 
 "D2", "F1", "E3", "D1", "F2", "E4", 
 "F6", "D5", "B6", "A4", "B2", "C4", 
 "A5", "C6", "E5", "F3", "E1", "C2", 
 "A1", "B3", "C5", "E6", "F4", "E2", 
 "C3", "A2", "C1", "D3", "B4", "A6"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	KnightTour * obj = new KnightTour();
	clock_t start = clock();
	string my_answer = obj->checkTour(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Invalid";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"D4", "F5", "D6", "B5", "A3", "B1", 
 "D2", "F1", "E3", "D1", "F2", "E4", 
 "F6", "D5", "B6", "A4", "B2", "C4", 
 "A5", "C6", "E5", "F3", "E1", "C2", 
 "A1", "B3", "C5", "A6", "B4", "A2", 
 "C3", "E2", "C1", "D3", "F4", "E6"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	KnightTour * obj = new KnightTour();
	clock_t start = clock();
	string my_answer = obj->checkTour(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Valid";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"C5", "D3", "F2", "D1", "B2", "A4", 
 "B6", "D5", "C3", "E4", "F6", "B3", 
 "A1", "C2", "E1", "F3", "E5", "C6", 
 "A5", "C4", "A3", "B1", "D2", "F1", 
 "E3", "F5", "D6", "B5", "D4", "E6", 
 "F4", "E2", "C1", "A2", "B4", "A6"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	KnightTour * obj = new KnightTour();
	clock_t start = clock();
	string my_answer = obj->checkTour(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Invalid";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

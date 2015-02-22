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

class PalindromicSubstringsDiv2 {
public:
	int f(string s)
	{
		int n = s.size(), c = 0;
		for (int i = 0; i < n; i++) {
			for (int k = 0; k + i < n && i - k >= 0; k++) {
				if (s[i+k] != s[i-k]) break;
				else c++;
			 } 
		}
		
		for (int i = 1; i < n; i++) {
			if (s[i] == s[i-1]) {
				for (int k = 0; k + i < n && i - k - 1 >= 0; k++) {
					if (s[i+k] != s[i-k-1]) break;
					else c++;
				}
			}
		}
		return c;
	}
	
	
	int count(vector <string>, vector <string>);
};

int PalindromicSubstringsDiv2::count(vector <string> S1, vector <string> S2) {
	string s = "";
	for (int i = 0; i < S1.size(); i++) s += S1[i];
	for (int i = 0; i < S2.size(); i++) s += S2[i];
	
	return f(s);
	
}


double test0() {
	string t0[] = {"a","a",""};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"a"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	PalindromicSubstringsDiv2 * obj = new PalindromicSubstringsDiv2();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
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
	string t0[] = {"zaz"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	vector <string> p1;
	PalindromicSubstringsDiv2 * obj = new PalindromicSubstringsDiv2();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
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
	string t0[] = {"top"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"coder"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	PalindromicSubstringsDiv2 * obj = new PalindromicSubstringsDiv2();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 8;
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
	vector <string> p0;
	string t1[] = {"daata"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	PalindromicSubstringsDiv2 * obj = new PalindromicSubstringsDiv2();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 7;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

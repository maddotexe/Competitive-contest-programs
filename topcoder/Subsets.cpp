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

class Subsets {
public:
	int ans, ones;
	vector <pair<int, int> > vv;
	
	void solve(int pos, int sum, int pro)
	{
		if (sum && pro && sum + ones <= pro) return;
		
		if (pos == vv.size()) {
			if (sum && pro && sum + ones > pro) {
				ans += ones - (pro - sum);
			}
			return;
		}
		
		int val = 1;
		
		for (int i = 0; i <= vv[pos].second; i++) {
			if ((sum + i * vv[pos].first) && (pro * val) && sum + i * vv[pos].first + ones <= pro * val) break;
			solve(pos + 1, sum + i * vv[pos].first , pro * val);
			val *= vv[pos].first;
		}
	}
		
	int findSubset(vector <int>);
};

int Subsets::findSubset(vector <int> v) {
	sort(v.begin(), v.end());
	int c = 0, cc = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 1) {
			c++;
			continue;
		}
		
		if (i > 0 && v[i] != v[i-1]) {
			vv.push_back(pair<int, int>(v[i-1], cc));
			cc = 0;
		}
		
		cc++;
	}
	
	if (c == 0) return 0;
	
	if (cc) vv.push_back(pair<int, int> (v[v.size() - 1], cc));
	ones = c;
	ans = c - 1;
	
	solve (0, 0, 1);
	
	return ans;
		 
}


double test0() {
	int t0[] = {1,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Subsets * obj = new Subsets();
	clock_t start = clock();
	int my_answer = obj->findSubset(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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
	int t0[] = {1,1,1,1,2,2,2,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Subsets * obj = new Subsets();
	clock_t start = clock();
	int my_answer = obj->findSubset(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 13;
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
	int t0[] = {1,2,3,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Subsets * obj = new Subsets();
	clock_t start = clock();
	int my_answer = obj->findSubset(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
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
	int t0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,10,20,30,40,50};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Subsets * obj = new Subsets();
	clock_t start = clock();
	int my_answer = obj->findSubset(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 77;
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
double test4() {
	int t0[] = {1,1,1,1,1,1,1,1,1,1,1,2,3,4,2,2,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Subsets * obj = new Subsets();
	clock_t start = clock();
	int my_answer = obj->findSubset(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 100;
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
double test5() {
	int t0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,2,2,2,3,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Subsets * obj = new Subsets();
	clock_t start = clock();
	int my_answer = obj->findSubset(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 8050;
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
double test6() {
	int t0[] = {5,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Subsets * obj = new Subsets();
	clock_t start = clock();
	int my_answer = obj->findSubset(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	time = test5();
	if (time < 0)
		errors = true;
	
	time = test6();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

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

class BoundingBox {
public:
	int abs(int x) {if(x < 0) return -x; return x;}
	int smallestArea(vector <int>, vector <int>);
};

int BoundingBox::smallestArea(vector <int> x, vector <int> y) {
	int r = *min_element(x.begin(), x.end());
	int r1 = *max_element(x.begin(), x.end());
	int r2 =*min_element(y.begin(), y.end());
	int r3 = *max_element(y.begin(), y.end());
	cout << r << " " << r1 << " " << r2 << " " << r3 << endl;
	int ans = (r - r1) * (r2 - r3);
	ans = abs(ans);
	return ans;
}


double test0() {
	int t0[] = {0,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	BoundingBox * obj = new BoundingBox();
	clock_t start = clock();
	int my_answer = obj->smallestArea(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1;
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
	int t0[] = {0,-2,-1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-1,-1,-2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	BoundingBox * obj = new BoundingBox();
	clock_t start = clock();
	int my_answer = obj->smallestArea(p0, p1);
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
	int t0[] = {0,0,1,0,-1,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,1,2,-2,0,-1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	BoundingBox * obj = new BoundingBox();
	clock_t start = clock();
	int my_answer = obj->smallestArea(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 12;
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
	int t0[] = {9,-88,-40,98,-55,41,-38};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-65,56,-67,7,-58,33,68};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	BoundingBox * obj = new BoundingBox();
	clock_t start = clock();
	int my_answer = obj->smallestArea(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 25110;
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

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <cstring>
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

class MysticAndCandiesEasy {
public:
	int dp[50][50000];
	int minBoxes(int, int, vector <int>);
	int solve(int pos, int sum, vector<int> v)
	{
		if(pos == v.size()) {
			if(sum == 0) return 0;
			else return -99999999;
		}
		if(dp[pos][sum] != -1) return dp[pos][sum];
		
		int ans = -99999999;
		
		ans = max(ans, solve(pos+1, sum, v));
		
		for(int i = 1; i <= v[pos]; i++) {
			if(sum-i < 0) continue;
			ans = max(ans, 1+solve(pos+1,sum-i, v)); 
		}
		
		return dp[pos][sum] = ans;
	}
};
	
int MysticAndCandiesEasy::minBoxes(int c, int x, vector <int> v) {
	//int a[(int)v.size()]; int k = 0;
	sort(v.begin(), v.end());
	
	int val = c-x;
	int sum = 0;
	for(int i = 0; i < v.size(); i++) {
		sum += v[i];
		if(sum == val) return v.size()-i-1;
		if(sum > val) return v.size()-i;
	}
	
}


double test0() {
	int p0 = 10;
	int p1 = 10;
	int t2[] = {20};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	MysticAndCandiesEasy * obj = new MysticAndCandiesEasy();
	clock_t start = clock();
	int my_answer = obj->minBoxes(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
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
	int p0 = 10;
	int p1 = 7;
	int t2[] = {3, 3, 3, 3, 3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	MysticAndCandiesEasy * obj = new MysticAndCandiesEasy();
	clock_t start = clock();
	int my_answer = obj->minBoxes(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 4;
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
	int p0 = 100;
	int p1 = 63;
	int t2[] = {12, 34, 23, 45, 34};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	MysticAndCandiesEasy * obj = new MysticAndCandiesEasy();
	clock_t start = clock();
	int my_answer = obj->minBoxes(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 3;
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
	int p0 = 19;
	int p1 = 12;
	int t2[] = {12, 9, 15, 1, 6, 4, 9, 10, 10, 10, 14, 14, 1, 1, 12, 10, 9, 2, 3, 6, 1, 7, 3, 4, 10, 3, 14};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	MysticAndCandiesEasy * obj = new MysticAndCandiesEasy();
	clock_t start = clock();
	int my_answer = obj->minBoxes(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 22;
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
double test4() {
	int p0 = 326;
	int p1 = 109;
	int t2[] = {9, 13, 6, 6, 6, 16, 16, 16, 10, 16, 4, 3, 10, 8, 11, 17, 12, 5, 7, 8, 7, 4, 15, 7, 14, 2, 2, 1, 17, 1, 7, 7, 12, 17, 2, 9, 7, 1, 8, 16, 7, 4, 16, 2, 13, 3, 13, 1, 17, 6};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	MysticAndCandiesEasy * obj = new MysticAndCandiesEasy();
	clock_t start = clock();
	int my_answer = obj->minBoxes(p0, p1, p2);
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

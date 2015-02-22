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
#define MOD 1000000007
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

class VocaloidsAndSongs {
public:
	int dp[51][51][51][51];
	int a[3];
	int count(int, int, int, int);
	int solve(int p1, int p2, int p3, int k)
	{
		if(k == 0) return 1;
		if(dp[p1][p2][p3][k] != -1) return dp[p1][p2][p3][k];
		
		long long ans = 0;
		
		if(p1) ans = (ans + solve(p1-1, p2, p3, k-1))%MOD; 
		if(p2) ans = (ans + solve(p1, p2-1, p3, k-1))%MOD; 
		if(p3) ans = (ans + solve(p1, p2, p3-1, k-1))%MOD; 
		
		return dp[p1][p2][p3][k] = ans;
	}
};	

int VocaloidsAndSongs::count(int S, int gumi, int ia, int mayu) {
	memset(dp, -1, sizeof(dp));
	a[0] = gumi;
	a[1] = ia;
	a[2] = mayu;
	int ans = solve(gumi, ia, mayu, S);
	return ans;
}


double test0() {
	int p0 = 3;
	int p1 = 1;
	int p2 = 1;
	int p3 = 1;
	VocaloidsAndSongs * obj = new VocaloidsAndSongs();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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
	int p1 = 3;
	int p2 = 1;
	int p3 = 1;
	VocaloidsAndSongs * obj = new VocaloidsAndSongs();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 9;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 50;
	int p1 = 10;
	int p2 = 10;
	int p3 = 10;
	VocaloidsAndSongs * obj = new VocaloidsAndSongs();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 18;
	int p1 = 12;
	int p2 = 8;
	int p3 = 9;
	VocaloidsAndSongs * obj = new VocaloidsAndSongs();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 81451692;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 50;
	int p1 = 25;
	int p2 = 25;
	int p3 = 25;
	VocaloidsAndSongs * obj = new VocaloidsAndSongs();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 198591037;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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

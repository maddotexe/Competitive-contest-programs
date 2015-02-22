// BEGIN CUT HERE
// PROBLEM STATEMENT
// Manao is working in the Tree Research Center.
It may come as a surprise that the trees they research are not the ones you can see in a park.
Instead, they are researching special graphs.
(See Notes for definitions of terms related to these trees.)

Manao's daily job is reconstructing trees, given some partial information about them.
Today Manao faced a difficult task.
He needed to find the maximum possible diameter of a tree, given the following information:


Some vertex in the tree is called V.
The distance between V and the farthest vertex from V is D.
For each x between 1 and D, inclusive, Manao knows the number of vertices such that their distance from V is x.


You are given a vector <int> cnt containing D strictly positive integers.
For each i, the i-th element of cnt is equal to the number of vertices which have distance i+1 from V.
Please help Manao with his task.
Return the maximum possible diameter of a tree that matches the given information.


DEFINITION
Class:TheTree
Method:maximumDiameter
Parameters:vector <int>
Returns:int
Method signature:int maximumDiameter(vector <int> cnt)


NOTES
-A tree is a connected graph with no cycles. Note that each tree with N vertices has precisely N-1 edges.
-The distance between two vertices of a tree is the smallest number of edges one has to traverse in order to get from one of the vertices to the other one.
-The diameter of a tree is the maximum of all pairwise distances. In other words, the diameter is the distance between the two vertices that are the farthest away from each other.


CONSTRAINTS
-cnt will contain between 1 and 50 elements, inclusive.
-Each element of cnt will be between 1 and 1000, inclusive.


EXAMPLES

0)
{3}

Returns: 2

The only tree that matches the given information is shown below. The vertex V is red.




1)
{2, 2}

Returns: 4

There are two trees which correspond to the given partial information:



The tree on the left has diameter 3 and the tree on the right has diameter 4.

2)
{4, 1, 2, 4}

Returns: 5

This is one example of a tree that corresponds to the given constraints and has the largest possible diameter.



3)
{4, 2, 1, 3, 2, 5, 7, 2, 4, 5, 2, 3, 1, 13, 6}

Returns: 21



// END CUT HERE
#line 84 "TheTree.cpp"
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;

class TheTree {
	public:
	int maximumDiameter(vector <int> cnt) {
		vector <int> v;
		int sum = 0;
		if (cnt.size() == 0 && cnt[0] == 1) {
			return 1;
		}
		for (int i = 0; i < cnt.size(); i++) {
			if (cnt[i] != 1) {
				sum += 2;
			} else {
				v.push_back(sum + cnt.size() - i);
				sum = 0;
			}
		}
		if (sum != 0) v.push_back(sum);
		
		sum = v[0];
		for (int i = 0; i < v.size(); i++) {
			if (sum < v[i]) sum = v[i];
		}
		return sum;
	}
};

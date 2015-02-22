// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are playing TopRPG, the latest and hottest new console-style RPG (role-playing game) to hit the market.  Much like many RPGs, it features the main characters getting stronger as the game progresses by obtaining a nebulous sort of thing known as experience, which is typically acquired by killing monsters.

The strategy guide open in front of you tells you how much experience you'll need to get to each level, represented as a vector <int> expNeeded.  For example, if expNeeded were {150, 450, 900, 1800}, you would need a total of 150 experience to get to level 1 (from level 0), then another (450 - 150) = 300 experience to get to level 2, and so on.

You have 0 experience at the start, and you are about to go through an area where you will get a fixed amount of experience.   You want to know how far you will be from the next level after you finish.  Given a vector <int> expNeeded, where the ith element is the total amount of experience required to advance to level i, and an int received, indicating the amount of experience you will get, return an int which is the amount of experience it will take you to get to the next level after you receive the experience.

DEFINITION
Class:LevelUp
Method:toNextLevel
Parameters:vector <int>, int
Returns:int
Method signature:int toNextLevel(vector <int> expNeeded, int received)


CONSTRAINTS
-expNeeded will contain between 1 and 50 elements, inclusive.
-Each element in expNeeded will be greater than all elements with lower indices.
-All elements in expNeeded will be between 1 and 999999, inclusive.
-received will be between 0, inclusive, and the largest element of expNeeded, exclusive.


EXAMPLES

0)
{150,450,900,1800}
133

Returns: 17

You receive 133 experience, which isn't enough to get to level 1.  You need is 150 - 133 = 17 more to get there.

1)
{150,450,900,1800}
312

Returns: 138

With the same situation, you now receive 312 experience.  The first 150 advances you to level 1.  There is 162 left, which then goes to the 450 - 150 = 300 experience you need to get from level 1 to level 2.  Thus to get to the next level (2), you need 300 - 162 = 138 more experience.

2)
{150,450,900,1800}
612

Returns: 288

3)
{150,450,900,1800}
450

Returns: 450

You advance exactly to level 2, and thus need 900 - 450 = 450 experience to get to the next level.

// END CUT HERE
#line 58 "LevelUp.cpp"
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

class LevelUp {
	public:
	int toNextLevel(vector <int> v, int n) {
		for (int i = 0; i < v.size(); i++) {
			if (v[i] > n) return v[i] - n;
		}
	}
};

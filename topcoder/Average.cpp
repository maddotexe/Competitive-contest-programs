#include <iostream>
#include <cstdio>
#include <vector>

using namespace std; 

class Average {
	public :
		int belowAvg(vector <int> v, vector <int> v1) 
		{
			int c = 0, sum = 0;
			for (int i = 0; i < v.size(); i++) {
				sum += v[i] + v1[i];
			}
			
			double  av = (double) sum / (double) v.size();
			
			for (int i = 0; i < v.size(); i++) 
				if (av > (double) (v[i] + v1[i])) c++;
				
				
			return c;
		}
};

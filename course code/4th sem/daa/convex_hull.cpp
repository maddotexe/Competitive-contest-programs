#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> >merge(vector<pair<int, int> > v, vector<pair<int, int> > v1){
	
}

vector<pair<int, int> > divide(vector<pair<int, int> > v, int min, int max, int n) {
	if (n == 1) {
		vector <pair<int, int> > v5;
		for (int i = 0; i < n; i++) {
			if (v[i].first >= min && v[i].first <= max) {
				v5.push_back(v[i]);
			}
		}
		
		return v5;
		
	} else if (n == 2) {
		vector <pair<int, int> > v5;
		for (int i = 0; i < n; i++) {
			if (v[i].first >= min && v[i].first <= max) {
				v5.push_back(v[i]);
			}
		}
		
		return v5;
	} else if (n == 3) {
		vector <pair<int, int> > v5;
		for (int i = 0; i < n; i++) {
			if (v[i].first >= min && v[i].first <= max) {
				v5.push_back(v[i]);
			}
		}
		
		return v5;
	} else if (n == 0) {
		vector <pair<int, int> > v5;
		return v5;
	}
	
	if (min == max) {
		int y_min = 0;
		int y_max = 0;
		vector <pair<int, int> > v5;
		for (int i = 0; i < n; i++) {
			if (v[i].first == min) {
				if (v[y_min].second > v[i].second) {
					y_min = i;
				}
				if (v[y_max].second < v[i].second) {
					y_max = i;
				}
			}
			v5.push_back(v[y_min]);
			v5.push_back(v[y_max]);
		}
		
		return v5;
	}
	
	int mid = (min + max) / 2;
	int i;
	 
	int no_of_pts = 0, no_of_pts1 = 0;
	for (int i = 0; i < n; i++) {
		if (min <= v[i].first && mid >= v[i].first) {
			no_of_pts++;
		}
		if (mid < v[i].first && max >= v[i].first) {
			no_of_pts1++;
		}
	}
	for(i = 0; v[i].first < min; i++);
	cout << "Left half no of points : " << no_of_pts << endl;
	for(; v[i].first <= mid; i++) cout << i << " " << v[i].first << " " << v[i].second << endl;
	cout << "Right halfno of points : " << no_of_pts1 << endl;
	for(; v[i].first <= max; i++) cout << i << " " << v[i].first << "  " << v[i].second << endl;
	
	vector <pair<int, int> > v1, v2;
	v1 = divide(v, min, mid, no_of_pts);
	v2 = divide(v, mid + 1, max,  no_of_pts1);
	
	vector <pair<int, int> > v4;
	
	//v4 = merge(v1, v2);
	return v;
}



int main()
{
	int n, x, y;
	vector <pair<int, int> > v;
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back(pair<int, int> (x, y));
	}
	sort(v.begin(), v.end());
	v = divide(v, v[0].first, v[n - 1].first, n);
	
	return 0;
}
	

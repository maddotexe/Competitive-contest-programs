#include <iostream>
#include <cstdio>

using namespace std;

void bin_s(int arr[], int left, int right, int target) 
{
	if (left > right) {
		cout<<"Not Found"<<endl;
		return;
	}

	int mid;

	mid = (left + right) / 2;
	
	if (arr[mid] == target) {
		cout<<"Found"<<endl;
	}

	else if (arr[mid] < target) {
		cout<<"Moving to right of "<<arr[mid]<<endl;
		bin_s(arr, mid + 1, right, target);
		}
	
	else {
		cout<<"Moving to left of "<<arr[mid]<<endl;
		bin_s( arr, left, mid - 1, target);
	}
	
}
int main()
{
	int a[100];
	int i;
	int n;

	cout<<"How many no's you want to enter"<<endl;
	scanf("%d", &n);

	cout<<"Enter the numbers"<<endl;

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);	
	}
	
	cout<<"Enter the no. to be searched"<<endl;
	scanf("%d", &i);

	bin_s(a, 0, n, i);

	return 0;
}

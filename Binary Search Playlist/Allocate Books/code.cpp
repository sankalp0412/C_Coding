#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int possible(vector<int> &arr, int pages, int m) {
	int cnt = 1;
	long long sum = 0;
	for(int i = 0; i < arr.size(); i++) {
		if(sum + arr[i] <= pages)
			sum += arr[i];
		else {
			cnt++;
			sum = arr[i];
		}
	}
	return cnt; 
}
int findPages(vector<int>& arr, int n, int m) {
	if(m > n) return -1;
	int low = *max_element(arr.begin(),arr.end());
	int high = accumulate(arr.begin(),arr.end(), 0);

	while(low <= high) {
		int mid = (low + high)/2;
		int students = possible(arr,mid,m);
		if(students > m)
			low = mid + 1;
		else 
			high = mid - 1;
	}
	return low;
}


int main() {
	init_code();
	vector<int> arr = {25 ,46 ,28 ,49 ,24};
	int m = 4;
	cout << findPages(arr,arr.size(),m);
	return 0;
}

//tc: O(log(sum - max(arr) + 1) * O(n));

//this question is same as 
	// 1) Painters partition Coding ninjas
	// 2) leet code 410 Split array largest sum
#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
 int findKthPositive(vector<int>& arr, int k) {
 	int n = arr.size();
 	int low = 0, high = n-1;
 	while(low <= high) {
 		int mid = (low + high)/2;
 		int missing = arr[mid] - (mid + 1);
 		if(missing < k) {
 			low = mid + 1;
 		}
 		else 
 			high = mid -1;
 	}
 	return low + k;
}
int main() {
	init_code();
	vector<int> arr = {2,3,4,7,11};
	int k = 5;
	cout << findKthPositive(arr,k);
	return 0;
}
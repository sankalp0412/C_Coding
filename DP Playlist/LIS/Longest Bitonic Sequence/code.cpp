//similar Questions:
/*
845. Longest Mountain in Array
852. Peak Index in a Mountain Array
1671. Minimum Number of Removals to Make Mountain Array

941. Valid Mountain Array 
*/

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
//in this question we will find the LIS from both sides of the array
// as the LIS from the back is like a decreasing sequence from the front.
// 1 2 4 10 5 3 2 1

//LIS from front  1 2 4 10
//LIS from back 1 2 3 5 10
//10 is coming twice 
//so for each index lenght of Bitonic sequece = dp1[i] + dp2[i] - 1
//we will pick the max from each index


int longestBitonicSubsequence(vector<int>& arr, int n){
	vector<int> dp1(n+1,1);
	vector<int> dp2(n+1,1);
	for(int i = 0; i < n; i++) {
		for(int prev = 0; prev < i; prev++){
			if(arr[prev] < arr[i] && 1 + dp1[prev] > dp1[i]) {
				dp1[i] = 1 + dp1[prev];
			}
		}
	}

	//LIS from back

	for(int i = n-1; i >= 0; i--) {
		for(int prev = n-1; prev > i; prev--)  {
			if(arr[i] > arr[prev] && 1 + dp2[prev] > dp2[i]) {
				dp2[i] = 1 + dp2[prev];
			}
		}
	}

	//check 
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans = max(ans, dp1[i] + dp2[i] - 1);
	}
	return ans;
}

int main() {
	init_code();
	vector<int> arr = {1, 2, 1 ,2, 1};
	cout << longestBitonicSubsequence(arr,arr.size());
	return 0;
}
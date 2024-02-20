// Coding ninjas question
// You are given an array 'arr' containing 'n' non-negative integers.
// Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.
// You just need to find the minimum absolute difference considering any valid division of the array elements.

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}


int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totalSum = accumulate(arr.begin(),arr.end(), 0);
	vector<bool> prev(totalSum+1,0), curr(totalSum+1,0);
	prev[0] = true;
	curr[0] = true;
	prev[arr[0]] = true;

	for(int i = 1; i < n; i++){
		for(int target = 1; target <= totalSum; target++) {
			bool notTake = prev[target];
			bool take = false;
			if(arr[i] <= target) take = prev[target - arr[i]];

			curr[target] = notTake | take;
		}
		prev = curr;
	}
	// dp[n-1][col0...totalSum] will tell the answer
	int ans = INT_MAX;
	for(int i = 0; i <= totalSum/2; i++) {
		if(prev[i]){
			int s1 = i;
			int s2 = totalSum - s1;
			ans = min(ans, abs(s1-s2));
		}
	}
	return ans;

}

int main() {
	init_code();
	vector<int> arr = {3,9,7,3};
	cout << minSubsetSumDifference(arr,arr.size());
	return 0;
}
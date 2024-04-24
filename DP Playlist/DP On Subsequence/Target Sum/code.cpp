//This problem can be solved by the approach used in 
// Count Partitions with given difference

//Ex -1 + 2+3-1
//take + and - together
// 2+3 - (1+1);

// 5 - 2 = 3
//s1 - s2 = d -> this problem is same as count partitions with given difference

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
#include <bits/stdc++.h> 
int mod = 1e9 + 7;
int countSubsetWithSumK(vector<int> &arr, int k, int &n) {
	vector<int> prev(k + 1,0), curr(k + 1,0);
	prev[0] = 1;
	curr[0] = 1;
	if(arr[0] <= k) prev[arr[0]] = 1;
	if(arr[0] == 0) curr[0] = prev[0] = 2; 

	for(int i = 1; i < n; i++) {
		for(int j = 0; j <= k; j++) {
			int notTake = prev[j];
			int take = 0;

			if(j >= arr[i])
				take = prev[j - arr[i]];

			curr[j] = (take + notTake) % mod;
		}
		prev = curr;
	}

	return prev[k];
}
int countPartitions(int n, int d, vector<int> &arr) {
	int total = accumulate(arr.begin(),arr.end(),0);
	int sum = (total - d)/2; //and now this is same as count number of subsets with sum k
	if((total - d) <= 0 || (total - d) % 2)  return 0;

	return countSubsetWithSumK(arr,sum, n);
}
int targetSum(int n, int target, vector<int>& arr) {
    return countPartitions(n,target, arr);
}

int main() {
	init_code();
	int n = 5,target = 3;
	vector<int> arr = {1, 1, 1, 1, 1};
	cout << targetSum(n,target,arr);
	return 0;
}
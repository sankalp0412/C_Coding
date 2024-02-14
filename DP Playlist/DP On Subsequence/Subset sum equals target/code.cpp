//any contiguous or non contiguous part of arr is called
//a subsequence

/*You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.

Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.

For Example :
If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.
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
bool solveMemo(int idx, int target, vector<int> &arr,vector<vector<int>> &memo) {
	//base
	if(target == 0)	return true;
	if(idx == 0) return (arr[0] == target);

	if(memo[idx][target] != -1)
		return memo[idx][target];

	bool take = false, notTake;

	if(target >= arr[idx])
		take = solveMemo(idx - 1,target - arr[idx], arr,memo);
	notTake = solveMemo(idx - 1, target,arr,memo);

	return memo[idx][target] = take || notTake;
}
bool solveTabulation(int n, int k, vector<int> &arr) {
	vector<vector<bool>> dp(n,vector<bool> (k + 1,0));

	dp[0][arr[0]] = 1; //if i am at 0 index 
	for(int i = 0; i < n; i++)
		dp[i][0] = 1;

	for(int i = 1; i < n; i++){
		for(int target = 1; target <= k; target++) {
			bool notTake = dp[i - 1][target];
			bool take = false;
			if(arr[i] <= target) take = dp[i - 1][target - arr[i]];

			dp[i][target] = notTake || take;
		}
	}

	return dp[n-1][k];

}

bool spaceOpt(int n, int k, vector<int> &arr) {
	vector<bool> prev(k+1,0), curr(k+1,0);
	prev[0] = true;
	curr[0] = true;

	for(int i = 1; i < n; i++){
		for(int target = 1; target <= k; target++) {
			bool notTake = prev[target];
			bool take = false;
			if(arr[i] <= target) take = prev[target - arr[i]];

			curr[target] = notTake || take;
		}
		prev = curr;
	}

	return prev[k];

}
bool subsetSumToK(int n, int k, vector<int> &arr) {
	vector<vector<int>> memo(n , vector<int> (k + 1, -1));
	// return solveMemo(n-1,k,arr,memo);
	// return solveTabulation(n,k,arr);
	return spaceOpt(n,k,arr);

}
int main() {
	init_code();
	int n = 4, k = 5;
	vector<int> arr = {4,3,2,1};
	cout << subsetSumToK(n,k,arr);
	return 0;
}



//REcursion TC : O(2^n)
//SC : Resucstion stack space


//Memo TC: O(N * target)
// SC : O(N*targe) + Aux


//Tabulation TC & SC Same as  memo except Aux

//Space Optimization TC: Same
//TC: O(target);
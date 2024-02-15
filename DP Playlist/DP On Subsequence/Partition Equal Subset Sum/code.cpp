//Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

//Here we require two subsets of equal sum
//if the total sum is S then we require two subsets
//s.t. s1 = s2 = S/2;

//If s is odd, not possible as we can't have odd sum
// devided into two equal sum subsets
//if S is even we need to look for a single subset
//with sum S/2 as then we will have two subsets with sum
//S/2

//Eg: {2,3,3,3,4,5} = 20

//Here {2,3,5} will give me sum 10 so the other subset
//will also give me sum  20 -10 = 10;

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
bool solve(vector<int> &nums, int idx, int target, vector<vector<int>>& memo) {
        if(target == 0)
            return true;
        if(idx == 0) return nums[idx] == target;

        if(memo[idx][target] != -1)
        	return memo[idx][target];

        int take = false, notTake;

        notTake = solve(nums,idx - 1, target,memo);

        if(nums[idx] <= target)
            take = solve(nums, idx - 1 , target - nums[idx],memo);

        return memo[idx][target] = take || notTake;        
    }

bool solveTabulation(vector<int> &nums, int &target) {
	int n = nums.size();
	vector<vector<bool>> dp(n,vector<bool> (target + 1, false));
	for(int i = 0; i < n; i++)
		dp[i][0] = true;

	if(nums[0] <= target) dp[0][nums[0]] = true; //The if condition is the new additin as per the comment in the video, this is why my code was failing for TC: nums = {100}.

	for(int i = 1; i < n; i++){
		for(int k = 1; k <= target; k++) {
			int take = false, notTake;
			notTake = dp[i-1][k];

			if(nums[i] <= k)
				take = dp[i-1][k - nums[i]];

			dp[i][k] = take || notTake;
		}
	}
	return dp[n-1][target];
}
bool canPartition(vector<int>& nums) {
    int total = accumulate(nums.begin(),nums.end(),0);
    if(total & 1) return false;
    int target = total / 2;
    vector<vector<int>> memo(nums.size(),vector<int> (target + 1,-1));
    // return solve(nums,nums.size() - 1, target,memo);
    return solveTabulation(nums,target);
}
int main() {
	init_code();
	vector<int> arr = {2,3,3,3,4,5};
	cout << canPartition(arr);
	return 0;
}
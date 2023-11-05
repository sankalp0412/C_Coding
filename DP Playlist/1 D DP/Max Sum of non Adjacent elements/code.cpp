#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

int solveSpaceOptized(vector<int> &nums) {
	int prev = nums[0];
    int prev2 = 0;
    for(int i = 1; i < nums.size(); i++) {
        int take = nums[i] + prev2;
        int notTake = prev;

        int currMax = max(take,notTake);
        prev2 = prev;
        prev = currMax;
    }
    return prev; //as in dp we return dp[n-1], for i = n (when the loop stops), n-1 will be prev
}
int solveTabulation(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,0);
    dp[0] = nums[0];
    for(int i = 1; i < n; i++){
        int take = nums[i] + (i > 1 ? dp[i-2]: 0);
        int notTake = dp[i-1];
        dp[i] = max(take,notTake); 
    }
    return dp[n-1];
}
int solveMemo(int idx, vector<int> &nums,vector<int> &memo) {
    if(idx == 0)
        return nums[idx];
    else if(idx < 0)
        return 0;
    if(memo[idx] != -1)
        return memo[idx];
    int pick = nums[idx] + solveMemo(idx-2,nums,memo);
    int notPick = 0 + solveMemo(idx-1,nums,memo);

    return memo[idx] = max(pick,notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> memo(n,-1);
    // return solveMemo(n-1,nums,memo);   
    // return solveTabulation(nums); 
    return solveSpaceOptized(nums);
}
int main() {
	init_code();
	vector<int> arr = {2,1,4,9};
	cout <<  maximumNonAdjacentSum(arr);
	return 0;
}
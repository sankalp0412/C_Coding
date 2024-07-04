#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int solve(int prev, int idx, vector<int> &nums , int &n,vector<vector<int>> &dp) {
    if(idx == n) return 0;
    
    if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
    //Not take
    int len = 0 + solve(prev,idx+1,nums,n,dp);
    //take
    if(prev == -1 || nums[idx] > nums[prev]) 
    	len = max(len, 1 + solve(idx,idx+1,nums,n,dp));

    return dp[idx][prev+1] = len;
}
int solveTabulation(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> dp(n+1,vector<int> (n+1,0));
    for(int idx = n-1; idx >= 0; idx--) {
    	for(int prev = idx-1; prev >= -1; prev--) {
    		int len = 0 + dp[idx+1][prev+1];
    		if(prev == -1 || nums[idx] > nums[prev])
    			len = max(len,1+dp[idx+1][idx+1]);
    	    dp[idx][prev+1] = len;
    	}
    }
    return dp[0][0];
}
int spaceOptm(vector<int> &nums) {
	int n = nums.size();
    vector<int> next(n+1,0), curr(n+1,0);
    for(int idx = n-1; idx >= 0; idx--) {
    	for(int prev = idx-1; prev >= -1; prev--) {
    		int len = 0 + next[prev+1];
    		if(prev == -1 || nums[idx] > nums[prev])
    			len = max(len,1+next[idx+1]);
    	    curr[prev+1] = len;
    	}
    	next = curr;
    }
    return next[0];
}
int anotherWay(vector<int> &nums) { //this was is required to print the LIS
	int n = nums.size();
	vector<int> dp(n,1);
	for(int i = 1; i < n; i++) {
		for(int j = i-1; j >= 0; j--) {
			if(nums[j] < nums[i])
				dp[i] = max(dp[i],1 + dp[j]);
		}
	}
	return *max_element(dp.begin(),dp.end());
}

vector<int> printLIS(vector<int> &nums) {
	int n = nums.size();
	int lastIdx = 0, maxi = 1;
	vector<int> dp(n,1), hash(n);
	for(int i = 1; i < n; i++) {
		hash[i] = i;
		for(int j = i-1; j >= 0; j--) {
			if(nums[j] < nums[i] && 1 + dp[j] > dp[i]){
				dp[i] = 1 + dp[j];
				hash[i] = j;
			}
		}
		if(dp[i] > maxi) {
			maxi = dp[i];
			lastIdx = i;
		}
	}
	vector<int> lis;
	lis.push_back(nums[lastIdx]);
	while(hash[lastIdx] != lastIdx) {
		lastIdx = hash[lastIdx];
		lis.push_back(nums[lastIdx]);
	}
	reverse(lis.begin(),lis.end());
	return lis;
}

int solveBS(vector<int> &nums ){ 
	vector<int> temp;
	temp.push_back(nums[0]);
	int n = nums.size();
	for(int i = 1; i < n; i++) {
		if(nums[i] > temp.back())	
		    temp.push_back(nums[i]);
	else {
			int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
			temp[ind] = nums[i];
		}
    }
	return temp.size(); //not the LIS, only the size, we are using the same array to replicate
}
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n,vector<int> (n+1,-1));
    // return solve(-1,0,nums,n,dp);
    // return solveTabulation(nums);
    // return spaceOptm(nums);
    auto lis = printLIS(nums);
    for(auto x: lis) cout << x << ",";
    	cout << endl;
    return anotherWay(nums);
}
int main() {
	init_code();
	vector<int> nums = {10,9,2,5,3,7,101,18};
	cout << lengthOfLIS(nums);
	return 0;
}
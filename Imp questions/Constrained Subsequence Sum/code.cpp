// https://www.youtube.com/watch?v=tWhboGihflM


// Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.

// A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.

 

// Example 1:

// Input: nums = [10,2,-10,5,20], k = 2
// Output: 37
// Explanation: The subsequence is [10, 2, 5, 20].


#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

class Solution {
public:
	unordered_map<string,int> mp;
	//this is the brute force, we can memoize it by using 
	//unorderd map and string 
	//we can't use array as the constraints are 10^5
	//so we can't make an array of 2d size as it will give MLE
    int solveBrute(int prev, int curr, vector<int> &nums, int k) {
        if(curr >= nums.size())
            return 0;
        int res = 0;
        if(prev == -1 || curr - prev <= k) {
            int take = nums[curr] + solveBrute(curr,curr+1,nums,k);
            int notTake = solveBrute(prev,curr+1,nums,k);
            res = max(take,notTake); 
        }
        return res;
    }
    //but even the memo solution will give TLE/MLE
    int solveMemo(int prev, int curr, vector<int> &nums, int k) {
        if(curr >= nums.size())
            return 0;
        if(mp.count(prev + "_" + curr))
        	return mp[prev + "_" + curr];
        int res = 0;
        if(prev == -1 || curr - prev <= k) {
            int take = nums[curr] + solveMemo(curr,curr+1,nums,k);
            int notTake = solveMemo(prev,curr+1,nums,k);
            res = max(take,notTake); 
        }
        return mp[prev + "_" + curr] = res;
    }
    //even the tabulation solution is TLE as 
    //it is O(n^2) and that is too much for 10^5
    int solveTabulation(vector<int>& nums, int k) {
    	int n = nums.size();
    	vector<int> dp(n);

    	for(int i = 0; i < n; i++) {
    		dp[i] = nums[i]; //as initially the maximum subsequence ending at i will be nums[i]
    	}
    	int ans = nums[0];
    	for(int i = 0; i < n; i++) {
    		for(int j = i-1; j >=0 && j-i <= k; j--) {
    			dp[i] = max(dp[i], nums[i] + dp[j]);
    			ans = max(ans,dp[i]);
    		}
    	}
    	return ans;
    }
    //so basically the culprit is the second for loop which 
    // is giving us an extra n TC
    //WHAT IS THE ROLE OF SECOND LOOP ABOVE IN TABLUATION:
    //it is to traverse j from i-1 to (j-i) <= k
    //and used to search for the max(dp[j])
    //so why don't we even store that in a dataStructure somewhere
    //which can give the maximum in O(1)
    //THIS IS WHY WE THINK OF Max HEap

    int solveOptimal(vector<int> &nums, int k) {
    	 int n = nums.size();
    	vector<int> dp(n);
    	priority_queue<pair<int,int>> pq;

    	for(int i = 0; i < n; i++) {
    		dp[i] = nums[i]; //as initially the maximum subsequence ending at i will be nums[i]
    	}
    	int ans = nums[0];
        pq.push({dp[0],0});
    	for(int i = 1; i < n; i++) {
    		while(!pq.empty() && i - pq.top().second > k)
    			pq.pop();
    		dp[i] = max(dp[i],nums[i] + pq.top().first);
            pq.push({dp[i],i});
    		ans = max(ans,dp[i]);
    	}
    	return ans;
    }
    int constrainedSubsetSum(vector<int>& nums, int k) {
    	return solveOptimal(nums,k);
    	// return solveTabulation(nums,k);
        // int ans = solveMemo(-1,0,nums,k);
        // return ans == 0 ? *max_element(nums.begin(),nums.end()) : ans;
    }
};
int main() {
	init_code();
	vector<int> vec = {10,2,-10,5,20};
	Solution sol;
	cout << sol.constrainedSubsetSum(vec,2);
	return 0;
}

//TC For optimal = O(n*logN)
//On for first lloop
//as in worst case max size of PQ will go to n when we never
//pop any element
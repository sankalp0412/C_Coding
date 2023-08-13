#include "bits/stdc++.h"
using namespace std;

// #define for(i,n) for(int i = 0; i < n; i++)

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
class SolutionByMe {
public:
    bool solve(vector<int> &arr, int beg, int end, vector<vector<int>> &memo) {
        int len = (end-beg) + 1;
        // cout << beg << "," << end << 
        if(len < 2 || beg > end) return false;
        if(len == 2) return arr[beg] == arr[end];
        if(len == 3) {
            bool conInc = ((arr[beg] + 1 == arr[beg+1]) && (arr[beg+1] + 1 == arr[end]));
            bool eql = (arr[beg] == arr[beg+1] && arr[beg+1] == arr[end]);

            return (conInc || eql);
        }  
        if(memo[beg][end] != -1) return memo[beg][end];
        bool remainArray;
        //pick first two
        bool firstTwo = solve(arr,beg,beg+1,memo);
        remainArray = solve(arr,beg+2,end,memo);
        if(firstTwo && remainArray) 
            return memo[beg][end] = true;
        //pick first three elemets
        bool firstThree = solve(arr,beg,beg+2,memo);
        remainArray = solve(arr,beg+3,end,memo);
        if(firstThree && remainArray)
            return memo[beg][end] = true;

        return memo[beg][end] = false;
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n+1,vector<int> (n+1,-1));
        return solve(nums,0,n-1, memo);
    }
};

class Solution {
public:
    unordered_map<int, bool> memo;

    // Determine if the prefix array nums[0 ~ i] has a valid partition
    bool solveMemo(vector<int>& nums, int i) {
        if (memo.count(i)) {
            return memo[i];
        }
        bool ans = false;

        // Check 3 possibilities
        if (i > 0 && nums[i] == nums[i - 1]) {
            ans |= solveMemo(nums, i - 2);
        }
        if (i > 1 && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2]) {
            ans |= solveMemo(nums, i - 3);
        }
        if (i > 1 && nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1) {
            ans |= solveMemo(nums, i - 3);
        }
        memo[i] = ans;
        return ans;
    }

    bool solveDP(std::vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return false;

        std::vector<bool> dp = {true, false, n > 1 && nums[0] == nums[1]};

        for (int i = 2; i < n; i++) {
            bool current_dp = false;

            if (nums[i] == nums[i-1] && dp[1]) {
                current_dp = true;
            }
            else if (nums[i] == nums[i-1] && nums[i] == nums[i-2] && dp[0]) {
                current_dp = true;
            }
            else if (nums[i] - nums[i-1] == 1 && nums[i-1] - nums[i-2] == 1 && dp[0]) {
                current_dp = true;
            }

            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = current_dp;
        }

        return dp[2];
    }

    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        memo[-1] = true;

        // return solveMemo(nums, n - 1);
        return solveDP(nums);
    }
};


int main() {
	init_code();
	vector<int> arr = {4,4,4,5,6};
	Solution solution;
	SolutionByMe sbe;
	cout << solution.validPartition(arr);
	return 0;
}
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

// The solution uses dynamic programming to determine if the given array can be partitioned into valid segments according to the rules provided in the problem. It uses an array dp to store the state of whether a valid partition exists for specific positions in the array.

// Here's a step-by-step explanation of how the solution works:

// First, the code initializes the dp array with initial values:

// dp[0] is set to true, indicating that an empty subarray is considered a valid partition.
// dp[1] is set to false, indicating that a single element subarray is not a valid partition.
// dp[2] is set to true only if the first two elements of the array are equal. This handles the case where the array starts with two equal elements, making a valid partition.
// Then, the code iterates over the array from the third element (index 2) up to the end of the array:

// For each element at index i, the code checks three conditions to determine if a valid partition can be created using the current element and the previous elements.
// current_dp is used to store whether a valid partition is possible considering the current element.
// The conditions checked are:

// If the current element is equal to the previous element and a valid partition was possible for the previous two elements (dp[1]), then a valid partition is possible for the current element.
// If the current element is equal to the two previous elements and a valid partition was possible for an empty subarray (dp[0]), then a valid partition is possible for the current element.
// If the current element is one greater than the previous element and the previous element is one greater than the element before it, and a valid partition was possible for an empty subarray (dp[0]), then a valid partition is possible for the current element.
// After checking the three conditions, the dp array is updated:

// dp[0] is updated to the previous value of dp[1].
// dp[1] is updated to the previous value of dp[2].
// dp[2] is updated to the value of current_dp.
// Finally, the solution returns the value of dp[2], which indicates whether a valid partition exists for the entire array.

// This solution efficiently keeps track of whether a valid partition is possible for various positions in the array using only three elements in the dp array. This avoids excessive memory usage and provides a more memory-efficient implementation compared to the original recursive approach.
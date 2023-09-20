//QUESTION:

// You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

// Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.


// APPROACH:

//here we need to minimize the times
//TOTAL ARRAY SUM  = sum
//so if sum is x the rest of the array is sum - x
// so basically we can find the maximum subarray sum
// of length sum - x, and then the answer will be 
// total length - that length of sub array
//


// now since there are only positives as per the constraints
//we can use the approach to find longest subarray sum
// in case of positives 

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
	int longestSubarray(vector<int>& nums, int& target) {
		int beg = 0, end = 0, n = nums.size();
		int currSum = nums[0], maxLen = 0;
		while(end < n) {
			while(beg <= end && currSum > target) {
				currSum -= nums[beg++];
			}
			if(currSum == target){
				int currLen = end - beg + 1;
				maxLen = max(maxLen,currLen);
			}
			end++;
      if(end < n)
				currSum += nums[end];
		}
		return maxLen;
	}
    int minOperations(vector<int>& nums, int x) {
        long long arraySum = accumulate(nums.begin(),nums.end(),0);
        int reqSum = arraySum - x;
		if(reqSum < 0) return -1;
		if(reqSum == 0) return nums.size(); // i didn't add these two checks first so was getting wrong anser
        int ans = nums.size()-longestSubarray(nums,reqSum) ;
        return ans == nums.size() ? -1 :ans  ;
    }
};
int main() {
	init_code();
	vector<int> nums = {1,1,4,2,3};
	int x = 5;
	Solution solution;
	cout <<  solution.minOperations(nums,x);
	return 0;
}
#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int beg = 0, end = 0, prod = 1, ans = 0;
        if(k <= 1) return 0;
        while(end < n) {
            prod *= nums[end];
            while(prod >= k) prod /= nums[beg++];
            ans += 1 + (end - beg);
            end++;
        }
        return ans;
    }
int main() {
	init_code();
	vector<int> nums = {10,5,2,6};
	int k = 100;
	cout << numSubarrayProductLessThanK(nums,k);
	return 0;
}


// Count subarrays:
// Add 1 + (right - left) to count. This accounts for:
// 1: The single-element subarray ending at right.
// (right - left): The number of contiguous subarrays within the current window (excluding elements already removed in the inner loop).
// Increment right to move the window one step forward.
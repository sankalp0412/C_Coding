//this is an optimal solution if 
//array only contains positives and 0

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int longestSubarray(vector<int> nums, int target) {
	int ans = INT_MIN;
	int left =0, right = 0;
	int sum = nums[0];
	int n = nums.size();
	while(right < n) {
		while(left <= right && sum > target) {
			sum -= nums[left];
			left++;
		}
		if(sum == target) {
			ans = max(ans,right - left + 1);
		}		
		right++;
		if(right < n) sum += nums[right];
	}
	return ans;
}
int main() {
	init_code();
	vector<int> nums = {1,2,3,1,1,1,1,2,3,4};
	int target = 6;
	cout << longestSubarray(nums,target);
	return 0;
}


// TC
// at worst case  : O(2n); 
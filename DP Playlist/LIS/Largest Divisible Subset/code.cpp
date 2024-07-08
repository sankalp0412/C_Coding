#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
//same as LIS, here we just have to check for divisibility
vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(),nums.end());
	int lastIdx = 0, maxi = 1;
	vector<int> dp(n,1), hash(n);
	for(int i = 1; i < n; i++) {
		hash[i] = i;
		for(int j = i-1; j >= 0; j--) {
			if(nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i]){
				dp[i] = 1 + dp[j];
				hash[i] = j;
			}
		}
		if(dp[i] > maxi) {
			maxi = dp[i];
			lastIdx = i;
		}
	}
	vector<int> ans;
	ans.push_back(nums[lastIdx]);
	while(hash[lastIdx] != lastIdx) {
		lastIdx = hash[lastIdx];
		ans.push_back(nums[lastIdx]);
	}
	return ans;
}
int main() {
	init_code();
	vector<int> nums = {1,2,4,7,8,16};
	auto vec = largestDivisibleSubset(nums);
	for(auto x: vec) cout << x << " ";
	return 0;
}
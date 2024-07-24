#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
//yet to do
int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
	vector<int> dp(n,1), cnt(n,1);
    int maxi = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(nums[j] < nums[i] && 1 + dp[j] > dp[i]) {
				dp[i] = 1 + dp[j];
				cnt[i] = cnt[j];
			}
			else if (nums[j] < nums[i] && 1 + dp[j] == dp[i]){
				cnt[i] += cnt[j];
			}
		}
        maxi = max(maxi,dp[i]);
	}

	int nos = 0;
	for(int i = 0; i < n ; i++) {
		if(dp[i] == maxi) nos += cnt[i];
	}
	return nos;
	
}
int main() {
	init_code();
	vector<int> nums = {1,3,5,4,7};
	cout << findNumberOfLIS(nums);
	return 0;
}
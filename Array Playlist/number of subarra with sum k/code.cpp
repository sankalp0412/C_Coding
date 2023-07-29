#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

int subarraySum(vector<int> nums, int k) {
	int n = nums.size();
	int sum = 0, ans = 0;
	unordered_map<int,int> mp;
	mp[sum] = 1;
	for(int i = 0; i < n; i++) {
		sum += nums[i];
		int rem = sum - k;
		if(mp.count(rem)){
			ans += mp[rem];
		}
		mp[sum]++;
	}
	return ans;
}
int main() {
	init_code();
	vector<int> nums = {1,2,3,-3,1,1,1,4,2,-3};
	cout << subarraySum(nums,3);
	return 0;
}
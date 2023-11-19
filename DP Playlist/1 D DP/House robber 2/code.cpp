#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
// #define fo(i,n) for(int i = 0; i < n; i++) ;
int solve(vector<int> &nums) {
int prev = nums[0];
    int prev2 = 0;
    for(int i = 1; i < nums.size(); i++) {
        int take = nums[i] + prev2;
        int notTake = prev;

        int currMax = max(take,notTake);
        prev2 = prev;
        prev = currMax;
    }
    return prev;
}
int rob(vector<int> &nums) {
	vector<int> temp1,temp2;
	if(nums.size() == 1) return nums[0];
	if(nums.size() == 2) return max(nums[0],nums[1]);
	for(int i = 0 ; i < nums.size(); i++) {
		if(i != 0) temp1.push_back(nums[i]);
		if(i != nums.size() - 1) temp2.push_back(nums[i]);
	}
	return max(solve(temp1),solve(temp2));
}
int main() {
	init_code();
	vector<int> nums = {2,3,2};
	cout << rob(nums);
	return 0;
}
#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int solve(vector<int> &nums) {
	int i = 0;
	for(int j = 0; j < nums.size(); j++) {
		if(nums[j]  !=  nums[i]) {
			nums[i+1] = nums[j];
			i++;
		}
	}
	return i+1;
}
int main() {
	init_code();
	vector<int> nums = {1,2,2,3,3,3,4,4,5};
	cout << solve(nums);
	return 0;
}


//Time complexity: On
// SC: O(1);
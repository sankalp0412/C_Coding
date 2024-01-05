#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int lengthOfLIS(vector<int>& nums) {
      
}
int main() {
	init_code();
	vector<int> nums = {10,9,2,5,3,7,101,18};
	cout << lengthOfLIS(nums);
	return 0;
}
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
    int alternatingSubarray(vector<int>& nums) {
      int n = nums.size();
    if (n < 2)
        return -1;

    int start = 0;  // starting index of the current subarray
    int prev_diff = 0;  // previous difference between consecutive elements
    int max_length = -1;  // maximum length of an alternating subarray

    for (int i = 1; i < n; i++) {
        int curr_diff = nums[i] - nums[i - 1];

        if (prev_diff == 0) {
            prev_diff = curr_diff;
        } else if (curr_diff == -prev_diff) {
            continue;
        } else {
            start = i;
            prev_diff = curr_diff;
        }

        int length = i - start + 1;
        max_length = max(max_length, length);
    }

    return max_length;
    }
};
int main() {
	init_code();
	Solution solution;
	vector<int> nums = {21,9,5};
	cout << solution.alternatingSubarray(nums);
	return 0;
}
#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
  int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX, curr = 0, i = 0, j = 0, n = nums.size();
        bool flag = true;
        
        while (i < n && j < n) {
            if (flag)
                curr += nums[j];
            
            if (curr < target && j < n - 1) {
                j++;
                flag = true;
            } else if (curr >= target) {
                ans = min(ans, j - i + 1);
                curr -= nums[i];
                i++;
                flag = false;
            } else { // curr < target and j == n - 1 //we can't add any more so it will just keep on decreasing hence we break
                break;
            }
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
int main() {
	init_code();
	vector<int> nums = {2,3,1,2,4,3};
	int target = 7;
	cout << minSubArrayLen(target, nums) << endl;
	return 0;
}
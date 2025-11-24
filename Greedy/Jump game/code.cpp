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
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goal = n-1;
        int i = n-1;
        while(i >= 0) {
            if(i + nums[i] >= goal){
                goal = i;
            }
            i--;
        }
        return goal == 0;
    }
};
int main() {
	init_code();
    vector<int> nums = {2,3,3,1,4};
    Solution sol;
    cout << sol.canJump(nums);
	return 0;
}


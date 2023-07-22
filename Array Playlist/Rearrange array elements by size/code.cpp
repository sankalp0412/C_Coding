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
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int pos = 0, neg = 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] < 0){
                ans[neg] = nums[i];
                neg += 2;
            }
            else {
                ans[pos] = nums[i];
                pos += 2;
            }
        }
        return ans;
    }
};
int main() {
	init_code();
	Solution solution;
	vector<int> nums = {3,1,-2,-5,2,-4};
	nums = solution.rearrangeArray(nums);
	for(auto x: nums)
		cout << x << endl;
	return 0;
}

//brute force was to use two arrays with SC o(n);
//TC is o(2n) in brute

//now tc is O(n);


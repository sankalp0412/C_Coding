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
    vector<int> productExceptSelf(vector<int>& nums) {
        // ps 1,1,2,6
        // ss 24,12,4,1
        int n= nums.size();
        // vector<int> pp(n),sp(n);
        vector<int> ans(n,1);
        int curr= 1;
        for(int i = 0; i < n; i++) {
            ans[i] *= curr;
            curr *= nums[i];
        }
        curr = 1;
        for(int i = n-1; i >= 0; i--) {
            ans[i] *= curr;
            curr *= nums[i];
        }


        return ans;
    }
};
int main() {
	init_code();
    Solution sol;

    vector<int> nums = {1,2,3,4};
    vector<int> result = sol.productExceptSelf(nums);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}

/*
Now, at any index i our final answer ans[i] 
would be given by ans[i] = pre[i] * suff[i]. 
Why? Because the pre[i] * suff[i] contains 
product of every element before i and every 
element after i but not the element at index i 
(and that is the reson why we excluded a[i] in 
our prefix and suffix product).

The Time Complexity would be O(n), but we are now using
 Auxilary Space of O(n) (excluding the final answer array).

 WE can further optimize the space by directly putting hte answer
 in the final array.
*/
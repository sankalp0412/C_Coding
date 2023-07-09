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
        int ans = INT_MIN;
        int i = 0, j = 1;
        for(int k = 0; k < nums.size();k++) {
            i = k, j = k+1;
            int tempI = nums[i];
            int tempJ = nums[j];
            while(j < nums.size() && (nums[i] + 1 == nums[j]) && (tempI == nums[i]) && tempJ == nums[j]){
            	i+=2;
                j+=2;
            }
            i-=2;
            j-=2;
            ans = max(ans,(j-k)+1);
        }
        return ans;
    }
};
int main() {
	init_code();
	Solution solution;
	vector<int> nums = {4,5,6};
	cout << solution.alternatingSubarray(nums);
	return 0;
}
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
    int longestSubarray(vector<int>& nums) {
        int maxElem = *max_element(nums.begin(),nums.end());
        int len = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++){
            while( i < nums.size() && nums[i] == maxElem ) {
                len++;
                i++;
            }
            ans = max(ans,len);
            len = 0;
        }
        return ans;
    }
};
int main() {
	init_code();
	Solution sol;
	vector<int> nums = {1,2,3,3,2,2};
	cout << sol.longestSubarray(nums);
	return 0;
}

// the bitwise AND of two different numbers will always be strictly less than the maximum of those two numbers. -  Longest Subarray With Maximum Bitwise AND

// So basically if i and any two numbers or more in the array, the answer will 
// keep becoming less, the best chance we have is to use the maximum element in the array
// {1,10,2,4,100} in this case our answer will be only len 1 i.e. 100, as if 
// we do its and with any other element it will only decrase 
// So we just need to find the maximium length of all the consecutive occurences
// of the maximum element
// {1,2,3,41,100,101} here answer will be 101
// {1,2,3,4,6,100,100,100,101,} here also 101
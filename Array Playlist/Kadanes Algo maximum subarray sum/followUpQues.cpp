//in the followip up question we need to print the subarray as well
//every time we are initializing the sum to zero 
// we are staring a new subarray
// so we can keep track of that

#include "bits/stdc++.h"
using namespace std;
//Leetcode question
class Solution {
public:
    vector<int> maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, sum = 0;
        int ansStart = -1, ansEnd = -1, start = -1;;
        for(int i = 0; i < nums.size(); i++) {
            if(sum == 0)
                start = i;
            sum += nums[i];
            if(sum > ans) {
                ansStart = start ;
                ansEnd = i;
            }
            if(sum < 0) sum = 0;
        }
        vector<int> temp;
        while(ansStart <= ansEnd){
            temp.push_back(nums[ansStart++]);
        }
        return temp;
    }
};
void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

int main() {
	init_code();
	vector<int> vec = {-2,-3,4,-1,-2,1,5,-3};
	// vector<int> nums = {-4,-2,-3,-1};
	Solution solution;
	solution.maxSubArray(vec);
	// cout << solution.codingNinjasSameQuestion(nums) << endl;
	return 0;
}
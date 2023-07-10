// here we will keep track of sum while tracersing 
// we wll neglect if that sum < 0 as on a large scale
// if i will inlcude that sum (subarra) it will only make my 
// total sum less


#include "bits/stdc++.h"
using namespace std;
//Leetcode question
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans = max(ans,sum);
            if(sum < 0) sum = 0;
        }
        return ans;
    }
    //in the coding ninjas similar question it says to find max subarray including EMPTY SUBARRAY
int codingNinjasSameQuestion(vector<int> &nums) {
	    int ans = INT_MIN, sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans = max(ans,sum);
            if(sum < 0) sum = 0;
        }
        return ans < 0 ? 0: ans;
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
	vector<int> nums = {-4,-2,-3,-1};
	Solution solution;
	cout << solution.maxSubArray(vec) << endl;
	cout << solution.codingNinjasSameQuestion(nums) << endl;
	return 0;
}
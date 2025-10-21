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
    //but this is not constant extra space.
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> mp;
        int n = numbers.size();
        for(int i = 0; i < n; i++) {
            int curr = numbers[i];
            int diff = target - curr;
            if(mp.count(diff))
                return {mp[diff] + 1, i + 1 };
            
            mp[curr] = i;
        }
        return {};
    }
    vector<int> twoSumOptimal(vector<int>& numbers, int target) {
        int n = numbers.size();
        int right = n-1;
        int left = 0;
        while(left <= right) {
            int currentSum = numbers[left] + numbers[right];
            if(currentSum == target)
                return {left +1 , right + 1};
            
            else if(currentSum > target) 
                right--;
        
            else 
                left++;
            
        }
        return {};
    }
};


int main() {
	init_code();
    Solution sol;
    vector<int> nums = {2,7,11,15};
    vector<int> ans = sol.twoSumOptimal(nums,9);
    for(auto x: ans) {
        cout << x << ",";
    }
	return 0;
}
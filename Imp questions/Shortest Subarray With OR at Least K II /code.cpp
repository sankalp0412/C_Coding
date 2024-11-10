//the property here is that , if we continously or a number
// the or will continously increase or stay same, it will never
// decrease.

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

 void fn(int num, vector<int> &vec, int val) {
        for(int i = 0; i < 32; i++) {
            if((num >> i ) & 1) {
                vec[i] += val;
            }
        }
    }
    int decimal(vector<int> &vec) {
        int res = 0;
        for(int i = 0; i < 32; i++) {
           if(vec[i] > 0) {
                res |= (1 << i);
           }
        }
        return res;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;

        int i = 0, j = 0;
        vector<int> vec(32,0);
        while(j < n) {
            fn(nums[j],vec,1);
            while(i <= j && decimal(vec) >= k) {
                ans = min(ans,j-i+1);
                fn(nums[i],vec,-1);
                i++;
            }
            j++;
        }
        return ans == INT_MAX ? -1: ans;
    }
int main() {
	init_code();
	vector<int> nums = {3,2,1,5};
	cout << minimumSubarrayLength(nums,6);
	return 0;
}
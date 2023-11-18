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
	int solveSlidingWindow(vector<int>& nums, int k) {
		sort(nums.begin(),nums.end());

		int n = nums.size();

		int res = 0;

		int l = 0;
		long currSum = 0;

		for(int r = 0; r < n; r++) {
			long target = nums[r];
			currSum += nums[r];

			while((r-l+1) * target - currSum > k) { //window shrink
				currSum -= nums[l];
				l++;				
			}

			res = max(res,r-l+1);
		}
		return res;
	}
	int bs(int target_idx, int k, vector<int> &nums, vector<long> &ps) {
		int target = nums[target_idx];

		int l = 0, r = target_idx;

		int bestIndex = target_idx;
		while(l <= r) {
			int mid = l + (r-l)/2;

			int count = (target_idx - mid + 1);
			long windoSum = count * target; //what would be the sum if all are equal to target

			long currSum = ps[target_idx] - ps[mid] + nums[mid];

			int ops = windoSum - currSum;
			if(ops > k)
				l = mid + 1;
			else 
				r = mid - 1;
		}
		return target_idx - l +1;
	}
    int maxFrequency(vector<int>& nums, int k) {
        //more chances to get a best answer is to make the values 
        //to a value that is already present in the array

        //sorting is required as since we only have option to increment
        // a particular value can only be reached by doing operations on a value that is 
        //less than it, so we will sort
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = INT_MIN;
        vector<long> ps(n);
        ps[0] = nums[0];
        for(int i = 1; i < n; i++) 
        	ps[i] = ps[i-1] + nums[i];
        for(int target_idx = 0; target_idx < n; target_idx++) {
            ans = max(ans,bs(target_idx,k,nums,ps));
        }
        return ans;
    }
};
int main() {
	init_code();
	vector<int> nums = {1,4,8,13};
	int k = 5;
	Solution sol;
	cout << sol.solveSlidingWindow(nums,k);
	return 0;
}


//for an array {1,4,8,13} k = 5
//if we need to find the number of operation required to convert to a target lets say 8
//for i = 0, j = 2
//if all these are 8 the actual sum will be equal to 8 * (j-i + 1) = 8 * 3 = 24

//but what is the current sum = 1+4+8 = 13 
//the number of ops = 24 - 13 > k (5) so not possible so we will chagne the window of binary search
// TC: O(n * LogN)
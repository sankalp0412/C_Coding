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
    int firstOcc(vector<int> nums,int target) {
        int n = nums.size();
        int low = 0, high = n -1;
        int first = -1;
        while(low <= high) {
            int mid = (low + high)/2;
            if(nums[mid] == target) {
                first = mid;
                high = mid -1;
            }
            else if(nums[mid] > target)
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return first;
    }
    int lastOcc(vector<int> nums,int target) {
        int n = nums.size();
        int low = 0, high = n -1;
        int last = -1;
        while(low <= high) {
            int mid = (low + high)/2;
            if(nums[mid] == target) {
                last = mid;
                low = mid + 1;
            }
            else if(nums[mid] > target)
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOcc(nums,target);
        if(first == -1) return {-1,-1};
        int last = lastOcc(nums,target);
        return {first,last};
    }
};
int main() {
	init_code();
	Solution solution;
	vector<int> arr = {1,2,3,4,4,4,4,4,4,5,6};
	vector<int> ans = solution.searchRange(arr,4);
	cout << ans[0] << "," << ans[1];
	return 0;
}
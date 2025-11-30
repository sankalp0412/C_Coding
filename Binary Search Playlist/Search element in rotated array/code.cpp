#include "bits/stdc++.h"
using namespace std;

#define for(i,n) for(int i = 0; i < n; i++)

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high) {
            int mid = (low + high) /2;
            if(nums[mid] == target)
                return mid;
            //check which half is sorted;
            if(nums[low] <= nums[mid]) { //left half is sorted
                if(nums[low] <= target && nums[mid] >= target) {
                    //left half is sorted and the element is in that half
                    high = mid -1;
                }
                else {
                    //left half is sorted and hte element is not in that half
                    low = mid + 1;
                }
            }
            else {
                if(nums[mid] <= target && nums[high] >=target)
                    low = mid + 1;
                else 
                    high = mid - 1;
            }   
        }
        return -1;
    }
int main() {
	init_code();
	vector<int> nums = {7,8,9,1,2,3,4,5,6};
	int target = 1;
	cout << search(nums,target);
	return 0;
}
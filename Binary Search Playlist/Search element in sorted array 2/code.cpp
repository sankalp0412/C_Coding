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
 bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high) {
            int mid = (low + high) /2;
            if(nums[mid] == target)
                return true;
            //check which half is sorted;
            if(nums[mid] == nums[low] && nums[high] == nums[mid]) {
                high-=1;
                low += 1;
                continue;
            }
            if(nums[low] <= nums[mid]) { //left half is sorted
                if(nums[low] <= target && nums[mid] >= target) {
                    high = mid -1;
                }
                else {
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
        return 0;
    }
int main() {
	init_code();
	vector<int> vec = {2,5,6,0,0,1,2};
	int target = 0;
	cout << search(vec,target);
	return 0;
}
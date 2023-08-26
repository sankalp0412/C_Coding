#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
 bool possible(vector<int> &nums, int threshold, int div) {
        int sum = 0;
        for(auto x: nums) sum += ceil( (double)x/(double)div);
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        // int minDiv = *min_element(nums.begin(),nums.end());
	    int maxDiv = *max_element(nums.begin(),nums.end());
        int low = 1;
        int high = maxDiv;
        int mid ;
        while(low <= high) {
            int mid = (low + high) /2;
            if(possible(nums,threshold,mid))
                high = mid-1;
            else 
                low = mid + 1;
        }
    return low;
    }
int main() {
	init_code();
	vector<int> nums = {1,2,5,9};
	int limit = 6;
	cout << smallestDivisor(nums,limit);
	return 0;
}
//here we kind of have a hint in the constraints 
//it says : nums.length <= threshold <= 106
// so the minimum value of the threshold will be the size
//of the array i.e in optimal condition if we are getting
// all 1 (which is possible after dividing it with the max value in array greater than that)
//after dividing the sum will be the size of array
// hence in most optimal condition the threshold should
// at least be nums.length
//so max value for binary search will be the max element in array
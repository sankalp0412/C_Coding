/*Given an integer array nums, return the number of all the arithmetic subsequences of nums.

A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.
A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.

For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
The test cases are generated so that the answer fits in 32-bit integer. */

// --------

// So for this question initially I tried with Recursion and failed 
// as brute force recursion will lead to checking all the possible 
// subsequences, so for n = 1000 (as per the constraints)
// the number of subsequences will be very large (2^n) will not come in INT.
// Hence direct recursion will not work.

//TC for brute force will be 
// 2^n for all subsequences 
// O(n) to check wheather a subsequece is arithematic
// so O(2^n * n);

//Better approach
// for current i index, we will check all the previous index j
// such that if there exists s subsequecnes (f) ending at index j
// whose diff is 'd' (nums[i] - nums[j])
// if at j already there were f subsequences ending then we will add.
// f to the answer (Check screenshot)


//https://www.youtube.com/watch?v=cau0JE1q_ZA

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
 int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        unordered_map<long,int> mp[n];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++) {
                long currDiff = (long)nums[i] - nums[j];
                
                auto it = mp[j].find(currDiff);

                int cntAtJ = it == mp[j].end() ? 0: it -> second;

                mp[i][currDiff] += cntAtJ + 1;

                ans += cntAtJ;
            }
        }
    return ans;
    }
int main() {
	init_code();
	vector<int> nums = {2,4,6,8,10};
	cout << numberOfArithmeticSlices(nums);
	return 0;
}

//What i did earlier myself was and it was failing and giving TLE:
//This is code 1 and above is code 2
/*class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        unordered_map<long,int> mp[n];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++) {
                long currDiff = (long)nums[i] - nums[j];
                int countAtJ = 0;
                auto cdAtj = mp[j]; //map at j

                if(cdAtj.count(currDiff))
                    countAtJ += cdAtj[currDiff];

                mp[i][currDiff] += countAtJ + 1;

                ans += countAtJ;
            }
        }
    return ans;
    }
};*/


// In Code 1, the line auto cdAtj = mp[j]; creates a copy of the entire map at index j. 
// This means that you are creating and copying the entire map in each iteration of the inner loop,
//  which can result in higher time complexity, especially when the map size is large.

// On the other hand, Code 2 uses auto it = mp[j].find(currDiff); to directly access the iterator 
 // of the map at index j. This avoids creating a copy of the entire map, and the code directly accesses
 //  the required element using the iterator. This can be more efficient, especially when dealing with larger maps.

// So, Code 2 is likely more optimized than Code 1 due to the avoidance of unnecessary map copies.
//  This difference in performance might be more pronounced when the input size is large. Always consider 
//  the efficiency of data structures and their usage when dealing with algorithmic problems.
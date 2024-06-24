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
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> ms;

        int left = 0, ans = 0;

        for(int right = 0; right < nums.size(); right++){
            ms.insert(nums[right]);
            
            while(*ms.rbegin() - *ms.begin() > limit) {
                ms.erase(ms.find(nums[left]));   //erase only one occurence of the element

                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
int main() {
	init_code();
	vector<int> nums = {8,2,4,7};
	int limit = 4;
	Solution sol;
	cout << sol.longestSubarray(nums,limit);
	return 0;
}



// ms.end() initially points to the theoretical element.
// Decrementing it makes it point to the last real element in the container.
// Dereferencing ms.end() directly would be incorrect and lead to undefined behavior

// ms.rbegin() provides a reverse iterator to the last element
// if auto it = ms.rbegin()  doing it++ will traverse backwards

// Multisets are a type of associative containers similar to
 // the set, with the exception that multiple elements can have the same values
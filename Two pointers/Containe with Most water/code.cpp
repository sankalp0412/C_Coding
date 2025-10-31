// Area formula: A = min(hL, hR) * (R - L)
// Assume hL < hR, so A = hL * (R - L)

// Move the taller pointer (right one):
// New right index = R' = R - 1
// New area A' = min(hL, hR') * (R' - L)

// Case 1: hR' >= hL
// Then min(hL, hR') = hL
// => A' = hL * (R' - L).  - 1
// Since R' - L < R - L, area strictly decreases

// Case 2: hR' < hL
// Then min(hL, hR') = hR'
// => A' = hR' * (R' - L)
// But hR' < hL and (R' - L) < (R - L)
// => Both height and width decrease → area decreases again, from 1, basically we try further decrease the area since hR' is even smaller

// Conclusion:
// Moving the taller pointer always reduces (or keeps same) area.
// Only moving the shorter pointer can potentially increase min(height),
// which is the bottleneck for the area.

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
    int maxArea(vector<int>& height) {
        int area = 0, n = height.size();
        int l = 0, r=n-1;
        while(l < r) {
            int length = min(height[l], height[r]);
            int width = r-l;

            area = max(area, length * width);

            if (height[l] < height[r])
                l++;
            else 
                r--;
        }
        return area;

        
    }
};


int main(){
    Solution sol;
    vector<int> nums = {1,8,6,2,5,4,8,3,7};
    cout << sol.maxArea(nums);

    return 0;
}
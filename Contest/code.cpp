#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minSwapsAlternateParity(const vector<int>& nums) {
        int n = nums.size();
        vector<int> posE, posO;
        posE.reserve(n);
        posO.reserve(n);
        // collect the positions of evens and odds
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0)
                posE.push_back(i);
            else
                posO.push_back(i);
        }
        int e = posE.size(), o = posO.size();
        // impossible if counts differ by more than 1
        if (abs(e - o) > 1) return -1;
        
        // helper: cost to line up the given positions vector at 0,2,4,...
        auto cost_to_start_at_zero = [&](const vector<int>& P) {
            long long cost = 0;
            for (int i = 0; i < (int)P.size(); i++) {
                int target = 2 * i;
                cost += llabs(P[i] - target);
            }
            return cost;
        };
        
        // if more evens, we must start with even at index 0
        if (e > o) {
            return cost_to_start_at_zero(posE);
        }
        // if more odds, we must start with odd at index 0
        if (o > e) {
            return cost_to_start_at_zero(posO);
        }
        // if equal, try both and take min
        long long costStartEven = cost_to_start_at_zero(posE);
        long long costStartOdd  = cost_to_start_at_zero(posO);
        return min(costStartEven, costStartOdd);
    }
};

// Example usage (LeetCode style):
int main() {
    Solution sol;
    vector<int> nums = {2,4,6,5,7};
    cout << sol.minSwapsAlternateParity(nums) << "\n";  // outputs 3
    return 0;
}

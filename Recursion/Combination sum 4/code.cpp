#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1,0);
        dp[0] = 1;
        for(int i = 1; i <= target; i++) {
            for(auto x: nums) {
                if(i - x >= 0){
                    dp[i] += dp[i-x];
                }
            }
        }
        return dp[target];
    }
int main() {
	init_code();
	vector<int>arr = {1,2,3};
	int target = 4;
	cout << combinationSum4(arr,target);
	return 0;
}

//here we are using unsigned INT for dp as for higher input 
//we were getting the below error:
// Line 9: Char 27: runtime error: signed integer overflow: 2147483647 + 1 cannot be represented in type 'int' (solution.cpp)
// SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:18:27
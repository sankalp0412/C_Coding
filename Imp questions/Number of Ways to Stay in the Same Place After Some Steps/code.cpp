// You have a pointer at index 0 in an array of size arrLen. At each step, 
// you can move 1 position to the left, 1 position to the right in the array,
//  or stay in the same place (The pointer should not be placed outside the 
//  	array at any time).
// Given two integers steps and arrLen, return the number of ways such 
// that your pointer is still at index 0 after exactly steps steps. Since
//  the answer may be too large, return it modulo 109 + 7.



#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
class SolutionMemo {
public:
    int mod = 1e9 + 7;
    int solve(int steps, int index ,int &n, vector<vector<int>> &memo) {
        if(index < 0 || index >= n || steps < 0)
            return 0;
        if(steps == 0 && index == 0)
            return 1;

        if(memo[steps][index] != -1)
            return memo[steps][index];
        int goLeft,goRight,stay;
        goLeft = solve(steps-1,index-1,n,memo) % mod ;
        goRight = solve(steps-1,index+1,n,memo) % mod;
        stay = solve(steps-1,index,n,memo) % mod;
        
        int TotalWays = (goLeft + goRight) % mod;
        TotalWays = (TotalWays + stay) % mod; 
        return memo[steps][index] = TotalWays % mod;
    }
    int numWays(int steps, int arrLen) {
        vector<vector<int>> memo (steps + 1, vector<int> (arrLen + 1,-1));
        return solve(steps,0,arrLen,memo);
    }
};
class Solution {
public:
    int numWays(int steps, int arrLen) {
        int mod = 1e9 + 7;
        arrLen = min(steps,arrLen); 
        vector<vector<int>> dp (steps + 1, vector<int> (arrLen + 1, 0));
        dp[0][0] = 1;
        for(int step = 1; step <= steps; step++) {
            for(int index = 0; index < arrLen; index++) {
                int ways = 0;
                ways = (ways + dp[step-1][index]) % mod; 
                if(index != 0)
                    ways = (ways + dp[step-1][index-1]) % mod;
                if(index != arrLen-1)
                    ways = (ways + dp[step-1][index+1]) % mod;

                dp[step][index] = ways % mod; 
            }
        }
        return dp[steps][0];
    }
};
int main() {
	init_code();
	SolutionMemo memo;
	Solution sol;
	cout << memo.numWays(4,3) << endl;
	cout << sol.numWays(4,3) << endl;
	return 0;
}


//here i was getting TLE as i missed this very important line 40
//ArrLen should be min of steps or arrLen as 
//if Steps < arrLen after certain point of time if i choose all right
//i will have no more steps, hence there is no point calculating after
//that index.
//eg: if my arraLEn = 10 ans steps = 3, i can't reach beyond the third index


// Complexity Analysis

// Given n as steps and m as arrLen,

// Time complexity: O(n * min⁡(n,m))

// Our nested for-loops iterate over O(n⋅min⁡(n,m))

// Space complexity: O(min⁡(n,m))
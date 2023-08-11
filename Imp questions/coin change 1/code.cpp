#include "bits/stdc++.h"
using namespace std;

// #define for(i,n) for(inst i = 0; i < n; i++)

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

class Solution {
public:
	int solveMemo(vector<int> &dp, vector<int> &coins, int amount) {
			if(amount == 0) return 0;
			if(amount < 0) return INT_MAX;

			if(dp[amount] != -1)
				return dp[amount];

			int res = INT_MAX;

			for(int i = 0; i < coins.size(); i++) {
				int temp = solveMemo(dp,coins,amount-coins[i]);
				if(temp != INT_MAX)
					res = min(res, temp+1);
			}
			return dp[amount] = res;
		}
	int solve(int numOfCoins, vector<int> &coins, int currAmount) {
		//base
		if(currAmount == 0) 
			return numOfCoins;

		int res = INT_MAX;
		for(int i = 0; i < coins.size(); i++) {
			if(currAmount - coins[i] >= 0){
				res = min(res,solve(numOfCoins+1,coins,currAmount - coins[i]));
			}
		}
		return res;
		
	}
    int coinChange(vector<int>& coins, int amount) {
        // int ans = INT_MAX;
        // return solve(0,coins,amount);
        //For Memo:
        vector<int> dp(amount+1,-1);
        int ans = solveMemo(dp,coins,amount);
				if(ans == INT_MAX)
					return -1;
				return ans;
    }
};

int main() {
	init_code();
	Solution solution;
	vector<int> coins = {1,2,5};
	int target = 11;
	cout << solution.coinChange(coins,target);
	return 0;
}
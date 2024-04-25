#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
 int dp[301][5001];
    int solveMemo(int idx, int amount, vector<int> coins) {
        if(amount == 0)
            return 1;
        if(idx == 0)
            return (amount % coins[idx] == 0);
        
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int take = 0, notTake;

        if(coins[idx] <= amount)
            take = solveMemo(idx, amount - coins[idx], coins);
        notTake = solveMemo(idx -1 , amount, coins);

        return dp[idx][amount] = take + notTake;
    }
int solveTabulation(int amount, vector<int>& coins) {
	int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount + 1, 0));
        for(int t = 0; t <= amount; t++)
            dp[0][t] = (t % coins[0] == 0);
          
        for(int idx = 1; idx < n; idx++) {
            for(int amt = 0; amt <= amount; amt++) {
                int take = 0, notTake;
                if(coins[idx] <= amt)
                    take = dp[idx][amt - coins[idx]];
                notTake = dp[idx-1][amt];

                dp[idx][amt] = take + notTake;
            }
        }
        return dp[n-1][amount];
}

int solveSpaceOptm(int amount, vector<int>& coins) {
	int n = coins.size();
        vector<int> prev(amount + 1, 0),curr(amount + 1,0);
        for(int t = 0; t <= amount; t++)
            curr[t] = (t % coins[0] == 0);
          
        	prev = curr;
        for(int idx = 1; idx < n; idx++) {
            for(int amt = 0; amt <= amount; amt++) {
                int take = 0, notTake;
                if(coins[idx] <= amt)
                    take = curr[amt - coins[idx]];
                notTake = prev[amt];

                curr[amt] = take + notTake;
            }
            prev = curr;
        }
        return curr[amount];
}
int change(int amount, vector<int>& coins) {
	int n = coins.size();
    memset(dp,-1,sizeof(dp));
    // return solveMemo(n-1,amount,coins);
    // return solveTabulation(amount,coins);
    return solveSpaceOptm(amount,coins);
}
int main() {
	init_code();
	int amount = 5;
	vector<int> coins = {1,2,5};
	cout << change(amount,coins);
	return 0;
}
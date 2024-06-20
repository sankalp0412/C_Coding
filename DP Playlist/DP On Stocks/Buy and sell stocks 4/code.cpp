//same as buy and sell stock 3 only now the transaction limit will be k instead of 2
// another way of solving this problem and the one before is to use a variable 
//to track the transaction sequence , even will mean buy and odd will mean sell
//0 - Buy
//1 - Sell
// 2 - Buy
// 3 - sell
#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int solveMemo(int idx, vector<int> &prices, int transNum,vector<vector<int>> &dp, int k) {
        if(idx >= prices.size() || transNum == 2*k)
            return 0;
        if(dp[idx][transNum] != -1)
            return dp[idx][transNum];
        if(transNum % 2 == 0)
            return dp[idx][transNum] = max(-prices[idx] + solveMemo(idx + 1,prices,transNum + 1, dp, k), solveMemo(idx + 1,prices,transNum, dp,k));
        else
            return dp[idx][transNum] = max(prices[idx] + solveMemo(idx +1 , prices, transNum + 1, dp, k), solveMemo(idx + 1, prices,transNum, dp , k));

        return -1;   
            
    }

int tabulation(vector<int> &prices , int k) {
	int n = prices.size();
	vector<vector<int>> dp(n+1, vector<int> (2*k + 1,0));

	for(int i = n-1; i >= 0; i--){
		for(int t = 2*k - 1; t >= 0; t--){
			if(t % 2 == 0)
            	dp[i][t] = max(-prices[i] + dp[i+1][t+1], dp[i+1][t]);
        	else
            	dp[i][t] = max(prices[i] + dp[i+1][t+1], dp[i+1][t]);
		}
	}
	return dp[0][0];
}

int spaceOpt(vector<int> &prices , int k) {
	int n = prices.size();
	vector<int> curr(2*k + 1,0);
	vector<int> ahead(2*k + 1,0);

	for(int i = n-1; i >= 0; i--){
		for(int t = 2*k - 1; t >= 0; t--){
			if(t % 2 == 0)
            	curr[t] = max(-prices[i] + ahead[t+1], ahead[t]);
        	else
            	curr[t] = max(prices[i] + ahead[t+1], ahead[t]);
		}
		ahead = curr;
	}
	return curr[0];
}
int maxProfit(int k, vector<int>& prices) {
	int n = prices.size();
	vector<vector<int>> dp(n, vector<int> (2*k + 1,-1));
	// return solveMemo(0,prices,0,dp,k);
	// return tabulation(prices,k);
	return spaceOpt(prices,k);
}
int main() {
	init_code();
	vector<int> prices = {3,2,6,5,0,3};
	int k = 2;
	cout << maxProfit(k,prices);
	return 0;
}
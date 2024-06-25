#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int solveMemo(int idx, vector<int> &prices, bool buy,vector<vector<int>> &dp, int &fee) {
       if(idx >= prices.size()) return 0;
       if(dp[idx][buy] != -1) 
           return dp[idx][buy];
       
       int ans = INT_MIN;
       if(buy)
       		ans = max(solveMemo(idx + 1,prices,false,dp,fee) - prices[idx],solveMemo(idx +1, prices, buy,dp,fee));
       else //the only change we are going to do is subtract the fee after the transaction, rest of the code is same as II
        	ans = max(solveMemo(idx + 1, prices, true,dp,fee) + prices[idx] - fee,solveMemo(idx +1, prices, buy,dp,fee));

       return dp[idx][buy] = ans;
}
int maxProfit(vector<int>& prices, int fee) {
	int n = prices.size();
    vector<vector<int>> dp(n,vector<int> (2,-1));
    return solveMemo(0, prices, false,dp,fee);
}
int main() {
	init_code();
	vector<int> prices = {1,3,2,8,4,9};
	int fee = 2;
	cout << maxProfit(prices,fee);
	return 0;
}
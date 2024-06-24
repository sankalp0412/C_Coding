//Q-  After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).


#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
 int solveMemo(int idx, vector<int> &prices, bool buy,vector<vector<int>> &dp) {
        if(idx >= prices.size()) return 0;
        if(dp[idx][buy] != -1) 
            return dp[idx][buy];
        
        int ans = INT_MIN;
        if(buy)
        	ans = max(solveMemo(idx+ 1,prices,false,dp) - prices[idx],solveMemo(idx +1, prices, buy,dp));
        else 
            ans = max(solveMemo(idx + 2, prices, true,dp) + prices[idx],solveMemo(idx +1, prices, buy,dp));
      		//this is the only change that we will make, now we will just go to idx + 2 instead of 1 because of cooldown
            // After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).


        return dp[idx][buy] = ans;
    }

int tabulation(vector<int> &prices){
	int n = prices.size();
	vector<vector<int>> dp(n+2,vector<int> (2,0)); //n+2 to avoid error of. accessing outside the sizea as we are checking for idx + 2

	for(int idx = n-1; idx >= 0; idx--){
		for(int buy = 0; buy < 2; buy++) { //we can also ommit this for loop as well and write 0,1 in place of buy
			int ans = INT_MIN;
	        if(buy)
	        	ans = max(dp[idx+ 1][false] - prices[idx],dp[idx+1][buy]);
	        else 
	            ans = max(dp[idx+2][true] + prices[idx],dp[idx+1][buy]);

	        dp[idx][buy] = ans;
	    }
	}
	return dp[0][1];
}

int spaceOptimization(vector<int> &prices){
	int n = prices.size();
	vector<int> curr(2,0); //n+2 to avoid error of. accessing outside the sizea as we are checking for idx + 2
	vector<int> front1(2,0);
	vector<int> front2(2,0);
	for(int idx = n-1; idx >= 0; idx--){
		for(int buy = 0; buy < 2; buy++) { //we can also ommit this for loop as well and write 0,1 in place of buy
			int ans = INT_MIN;
	        if(buy)
	        	ans = max(front1[false] - prices[idx],front1[buy]);
	        else 
	            ans = max(front2[true] + prices[idx],front1[buy]);

	        curr[buy] = ans;
	    }
	    front2 = front1;
	    front1 = curr;
	}
	return curr[1];
}
int maxProfit(vector<int>& prices) {
	int n = prices.size();
	vector<vector<int>> dp(n,vector<int> (2,-1));
	// return solveMemo(0,prices,1,dp);
	// return tabulation(prices);
	return spaceOptimization(prices);
}

int main() {
	init_code();
	vector<int> prices = {1,2,3,0,2};
	cout << maxProfit(prices);
	return 0;
}
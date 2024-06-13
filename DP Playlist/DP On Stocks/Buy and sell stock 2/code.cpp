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
    int solveMemo(int idx, vector<int> &prices, bool stock,vector<vector<int>> &dp) {
        if(idx >= prices.size()) return 0;
        if(dp[idx][stock] != -1) 
            return dp[idx][stock];
        int buy = 0, sell = 0, doNothing = 0;

        if(stock)
            sell = solveMemo(idx +1, prices, false,dp) + prices[idx];
        
        else 
            buy = solveMemo(idx+1,prices,true,dp) - prices[idx];
        
        doNothing = solveMemo(idx +1, prices, stock,dp);

        return dp[idx][stock] = max(buy,max(sell,doNothing));
    }
    int solveTabulation(vector<int> &prices) {
    	//dp[i][buy]
    	//defined what is the max profit i can make from the ith day with option buy to buy
    	int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,0));
        dp[n][0] = dp[n][1] = 0;
        //buy = 0 means i can't buy
        for(int i = n - 1; i >= 0; i--) {
        	for(int buy = 0; buy <= 1; buy++) {
        		int profit = 0;
        		if(buy) 
        			profit = max(dp[i+1][0] - prices[i],dp[i+1][1]);
        		
        		else { //i can sell
        			profit = max(prices[i] + dp[i+1][1], dp[i+1][0]);
        		}	
        		dp[i][buy] = profit;
        	}
        }
        return dp[0][1];  //what is the max profit i can make on day 0 with an option to buy

    }
    int solveSpaceOpt(vector<int> &prices) {
    	int n = prices.size();
        vector<int> ahead(2,0), curr(2,0); //here we can also use 4 variables to do this but that does not optimize it as it is still space of 4
        ahead[0] = ahead[1] = 0;
        //buy = 0 means i can't buy
        for(int i = n - 1; i >= 0; i--) {
        	for(int buy = 0; buy <= 1; buy++) {
        		int profit = 0;
        		if(buy) 
        			profit = max(ahead[0] - prices[i],ahead[1]);
        		
        		else { //i can sell
        			profit = max(prices[i] + ahead[1], ahead[0]);
        		}	
        		curr[buy] = profit;
        	}
        	ahead = curr;
        }
        return curr[1]; 
    }

     int solveVariables(vector<int> &prices) {
    	int n = prices.size();
        long aheadNotBuy = 0, aheadBuy = 0, currBuy,currNotBuy; 
        for(int i = n - 1; i >= 0; i--) {
        	int profit = 0;
        	currBuy = max(aheadNotBuy - prices[i],aheadBuy);
        		
        	//i can sell
        	currNotBuy = max(prices[i] + aheadBuy, aheadNotBuy);
        			
        	aheadBuy = currBuy;
        	aheadNotBuy = currNotBuy;
        }
        return aheadBuy; 
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        // return solveMemo(0, prices, false,dp);
        // return solveTabulation(prices);
        // return solveSpaceOpt(prices);
        return solveVariables(prices);
    }
};
int main() {
	init_code();
	vector<int> prices = {7,1,5,3,6,4};
	Solution sol;
	cout << sol.maxProfit(prices);
	return 0;
}
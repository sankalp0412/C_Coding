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
    int solveMemo(int idx, vector<int> &prices, bool stock,vector<vector<vector<int>>> &dp, int t) {
        if(idx >= prices.size() || !t) return 0;
        if(dp[idx][stock][t] != -1) 
            return dp[idx][stock][t];
        int buy = 0, sell = 0, doNothing = 0;

        if(stock)
            sell = solveMemo(idx +1, prices, false,dp,t-1) + prices[idx];
        
        else 
            buy = solveMemo(idx+1,prices,true,dp,t) - prices[idx];
        
        doNothing = solveMemo(idx +1, prices, stock,dp,t);

        return dp[idx][stock][t] = max(buy,max(sell,doNothing));
    }
    int tabulation(vector<int> &prices) {
    	int n = prices.size();
    	vector<vector<vector<long>>> dp(n + 1,vector<vector<long>>(2,vector<long> (3,0)));
        dp[n][0][2] = dp[n][1][2] = 0;
        //buy = 0 means i can't buy
        for(int i = n - 1; i >= 0; i--) {
        	for(int buy = 0; buy <= 1; buy++) {
	        		for(int t = 1; t <= 2; t++) {
		        		int profit = 0;
		        		if(buy) 
		        			profit = max(dp[i+1][0][t] - prices[i],dp[i+1][1][t]);
		        		
		        		else { //i can sell
		        			profit = max(prices[i] + dp[i+1][1][t-1], dp[i+1][0][t]);
		        		}	
		        		dp[i][buy][t] = profit;
	        	}
        	}
        }
        return dp[0][1][2];
    }
    int spaceOpt(vector<int> &prices) {
    	int n = prices.size();
    	vector<vector<long>> ahead(2,vector<long> (3,0));
    	vector<vector<long>> curr(2,vector<long> (3,0));
        curr[0][2] = curr[1][2] = 0;
        //buy = 0 means i can't buy
        for(int i = n - 1; i >= 0; i--) {
        	for(int buy = 0; buy <= 1; buy++) {
	        		for(int t = 1; t <= 2; t++) {
		        		int profit = 0;
		        		if(buy) 
		        			profit = max(ahead[0][t] - prices[i],ahead[1][t]);
		        		
		        		else { //i can sell
		        			profit = max(prices[i] + ahead[1][t-1], ahead[0][t]);
		        		}	
		        		curr[buy][t] = profit;
	        	}
        	}
        	ahead = curr;
        }
        return curr[1][2];
    }


     int solveNcross4(int idx, vector<int> &prices, int trans,vector<vector<int>> &dp) {
    	if(idx >= prices.size() || trans == 4) return 0;
        if(dp[idx][trans] != -1) 
            return dp[idx][trans];
       	if(trans % 2 == 0) 
       		return dp[idx][trans] = max(solveNcross4(idx + 1,prices, trans+1,dp)-prices[idx] , solveNcross4(idx+1,prices,trans,dp));
       	else
       		return dp[idx][trans] = max(solveNcross4(idx + 1,prices, trans+1,dp)+prices[idx] , solveNcross4(idx+1,prices,trans,dp));

       	//never reach here
       	return 0;
    }


    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int> (3,-1)));
        // return solveMemo(0, prices, false,dp,2);
        // return tabulation(prices);
        // return spaceOpt(prices);
		vector<vector<int>> memo(n,vector<int>(4,-1)); 
		return solveNcross4(0,prices,0,memo);
    }
};
int main() {
	init_code();
	vector<int> prices = {3,3,5,0,0,3,1,4};
	Solution sol;
	cout << sol.maxProfit(prices);
	return 0;
}
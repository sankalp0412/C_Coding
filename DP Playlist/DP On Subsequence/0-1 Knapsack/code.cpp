#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
#include <bits/stdc++.h> 
int dp[101][1001];

//dp[idx][wt] defines
// the max value i can get if i have weight 'wt' left at 
// index 'idx'
// 1,2,3,4
// -----
// dp[2][0] = 0; (how much value i can get from index (0-2) with weight 0)
int solve(int idx, int wt, vector<int> &weight, vector<int> &value) {
	if(wt == 0)
		return 0;
	if(idx == 0)
		return weight[0] > wt ? 0 : value[0];
	if(dp[idx][wt] != -1)
		return dp[idx][wt];
	int take = 0;

	int notTake = solve(idx - 1, wt,weight,value);

	if(weight[idx] <= wt) 
		take = value[idx] + solve(idx - 1, wt - weight[idx], weight, value);

	return dp[idx][wt] = max(take, notTake);
}

int solveTabulation(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<vector<int>> dp(n, vector<int> (maxWeight + 1, 0));
	//base cases
	//0index is done
	//0 weight is also done
        for (int w = weight[0]; w <= maxWeight; w++) 
           dp[0][w] = value[0];        

        for(int i = 1; i < n; i++){
		for(int wt = 1; wt <= maxWeight; wt++) {
			int take = INT_MIN;
			int notTake = dp[i - 1][wt];

			if(weight[i] <= wt)
				take = value[i] + dp[i-1][wt - weight[i]];
			
			dp[i][wt] = max(take,notTake);
		}
	}
	return dp[n-1][maxWeight];
}
int solveSpaceOptmization(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<int> prev(maxWeight + 1,0), curr(maxWeight + 1,0);
        for (int w = weight[0]; w <= maxWeight; w++) {
 	        prev[w] = value[0];
			curr[w] = value[0];
        }

        for(int i = 1; i < n; i++){
            for (int wt = 1; wt <= maxWeight; wt++) {
              int take = INT_MIN;
              int notTake = prev[wt];

              if (weight[i] <= wt)
                take = value[i] + prev[wt - weight[i]];

              curr[wt] = max(take, notTake);
            }
			prev = curr;
        }
        return curr[maxWeight];
}


//we dont require the curr vector
//as we are updating it one by from using the adjacent
//values 
int furtherSpaceOpt(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<int> prev(maxWeight + 1,0);
        for (int w = weight[0]; w <= maxWeight; w++) {
 	        prev[w] = value[0];
		}

        for(int i = 1; i < n; i++){
            for (int wt = maxWeight; wt >= 1; wt--) {
              int take = INT_MIN;
              int notTake = prev[wt];

              if (weight[i] <= wt)
                take = value[i] + prev[wt - weight[i]];

              prev[wt] = max(take, notTake);
            }
			
        }
        return prev[maxWeight];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	memset(dp,-1,sizeof(dp));
	// return solve(n - 1, maxWeight, weight, value);
	// return solveTabulation(weight,value,n,maxWeight);
	// return solveSpaceOptmization(weight,value,n,maxWeight);
	return furtherSpaceOpt(weight,value,n,maxWeight);
}
int main() {
	init_code();
	int n = 7;
	vector<int> weight = {6, 5, 1, 5, 6, 5, 9 }, value = {5, 3 ,4, 9 ,6, 1, 1 };
	int maxWeight = 63;
	cout << knapsack(weight,value,n,maxWeight);
	return 0;
}

//Memo
//TC = O(n * w)
// SC = O(n * w) + O(n) {stack space}
/*
You are given ‘n’ items with certain ‘profit’ and ‘weight’ and a knapsack with weight capacity ‘w’.
You need to fill the knapsack with the items in such a way that you get the maximum profit. You are allowed to take one item multiple times.
*/

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

int solve(int &n, int idx, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &memo) {
	if(idx == 0)
		return ((int)(w/weight[0])) * profit[0];

	if(memo[idx][w] != -1)
		return memo[idx][w];

	int pick = INT_MIN, notPick = 0;

	notPick = solve(n,idx - 1,w,profit,weight,memo);

	if(w >= weight[idx])
		pick = profit[idx] + solve(n,idx,w - weight[idx],profit,weight,memo);

	return memo[idx][w] = max(pick,notPick);
}
int solveTabulation(int n, int wt, vector<int> &profit, vector<int> &weight) {
	vector<vector<int>> dp(n, vector<int> (wt + 1,0));
	for(int w = 0; w <= wt; w++) {
		dp[0][w] = ((int)(w/weight[0])) * profit[0];
	}

	for(int i = 1; i < n; i++) {
		for(int w = 0; w <= wt; w++) {
				int pick = INT_MIN, notPick = 0;
				notPick = dp[i-1][w];
				  if (w >= weight[i]) {
                pick = profit[i] + dp[i][w - weight[i]]; // Use dp[i][...] for unlimited number of the same item
            }

			dp[i][w] = max(pick,notPick);
		}
	}
	return dp[n-1][wt];
}
int solveSpaceOpt(int n, int wt, vector<int> &profit, vector<int> &weight){
	vector<int> prev(wt + 1,0),curr(wt + 1,0);
	for(int w = 0; w <= wt; w++) {
		curr[w] = ((int)(w/weight[0])) * profit[0];
	}

	prev = curr;

	for(int i = 1; i < n; i++) {
		for(int w = 0; w <= wt; w++) {
				int pick = INT_MIN, notPick = 0;
				notPick = prev[w];
				  if (w >= weight[i]) {
                pick = profit[i] + curr[w - weight[i]]; // Use dp[i][...] for unlimited number of the same item
            }

			curr[w] = max(pick,notPick);
		}
		prev = curr;
	}
	return curr[wt];
}

int solveSpaceOpt1Array(int n, int wt, vector<int> &profit, vector<int> &weight){
	vector<int> curr(wt + 1,0);
	for(int w = 0; w <= wt; w++) {
		curr[w] = ((int)(w/weight[0])) * profit[0];
	}

	for(int i = 1; i < n; i++) {
		for(int w = 0; w <= wt; w++) {
				int pick = INT_MIN, notPick = 0;
				notPick = curr[w];
				  if (w >= weight[i]) {
                pick = profit[i] + curr[w - weight[i]]; // Use dp[i][...] for unlimited number of the same item
            }

			curr[w] = max(pick,notPick);
		}
	}
	return curr[wt];
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
	vector<vector<int>> memo(n, vector<int> (w + 1,-1));
	// return solve(n,n-1,w,profit,weight,memo);
	// return solveTabulation(n,w,profit,weight);
	// return solveSpaceOpt(n,w,profit,weight);
	return solveSpaceOpt1Array(n,w,profit,weight);
}


int main() {
	init_code();
	int n = 3, w = 10;
	vector<int> profit = {5,11,13};
	vector<int> weight = {2,4,6};
	cout << unboundedKnapsack(n,w,profit,weight);
	return 0;
}
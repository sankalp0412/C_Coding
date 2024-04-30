/*
Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it. Determine the maximum cost obtained by cutting the rod and selling its pieces.
Note:
1. The sizes will range from 1 to ‘N’ and will be integers.

2. The sum of the pieces cut should be equal to ‘N’.

3. Consider 1-based indexing.
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
int solveMemo(int idx, vector<int> &price, int remSize,vector<vector<int>> &dp) {
	if(idx == 0) 
		return price[0] * remSize; //pick remaining pieces of size 1

	if(dp[idx][remSize] != -1 )
		return dp[idx][remSize];
	int pick = 0, notPick;

	notPick = solveMemo(idx - 1, price,remSize,dp);
	if(remSize >= idx + 1)
		pick = price[idx] + solveMemo(idx, price, remSize - (idx + 1),dp);

	return dp[idx][remSize] = max(pick,notPick);
}

int solveTabulation(vector<int> &price, int n) {
	vector<vector<int>> dp(n, vector<int> (n + 1,0));
	//base
	for(int sz = 1; sz <= n; sz++)
		dp[0][sz] = price[0] * sz;

	for(int i = 1; i < n; i++) {
		for(int sz = 1; sz <= n; sz++) {
			int pick = 0, notPick;
			notPick = dp[i - 1][sz];
			if(sz >= i + 1) 
				pick = price[i] + dp[i][sz - (i + 1)];

			dp[i][sz] = max(pick,notPick);
		}
	}
	// cout  << dp[1][2] << endl;
	return dp[n-1][n];

}


int solveSpaceOptm(vector<int> &price, int n) {
	vector<int> curr(n + 1,0), prev(n+1,0);
	//base
	for(int sz = 1; sz <= n; sz++)
		curr[sz] = price[0] * sz;
	prev = curr;
	for(int i = 1; i < n; i++) {
		for(int sz = 1; sz <= n; sz++) {
			int pick = 0, notPick;
			notPick = prev[sz];
			if(sz >= i + 1) 
				pick = price[i] + curr[sz - (i + 1)];

			curr[sz] = max(pick,notPick);
		}
		prev = curr;
	}
	// cout  << dp[1][2] << endl;
	return curr[n];

}

int solve1DArraySpaceOptm(vector<int> &price, int n) {
	vector<int> curr(n + 1,0);
	//base
	for(int sz = 1; sz <= n; sz++)
		curr[sz] = price[0] * sz;

	for(int i = 1; i < n; i++) {
		for(int sz = 1; sz <= n; sz++) {
			int pick = 0, notPick;
			notPick = curr[sz];
			if(sz >= i + 1) 
				pick = price[i] + curr[sz - (i + 1)]; //if we are subtracing something from the curr sz, it will be less that the current sz

			curr[sz] = max(pick,notPick);
		}
		
	}
	// cout  << dp[1][2] << endl;
	return curr[n];

}

int cutRod(vector<int> &price, int n){
	vector<vector<int>> dp(n, vector<int> (n + 1,-1));
	// return solveMemo(n-1,price,n,dp);
	// return solveTabulation(price,n);
	// return solveSpaceOptm(price,n);
	return solve1DArraySpaceOptm(price,n);
}

int main() {
	init_code();
	int n = 5;
	vector<int> price = {2,5,7,8,10};
	cout << cutRod(price,n);
	return 0;
}
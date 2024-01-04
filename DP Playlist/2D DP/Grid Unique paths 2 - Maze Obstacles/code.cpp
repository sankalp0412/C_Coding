#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int spaceOptimized(vector<vector<int>>& vec){
	int m = vec.size();
	int n = vec[0].size();
	vector<int> dp(n,0);
	for(int i = 0; i < m; i++){
        vector<int> curr(n);
		for(int j = 0; j < n; j++) {
			if(vec[i][j] == 1) curr[j] = 0;
			else if(i == 0 && j == 0) curr[j] = 1;
			else{
				int up = 0, left = 0;
				if(i > 0) up = dp[j];
				if(j > 0) left = curr[j-1];
				curr[j] = (up + left);
			}
		}
        dp = curr;
	}
	return dp[n-1];
}
int uniquePathsWithObstacles(vector<vector<int>>& vec) {
	// return spaceOptimized(vec);
	int mod = 1e9 + 7;
	int m = vec.size();
	int n = vec[0].size();
	int dp[m][n];
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++) {
			if(vec[i][j] == 1) dp[i][j] = 0;
			else if(i == 0 && j == 0) dp[i][j] = 1;
			else{
				int up = 0, left = 0;
				if(i > 0) up = dp[i-1][j];
				if(j > 0) left = dp[i][j-1];
				dp[i][j] = (up + left) % mod;
			}
		}
	}
	return dp[m-1][n-1];
}
int main() {
	init_code();
	vector<vector<int>> vec = {{0,0,0},{0,1,0},{0,0,0}};
	cout << uniquePathsWithObstacles(vec);
	return 0;
}
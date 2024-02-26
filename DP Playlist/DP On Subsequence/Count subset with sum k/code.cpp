// You are given an array 'arr' of size 'n' containing positive integers and a target sum 'k'.
// Find the number of ways of selecting the elements from the array such that the sum of chosen elements is equal to the target 'k'.
// Since the number of ways can be very large, print it modulo 10 ^ 9 + 7
//Coding ninjas 

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int mod = 1e9 + 7;
int dp[1001][1001];
int solve(int idx, int k, vector<int> &arr) {
		if(idx == 0){
		if(k == 0 && arr[0] == 0) return 2;
		if(k == 0 || k == arr[0]) return 1;
		return 0;
}
	if(dp[idx][k] != -1) //means the number of sustet till index idx(from 0 - idx) that will give the sum k
		return dp[idx][k];
	int notTake = solve(idx - 1, k, arr) % mod;
	int take = 0;
	if(k - arr[idx] >= 0)
		take = solve(idx - 1, k - arr[idx], arr) % mod; 

	return (take + notTake) % mod;
	
}
int solTabulation( vector<int> &arr, int k){
	int n = arr.size();
	vector<vector<int>> dp(n,vector<int> (k + 1,0));
	dp[0][0] = 1;
	if(arr[0] <= k) dp[0][arr[0]] = 1;
	

	for(int i = 1; i < n; i++){
		for(int j = 0; j <= k; j++) {
			int notTake = dp[i-1][j];
			int take = 0;
			if(j - arr[i] >= 0)
				take = dp[i- 1][j - arr[i]];

			dp[i][j] = (take + notTake) % mod;
		}
	}
	return dp[n-1][k];
}
int solSpaceOptimization(vector<int> &arr, int k ) {
	int n = arr.size();
	vector<int> prev(k + 1,0), curr(k + 1,0);
	prev[0] = 1;
	curr[0] = 1;
	if(arr[0] <= k) prev[arr[0]] = 1;
	if(arr[0] == 0) curr[0] = prev[0] = 2; //this is why it was failing earlier for coding ninjas question

	for(int i = 1; i < n; i++){
		for(int j = 0; j <= k; j++) {
			int notTake = prev[j];
			int take = 0;
			if(j >= arr[i])
				take = prev[j - arr[i]];

			curr[j] = (take + notTake) % mod;
		}
		prev = curr;
	}
	return prev[k];
}
int findWays(vector<int>& arr, int k){
	memset(dp,-1,sizeof(dp));
	int n = arr.size();
	return solSpaceOptimization(arr,k);
}

int main() {
	init_code();
	vector<int> arr = {1, 1, 4, 5,0};
	int k = 5;
	cout << findWays(arr,k);
	return 0;
}
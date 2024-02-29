// QUESTION IS MINIMUM ELEMENTS/ COIN CHANGE ON LEETCODE
//INFINITE SUPPLIES PATTERN

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

int dp[15][10001];
int solve(int idx, int target, vector<int> &num) {
    if(target == 0)
        return 0;
    if(idx == 0)
        return (target % num[0] == 0) ? target / num[0] : 1e8;
    
    if(dp[idx][target] != -1)
        return dp[idx][target];
    
    int take = INT_MAX;
    int notTake = solve(idx - 1, target, num);
    if(num[idx] <= target) 
        take = 1 + solve(idx, target - num[idx], num);
//here we can't use division as not necessarily everytime we have to use all the denomination of idx type
    // mostly in case of infinite supplies / multiple use take will stand at the same index
    return dp[idx][target] =  min(take, notTake);
}
int solveTabulation(vector<int> num, int target) {
	int n = num.size();
	vector<vector<int>> dp(n, vector<int> (target + 1, 0));
	sort(num.begin(),num.end());
	
	for(int t = 1; t <= target; t++) {
		if(t % num[0] == 0)
			dp[0][t] = t / num[0]; 
		else 
			dp[0][t] = 1e9;
	}

	for(int i = 1; i < n; i++) {
		for(int t = 1; t <= target; t++) {
			int take = INT_MAX;
			int notTake = dp[i-1][t];
			if(num[i] <= t) 
				take = 1 + dp[i][t - num[i]];
		dp[i][t] = min(take, notTake);
		}
	}

	int ans = dp[n-1][target];
	return ans >= 1e9 ? -1: ans;

}
int solveSpaceOptimization(vector<int> &num, int target) {
	int n = num.size();
	vector<int> prev(target + 1, 0) ,curr(target + 1, 0);
	sort(num.begin(),num.end());
	
	for(int t = 1; t <= target; t++) {
		if(t % num[0] == 0)
			prev[t] = t / num[0]; 
		else 
			prev[t] = 1e9;
	}

	for(int i = 1; i < n; i++) {
		for(int t = 1; t <= target; t++) {
			int take = INT_MAX;
			int notTake = prev[t];
			if(num[i] <= t) 
				take = 1 + curr[t - num[i]];
			curr[t] = min(take, notTake);
		}
		prev = curr;
	}

	int ans = prev[target]; //IMP return prev Exampt arr = {20} target = 2
	return ans >= 1e9 ? -1: ans;

}
int minimumElements(vector<int> &num, int x){
    int n = num.size();
    memset(dp,-1,sizeof(dp));
    sort(num.begin(),num.end());
    // int ans = solve(n - 1, x, num);
    // return ans == 1e8 ? -1 : ans;
    // return solveTabulation(num,x);
    return solveSpaceOptimization(num,x);
}
int main() {
	init_code();
	vector<int> num = {9,5,6,1};
	int x = 11;
	cout << minimumElements(num,x);
	return 0;
}
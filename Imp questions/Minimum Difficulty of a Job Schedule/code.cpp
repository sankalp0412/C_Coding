#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
 int solveDP(vector<int>& jobDiff, int d) {
 	  int n = jobDiff.size();
        if(d > n) return -1;
        vector<vector<int>> dp(n+1,vector<int> (d + 1,-1));
        //dp[i][j] = minimum diff of doing job from index i to n - 1 in j days
        for(int i = 0; i < n; i++)
            dp[i][1] = *max_element(jobDiff.begin() + i, jobDiff.end());

        for(int day = 2; day <= d; day++) {
            for(int i = 0; i <= n - day ; i++) {
                int maxDiff = INT_MIN;
                int res = INT_MAX;
                for(int j = i; j <= n - day; j++) {
                    maxDiff = max(maxDiff, jobDiff[j]);
                    res = min(res, maxDiff + dp[j+1][day - 1]);
                }
                dp[i][day] = res;
            }
        }
    return dp[0][d]; //Return min difficulty from 0 to n n - 1 within d days
 }
 int dp[301][11];
    int solveMemo(vector<int> &jobDiff, int idx, int d, int &n) {
        if(d == 1)
            return *max_element(jobDiff.begin() + idx, jobDiff.end());
        if(dp[idx][d] != -1)
            return dp[idx][d];
        int ans = INT_MAX, diffForCurrDay = INT_MIN;
        for(int i = idx; i < jobDiff.size(); i++) {
            if(n - i >= d){
                diffForCurrDay = max(diffForCurrDay,jobDiff[i]);
                ans = min(ans,diffForCurrDay + solveMemo(jobDiff,i + 1,d - 1,n));
            }
            else break;
        }
        return dp[idx][d] = ans;
    }
int minDifficulty(vector<int>& jobDiff, int d){
	int n = jobDiff.size();
        memset(dp,-1,sizeof(dp));
        if(d > n)
            return -1;
        return solveMemo(jobDiff, 0, d, n);
        return solveDP(jobDiff ,d);
}
int main() {
	init_code();
	vector<int> jobDiff = {6,5,4,3,2,1};
	cout << minDifficulty(jobDiff,2);
	return 0;
}
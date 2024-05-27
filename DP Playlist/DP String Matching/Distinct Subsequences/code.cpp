//fn(n-1,m-1) means the number of distinct subsequences, 
//of string t[0-j] in string s[0-i]
#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

//recusion TC: 2^n * 2^m, SC: O(N+M)
int solveMemo(string &s, string &t, int i, int j,vector<vector<int>> &dp) {
        if(j == t.size())
            return 1;
        if(i == s.size())
            return 0;

        if(dp[i][j] != -1) 
            return dp[i][j];

        int take = 0, notTake;

        notTake = solveMemo(s,t,i+1,j,dp);
        
        if(s[i] == t[j])
            take = solveMemo(s,t,i+1,j+1,dp);

        return dp[i][j] = take + notTake;
            
}
int MOD = 1e9 + 7;
int solveTabulation(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<long long>> dp(n+1, vector<long long> (m+1,0));
        

        for(int i = 0; i <= n; i++) {
                dp[i][0] = 1;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int take = 0, notTake;
                notTake = dp[i-1][j];
                if(s[i-1] == t[j-1])
                    take = dp[i-1][j-1];

                dp[i][j] = (take + notTake)%MOD;
            }
        }
        return (int)dp[n][m];
}
int solveSpaceOptimization(string s, string t) {
        int n = s.size(), m = t.size();
        vector<long long>  curr(m+1,0), prev(m+1,0);
        
        prev[0] = 1;
        curr = prev;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int take = 0, notTake;
                notTake = prev[j];
                if(s[i-1] == t[j-1])
                    take = prev[j-1];

                curr[j] = (take + notTake)%MOD;
            }
            prev = curr;
        }
        return (int)curr[m];
}

 int solve1ArraySO(string s, string t) {
        int n = s.size(), m = t.size();
        vector<long long>  dp(m+1,0);
        
        for(int i = 0; i <= n; i++) {
                dp[0] = 1;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = m; j >=1 ; j--) { //this is the maine change that we will make now we will go from m to 1 as we will need th previous calculation of j
                int take = 0, notTake;
                notTake = dp[j];
                if(s[i-1] == t[j-1])
                    take = dp[j-1];

                dp[j] = (take + notTake)%MOD;
            }
        }
        return (int)dp[m];
    }

int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n, vector<int> (m,-1));
    // return solveMemo(s,t,0,0,dp);
    // return solveTabulation(s,t);
    // return solveSpaceOptimization(s,t);
    return solve1ArraySO(s,t);
}
int main() {
	init_code();
	string s = "rabbbit", t = "rabbit";
	cout << numDistinct(s,t);
	return 0;
}
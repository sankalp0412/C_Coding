//is string s = abacdaba
//then we can just reverse
//and then this question turns into 
//LC subsequence


#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) {
                if(s[i-1]==t[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][n]; 
}
int main() {
	init_code();
	string s = "bbbab";
	cout << longestPalindromeSubseq(s);
	return 0;
}
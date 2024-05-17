//if i wnat minimum insertionsm, i will try to
// keep the longest palindromic portion intact

//and then i will need to addthe remaining characters both sides
//eg abcaa
//longest already present palindrome sequ
//is aca
//so iwill just add the remainig and reverse 'ab' other sides
//a  ba c ab  a

//so basically answer will be n - length of longest palindromic subsequ

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif

}int longestPalindromeSubseq(string s) {
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
int minInsertions(string s) {
	int len = longestPalindromeSubseq(s);       
	return s.length() - len;
}
int main() {
	init_code();
	string s = "leetcode";
	cout << minInsertions(s);
	return 0;
}
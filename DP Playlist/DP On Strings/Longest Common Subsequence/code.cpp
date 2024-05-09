//Brute force will be exponential in nature, as we will search and check for all subsequences
// We will try to write some recurrenec that will give me answer through the way
// F[i] Means string till lenght 2
// A single index cannot represent both strings, hence we will need two indexes
// so F[2][2] will mean lcs of string 1 (0-2) string 2(0-2)
// Recursion : O(n) = 2^n * 2^m

//Memo : TC = N*M;
//		: SC = N*M + N+M  (As the max length of the stack tree will be sum of length of both strings)
#include "bits/stdc++.h"
using namespace std;


void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
string printLCS(vector<vector<int>> dp, string s, string t) {
	int i = dp.size()-1, j = dp[0].size() - 1;
	string ans = "";
	while(i > 0 && j > 0) {
		if(s[i-1] == t[j-1]){
			ans += s[i-1];
			i--;j--;
		}
		else if(dp[i-1][j] > dp[i][j-1])
				i--;
			else 
				j--;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
int solveMemo(string text1, string text2, int i, int j,vector<vector<int>> &memo) {
	if(i < 0 || j < 0) return 0;

    if(memo[i][j] != -1)return memo[i][j];
    if(text1[i] == text2[j])
        return  memo[i][j]= 1 + solveMemo(text1,text2, i- 1, j - 1,memo);
    return  memo[i][j] =  max(solveMemo(text1,text2,i-1,j,memo),solveMemo(text1,text2,i,j-1,memo));
}

int solveTabulation(string text1, string text2) {
	int n1 = text1.size(),n2 = text2.size();
	vector<vector<int>> dp(n1+1,vector<int> (n2 + 1,0));
	for(int j = 0; j <= n2; j++) 
		dp[0][j] = 0;
	for(int i = 0; i <= n1; i++) 
		dp[i][0] = 0;

	for(int i = 1; i <= n1; i++) {
		for(int j = 1; j <= n2; j++) {
			if(text1[i-1] == text2[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else 
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	cout << printLCS(dp,text1,text2) << endl;
	return dp[n1][n2];

}int solveSpaceOptm(string text1, string text2) {
	int n1 = text1.size(),n2 = text2.size();
	vector<int> curr(n2+1,0), prev(n2+1,0);
	for(int j = 0; j <= n2; j++) 
		curr[j] = 0;
	
	prev = curr;
	for(int i = 1; i <= n1; i++) {
		for(int j = 1; j <= n2; j++) {
			if(text1[i-1] == text2[j-1])
				curr[j] = 1 + prev[j-1];
			else 
				curr[j] = max(prev[j], curr[j-1]);
		}
		prev = curr;
	}
	return curr[n2];

}
int longestCommonSubsequence(string text1, string text2) {
	int n1 = text1.size(),n2 = text2.size();
	vector<vector<int>> memo(n1, vector<int> (n2,-1));
	// return solveMemo(text1,text2,n1-1,n2-1,memo);
	return solveTabulation(text1,text2);
	// return solveSpaceOptm(text1,text2);
}

int main() {
	init_code();
	string text1 = "abcde", text2 = "ace";
	cout << longestCommonSubsequence(text1,text2);
	return 0;
}
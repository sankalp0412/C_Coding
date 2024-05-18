//What can i not touch, as if i touch minimum
//number of chars i will use minimum number of operations
//i can delete anywhere and anyone and insert anywhere and anyone


//deletions = n - len(lcs)
//insertions = m - len(lcs);

//ans = n+m - 2(len(lcs))
#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int LCS(string text1, string text2) {
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
	return dp[n1][n2];

}
int minDistance(string word1, string word2) {
    int len = LCS(word1,word2);
    return word1.length() + word2.length() - (2 * len);
}
int main() {
	init_code();
	string word1 = "abcd", word2 = "anc";
	cout << minDistance(word1,word2);
	return 0;
}
/*Given two strings str1 and text2, return the shortest string that has both str1 and text2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.
*/

//Common characters should be taken once
//Common charcters are nothing but LCSubsequ

//Length of super seq is nothing but n + m - len(LCS)

//to find the actual string the approachd will be similar to print lcs
//we will start from end and unlike print lcs this time we will
//include the character if theres a non match.
//at the end we will reverse the string and return
//at the end we will also have to if some characters of a string are remaining

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
class Solution {
public:
string shortestCommonSupersequence(string text1, string text2) {
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

	string ans = "";
	int i = n1 , j = n2;
	while(i > 0 && j > 0) {
		if(text1[i-1] == text2[j-1]) {
			ans += text1[i-1];
			i--;j--;
		}
		else if(dp[i-1][j] > dp[i][j-1]){
			ans += text1[i-1];
			i--;
		}
		else {
			ans += text2[j-1];
			j--;
		}
	}
	while(i > 0){
		ans += text1[i-1];
		i--;
	}

	while(j > 0){
		ans += text2[j-1];
		j--;
	}

	reverse(ans.begin(),ans.end());
	return ans;
  }
};
int main() {
	init_code();
	string text1 = "abac", text2 = "cab";
	Solution sol;
	cout << sol.shortestCommonSupersequence(text1,text2);
	return 0;
}
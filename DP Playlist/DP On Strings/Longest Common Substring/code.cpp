//This is partially same as lc subsequence
//but we here the continuity matters.
//hence the condition [i-1][j] , [i][j-1] wont work
//so for i == j if they match then we will check directly
//for i-1,j-1 if they match or not and add 1 if they do
//else we initialize the current one to 0 resetting the value.

//the answer will be max value in the matrix

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int longesCommonSubstring(string &s, string &t) {
	int m = s.length(), n = t.length();
	vector<vector<int>> dp(m + 1,vector<int> (n+1,0));
	for(int j = 0; j <= n; j++) 
		dp[0][j] = 0;
	for(int i = 0; i <= m; i++) 
		dp[i][0] = 0;

	int ans = INT_MIN;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++) {
			if(s[i-1] == t[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
				ans = max(ans,dp[i][j]);
			}
			else
				dp[i][j] = 0; //this is the part which will be different as if there is a non match we will kinf of reset the counter
		}
	}
return ans;		

}
int main() {
	init_code();
	string s = "abcjklp", t = "acjkp";
	cout <<  longesCommonSubstring(s,t);
	return 0;
}
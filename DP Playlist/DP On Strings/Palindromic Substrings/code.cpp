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
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n,0)) ;
        int ans = 0;
        for(int i = 0; i < n; i++){
            dp[i][i] = 1; //one length string will be palindrom
            ans++;
        }

        for(int L = 2; L <= n; L++) {
            for(int i = 0; i <= n - L; i++) {
                //what will be j
                int j = i + L - 1;
                if(L == 2 && s[i] == s[j]){
                    dp[i][j] =1;
                    ans++;
                }
                //cehck if this is palidrome
                 else if(s[i] == s[j] && dp[i+1][j-1]) {
                    ans++;
                    dp[i][j] = 1;
                }
                else dp[i][j] =0;

            }
        }
        return ans;
    }
};

int main() {
	init_code();
	string s = "babad";
    Solution sol;
    cout << sol.countSubstrings(s);
	return 0;
}

// Time Complexity: \(O(n^2)\)
// Space Complexity: \(O(n^2)\)
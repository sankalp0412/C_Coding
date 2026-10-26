#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

//memoization O(n^3)
// class Solution {
// public:
//     vector<vector<int>> cache;
//     bool solve(int i, int  j, string &s) {
//         if(i >= j) return true;
//         if(cache[i][j] != -1) return cache[i][j];
//         if(s[i] == s[j])
//             return solve(i+1,j-1,s);

//         return false;
//     }
//     string longestPalindrome(string s) {
//         int m = s.size();
//         int ansLen = INT_MIN;
//         int ansIndex = -1;
//         cache.resize(m,vector<int>(m,-1));
//         for(int i = 0; i < m; i++) {
//             for(int j = i; j < m; j++) {
//                 if(solve(i,j,s)){
//                     if(j - i + 1 > ansLen){
//                         ansLen = j - i + 1;
//                         ansIndex = i;
//                     }
//                 }
//             }
//         }
//         return s.substr(ansIndex, ansLen);
//     }
// };


//Bottom up
//We iterate over substring lengths in increasing order, ensuring dp[i+1][j-1] is computed before we
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool> (n,false));

        int maxL = 1;
        int idx = 0;

        for(int i = 0 ; i< n; i++)
            dp[i][i] = 1;

        for(int L = 2; L <= n; L++) {
            for(int i = 0; i < n-L+1; i++) {
                int j = i + L -1;
                if(s[i] == s[j] && L ==2) {
                    dp[i][j] = true;
                    maxL = 2;
                    idx = i;
                }
                else if(s[i] == s[j] && dp[i+1][j-1] == 1){
                    dp[i][j] = true;
                    idx = i;
                    if(j - i +1 > maxL) {
                        maxL = j - i + 1;
                        idx = i;
                    }
                }
                    else dp[i][j] = false;
            }
        }
        return s.substr(idx,maxL);
    }
};

int main() {
	init_code();
	string s = "babad";
	return 0;
}
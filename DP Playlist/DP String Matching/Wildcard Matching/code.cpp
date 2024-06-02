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
    bool solveMemo(int i, int j, string &s, string &p,vector<vector<int>>& dp) {
       //base
       if(i < 0 && j < 0) return true;
       if(j < 0 && i >= 0) return false; //if pattern is finished
       if(i < 0 && j >= 0) { //if string is finished but pattern can be ****)
           while(j >= 0){
               if(p[j] != '*')
                   return false;
                   j--;
           }
           return true;
       }

       if(dp[i][j] != -1) return dp[i][j];

       if(s[i] == p[j] || p[j] == '?')
           return dp[i][j] = solveMemo(i-1,j-1,s,p,dp);
       if(p[j] == '*') {
           //here we can also use a for loop, line 55
           //or once we can consider * to be equal to nothing
           //or consider it matching with the ith character
           if(solveMemo(i,j-1,s,p,dp) || solveMemo(i-1,j,s,p,dp))
               return dp[i][j] = true;
       }
       
       //in case of a direct non-match
       return dp[i][j] = false;
    }
    bool solveTabulation(string &s, string &p) {
    	int m = s.length(),n = p.length();
        vector<vector<bool>> dp(m + 1,vector<bool>(n + 1,false)); 
        //base
        dp[0][0] = true;
        for(int j = 1; j <= n; j++){
        	if(p[j-1] == '*')
        		dp[0][j] = true;
        	else 
        		break; 
        		//because it will be false for the rest once we have encountered a non '*' in the case when we have string s as empty
        }

        for(int i = 1; i <= m; i++){
        	for(int j = 1; j <= n; j++) {
        		if(s[i-1] == p[j-1] || p[j-1] == '?')
        			dp[i][j] = dp[i-1][j-1];
        		else if(p[j-1] == '*')
        			dp[i][j] = dp[i][j-1] || dp[i-1][j];
        		else 
        			dp[i][j] = false;
        	}
        }

        return dp[m][n];
    }

    bool solveSpaceOpt(string &s, string &p) {
    	int m = s.length(),n = p.length();
        vector<bool> prev(n + 1, false), curr(n + 1,false); 
        //base
        prev[0] = true;
        for(int j = 1; j <= n; j++){
        	if(p[j-1] == '*')
        		prev[j] = true;
        	else 
        		break; 
        		//because it will be false for the rest once we have encountered a non '*' in the case when we have string s as empty
        }


        for(int i = 1; i <= m; i++){
        	for(int j = 1; j <= n; j++) {
        		if(s[i-1] == p[j-1] || p[j-1] == '?')
        			curr[j] = prev[j-1];
        		else if(p[j-1] == '*')
        			curr[j] = curr[j-1] || prev[j];
        		else 
        			curr[j] = false;
        	}
        	prev = curr;
        }

        return prev[n]; // we will return prev[n] instead of curr[n]
        //because of the case when s = "" and p = "****"
        //the curr will never get updated as s.size() is 0 so the loop wont run even once
    }
    bool isMatch(string s, string p) {
        int m = s.length(),n = p.length();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        //dp[i][j] ? is wildcard matching possible for s[0-i], p[0-j] 
        // return solveMemo(m-1,n-1,s,p,dp);
        // return solveTabulation(s,p);
        return solveSpaceOpt(s,p);
    }
};
int main() {
	init_code();
	string s = "cdefaxyz", p = "?*a*";
	//string s = "aa" , p = "a";
	//string s = "", p = "*****";
	//string s = "aa", p = "*";
	Solution sol;
	cout << sol.isMatch(s,p);
	return 0;
}



// if(p[j] == '*') {
//             for(int idx = i; idx < s.length(); idx++) { // i am cincluding till index idx for *
//                 if(solve(idx - 1, j-1,s,p))
//                     return true;
//             }
//         }
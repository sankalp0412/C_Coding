// Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

// Return the maximum product you can get.


#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}


int solve(int n , vector<int> &memo) {
	if(n <= 3) 
		return n;
	if(memo[n] != -1)
		return memo[n];

	int maxProd = INT_MIN;
	for(int i = 1; i < n; i++) {
		maxProd = max(maxProd, i * solve(n-i,memo));
	}
	return memo[n] = maxProd;
	
} 
int solveMemo(int n) {
	if(n <= 3)
		return n - 1;
	    					 //because if n <= 3 and we require at least two intergers
	vector<int> memo(n+1,-1);	// then we have to break to it further as we can't use the number
	return solve(n,memo);      // itself as then it would be only one intger
}
							//but VVVIMP in the case of recursion we will return the number 
							//itself if it is <= 3 as then it won't be the sole integer
							// so we will maximize it	(doing the same thing at line 41)

int solveDP(int n) {
	vector<int> dp(n+1,0);
        dp[1] = 1;
        for(int i = 2; i <=n; i++) {
            dp[i] = (i == n ? 0: i);  // 3 can be taken as max prod of 3 only if its not the sole integer
            for(int j = 1; j < i; j++) {
                dp[i] = max(dp[i], dp[j] * dp[i-j]);
            }
        }
        return dp[n];
}

int integerBreak(int n) {
	// return solveMemo(n);
	return solveDP(n);
}
int main() {
	init_code();
	int n  = 10;
	cout << integerBreak(n) << endl;
	return 0;
}
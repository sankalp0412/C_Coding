//f(i,j)
//minimum ops to convert s1[0--i] to s2[0---j]


//base cases

//if s1 is exhausted
//i.e. f(-1,j) i.e minimum operations to convert empty string
//to s2[0-j] i.e j + 1 operations

//similarly if s2 gets exhausted
//we will delete all the remaining in s1

//f(2,-1) -> minimum operation to convert "hor" to empty string
//recursion TC: exponential SC : O(n+M);

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
 int solveMemo(string &word1, string &word2, int &n, int &m, int i, int j,vector<vector<int> > &dp) {
	//base
	if(i < 0) return j + 1;
	if(j < 0) return i + 1;

	if(dp[i][j] != -1) return dp[i][j];

	int ins,rep,del;

	if(word1[i] == word2[j])
		return dp[i][j] = solveMemo(word1,word2,n,m,i-1,j-1,dp);
	ins = 1 + solveMemo(word1,word2,n,m,i,j-1,dp);  //means hypothetically i am inserting at (i+1) position so the i+1 will match to j(hypothetically), hence the i will remain same.
	del = 1 + solveMemo(word1,word2,n,m,i-1,j,dp);
	rep = 1 + solveMemo(word1,word2,n,m,i-1,j-1,dp);

	return dp[i][j] = min(ins,min(del,rep));
}
int solveTabulation(string word1, string word2) {
	int m = word1.size(),n = word2.size();
	vector<vector<int> > dp(m + 1,vector<int> (n + 1,0));

	for(int i = 0; i <= m; i++) 
		dp[i][0] = i ;

	for(int j = 0; j <= n; j++) 
		dp[0][j] = j ;
	

	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++) {
			if(word1[i-1] == word2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else {
			     int ins,rep,del;

			     ins = 1 + dp[i][j-1];
			     del = 1 + dp[i-1][j];
			     rep = 1 + dp[i-1][j-1];

			     dp[i][j] = min(ins,min(del,rep));

			}
		}
	}

	return dp[m-1][n-1];

}

int solveSpaceOpt(string word1, string word2) {
	int m = word1.size(),n = word2.size();
	vector<int> prev(n + 1,0),curr(n+1,0);


	for(int j = 0; j <= n; j++) 
		prev[j] = j ;
	for(int i = 1; i <= m; i++){
        curr[0] = i; //imp second base case the 0 should have i 
		for(int j = 1; j <= n; j++) {
			if(word1[i-1] == word2[j-1])
				curr[j] = prev[j-1];
			else {
			     int ins,rep,del;

			     ins = 1 + curr[j-1];
			     del = 1 + prev[j];
			     rep = 1 + prev[j-1];

			     curr[j] = min(ins,min(del,rep));

			}
		}
		prev = curr;
	}

	return prev[n];
}
//here we can't optimize it further to one array as we are dependent on both curr and prev j -1;

int minDistance(string word1, string word2) {
	int m = word1.size(),n = word2.size();
	vector<vector<int> > dp(m,vector<int> (n,-1));
	// return solveMemo(word1,word2,n,m,m-1,n-1,dp);
	// return solveTabulation(word1,word2);
	return solveSpaceOpt(word1, word2);
}
int main() {
    init_code();
    string word1 = "horse", word2 = "ros";
    cout << minDistance(word1,word2);
    return 0;
}


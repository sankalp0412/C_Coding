// Given a string s, return the number of homogenous substrings of s. Since the answer may be too large, return it modulo 109 + 7.

// A string is homogenous if all the characters of the string are the same.

// A substring is a contiguous sequence of characters within a string.
// --------------------------------------------------------------------

//APPROACH: 

//All substring of a homogenous substring will be also homogenous substrings:

//If i have a string "aa" number of homogenous substring: 3
//string "aaa" number of homo substring : 6
// String "aaaa" number of : 10
//i.e sum of n natural number where n is lenght
 

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int countHomogenous(string &s) {
	int mod = 1e9 + 7;
    int ans = 0;
	int cnt = 0;
	for(int i = 0; i < s.length(); i++) {
		if(i > 0 && s[i-1] == s[i]){
			cnt += 1;
		}
		else cnt = 1;
		ans= (ans + cnt) % mod;
	}
	return ans;
}
int main() {
	init_code();
	string s = "abbcccaa";
	cout << countHomogenous(s);
	return 0;
}
//TC : N^2  * L (max length of the string) + nlogn(sorting)
#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
//we use the lis code only only check for wheather we 
//can take the current string or not
bool checkPossible(string &a, string &b) {
	if(a.size() != b.size() + 1) return false;
	int first = 0;
	int second = 0;
	while(first < a.size()) {
		if(a[first] == b[second]){
			first++;
			second++;
		}
		else 
			first++;
	}
	if(first == a.size() && second == b.size()) 
		return true;
	return false;
}
int longestStrChain(vector<string>& words) {
	sort(words.begin(), words.end(),[&](string &a, string &b) {
            return a.size() <= b.size();
        });
    int n = words.size();
	int maxi = 1;
	vector<int> dp(n,1);
	for(int i = 1; i < n; i++) {
		for(int j = i-1; j >= 0; j--) {
			if(checkPossible(words[i],words[j]) && 1 + dp[j] > dp[i]){
				dp[i] = 1 + dp[j];
			}
		}
		if(dp[i] > maxi) {
			maxi = dp[i];
		}
	}
	return maxi;
}
int anotherWay(vector<string>& words) {
         sort(words.begin(),words.end(),[&](string s1, string s2){
            return s1.length() < s2.length();
        });
        unordered_map<string,int> dp;
        int max_chain = 0;
        for(auto &word: words) {
            dp[word] = 1;
            for(int i = 0; i < word.size(); i++) {
                string prev_word = word.substr(0,i) + word.substr(i+1); //we check by omitting each character in the current string one by one, if the new formed string after omitting existed previously or not
                if(dp.count(prev_word)){
                    dp[word] = max(dp[word],dp[prev_word]+1);
                }
            }
            max_chain = max(max_chain, dp[word]);
        }
        return max_chain;
    }
int main() {
	init_code();
	vector<string> words = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
	cout << anotherWay(words);
	return 0;
}
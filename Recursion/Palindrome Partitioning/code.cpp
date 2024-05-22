/*Given a string s, partition s such that every 
substring
 of the partition is a 
palindrome
. Return all possible palindrome partitioning of s.
*/


#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
bool isPal(string str) { 
    string t = str; 
    reverse(str.begin(),str.end()); 
    return t == str;
}
void solve(vector<vector<string>> &ans, string &s, vector<string> temp, int idx) {
     //base
    if(idx >= s.size()){
        ans.push_back(temp);
        return;
    }
    for(int i = idx ; i < s.size(); i++) {
        string curr = s.substr(idx, i - idx + 1);
      
        if(isPal(curr)){
            temp.push_back(curr);
            solve(ans,s,temp,i + 1);
            temp.pop_back();
        }
    }
    return;
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    solve(ans,s,{},0);
    return ans;
}
int main() {
	init_code();
	string s = "aab";
	auto vec = partition(s);
	for(auto v: vec) {
		for(auto str: v)
			cout << str << ",";
		cout << endl;
	}
	return 0;
}
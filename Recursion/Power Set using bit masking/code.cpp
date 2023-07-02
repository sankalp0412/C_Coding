// https://www.youtube.com/watch?v=b7AYbpM5YrE
//for a string of size 9 we 2^n sets
//2^n is same as 1 << n
// 1 left shif 3 will be 8
// 1000 
// 1 << n - 1 = 1000 (8) - 1 = 7
//we can explain this in terms of bits from 0-2^n-1
//where 0 means take that char and 1 means dont take that cchar
//0-000  ""
//1-001  a
//2-010  b
//3-011  ab
//4-100  c
//5-101  ac
//6-110  ab
//7-111  abc
//
// for bits the index starts from left 
// so if the 0 th bit is set that means the 0th index in the string abc
#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
void solve(string &s, int &n, vector<string> &ans ) {
	for(int num = 0; num <= (1 << n) -1; num++) {  //or i < pow(2,n) - 1
		string temp = "";
		for(int i = 0; i < n; i++) {
			if(num &(1 << i))
				temp += s[i];
		}
	ans.push_back(temp);
	}
}

int main() {
	init_code();
	string s= "abc";
	int n = s.size();
	vector<string> ans;
	solve(s,n,ans);
	
	for(auto str: ans) {
		cout << str << endl;
	}
	return 0;
}
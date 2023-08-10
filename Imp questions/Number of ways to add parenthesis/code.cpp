#include "bits/stdc++.h"
using namespace std;

// #define for(i,n) for(int i = 0; i < n; i++)

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
unordered_map<string,vector<int>> mp;
      int perform(int x, int y, char op) {
        if(op == '+') return x + y;
        if(op == '-') return x - y;
        if(op == '*') return x * y;
        return 0;
    }
    vector<int> diffWaysToCompute(string exp) {
        vector<int> res;
        for(int i = 0; i < exp.length(); i++) {
            if(!isdigit(exp[i])) {
                vector<int> left,right;
                string l = exp.substr(0,i);
                string r = exp.substr(i+1);
                if(mp.count(l)) left = mp[l];
                else left =diffWaysToCompute(l);
                if(mp.count(r)) right = mp[r];
                else right = diffWaysToCompute(r);

                for(int x: left){
                    for(int y: right) {
                        int val = perform(x,y,exp[i]);
                        res.push_back(val);
                    }
                }
            }
        }
        if(!res.size()) res.push_back(stoi(exp));
        return mp[exp] =  res;
    }
int main() {
	init_code();
	string exp;
	cin >> exp;
	vector<int> ans = diffWaysToCompute(exp);
	for(auto x: ans) cout << x << "," ;
	return 0;
}
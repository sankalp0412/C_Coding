#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
    bool isValid(string subnet) {
       return (stoi(subnet) <= 255 &&  (subnet.size() == 1 || subnet[0] != '0'));
    }
    void solve(int index, int subnetCount, string &s, string temp, vector<string> & ans) {
        if(index == s.size() && subnetCount == 4) {
            temp.pop_back(); //remove the last dot
            ans.push_back(temp);
            return;
        }
        if(subnetCount > 4) return;
        for(int i = index; i < min(index + 3, (int)s.size()); i++) {
            if(isValid(s.substr(index, i - index + 1))){
                solve(i+1,subnetCount+1, s, temp + s.substr(index,i-index+1) + '.', ans);
            }
        }
    }
int main() {
	init_code();
	string s = "101023";
	vector<string> ans;
    if(s.size() > 12) cout << "";
    solve(0,0,s,"",ans);
    for(auto str: ans) cout << str << endl;
	return 0;
}
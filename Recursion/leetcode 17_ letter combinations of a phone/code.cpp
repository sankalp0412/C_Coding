#include<bits/stdc++.h>
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
void solve(string temp,int curr,string digits, unordered_map<char,string> mp) {
        if(curr >= digits.size()){
            if(temp.size() == digits.size()) {
                cout << temp << endl;
            }
            return;
        }
        for(auto letter: mp[digits[curr]]) {
            temp += letter;
            solve(temp,curr+1,digits,mp);
            temp.pop_back();
        }
}
int main () {
    init_code();
    string digits = "23";
    int n = digits.size();
    unordered_map<char,string> mp;
    mp['2'] = "abc"; mp['3'] = "def"; mp['4'] = "ghi"; mp['5'] = "jkl";
    mp['6']= "mno" ;mp['7'] = "pqrs" ; mp['8'] = "tuv"; mp['9'] = "wxyz";
    
    solve("",0,digits,mp);

    return 0;

}

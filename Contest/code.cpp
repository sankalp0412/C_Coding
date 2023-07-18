#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
    void maximumNumberOfStringPairs(vector<string>& words) {
        int ans = 0;
        unordered_map<string,int> mp;
        for(auto str: words) {
            sort(str.begin(),str.end());
            if(mp.count(str)) ans++;
            else mp[str]++;
        }
        cout << ans << endl;
    }
int main() {
	init_code();
	vector<string> words = {"cd","ac","dc","ca","zz"};
	maximumNumberOfStringPairs(words);
	return 0;
}
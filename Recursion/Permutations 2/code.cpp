// https://www.youtube.com/watch?v=qhBVWf0YafA

//here instead of using a vector as an input we will us a map
// for eg 1,1,2 map will look like 1-2 : 2-1
//now we will keep track of the counts each time we do a recursion



#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
 void solve(int n, vector<int> temp, unordered_map<int,int> mp, vector<vector<int>> &ans) {
        if(temp.size() == n){
            ans.push_back(temp);
        }
        for(auto it: mp) {
            int num = it.first;
            int count = it.second;
            if(!count)
                continue;
            
            temp.push_back(num);
            mp[num]--;
            solve(n,temp,mp,ans);
            //backtrack
            mp[num]++;
            temp.pop_back();
        }
    }
int main() {
	init_code();
	vector<int> nums = {1,1,2};
	unordered_map<int,int>mp;
    for(auto x: nums)   mp[x]++;
    vector<int> temp;
    int n = nums.size();
    vector<vector<int>> ans;
    solve(n,temp,mp,ans);
    for(auto vec: ans){
		for(auto x: vec){
			cout << x << ",";
		}
		cout << endl;
	}
	return 0;
}
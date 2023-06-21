#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
   void solve(vector<vector<int>> &ans, vector<int> marked, vector<int>temp, vector<int> &nums) {
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(!marked[i]) {
                temp.push_back(nums[i]);
                marked[i] = 1;
                solve(ans,marked,temp,nums);
                temp.pop_back();
                marked[i] = 0;
            } 
        }
    }
int main() {
	init_code();
	vector<int> nums = {1,2,3};
	int n = nums.size();
    vector<int> marked(n,0);
    vector<int> temp;
    vector<vector<int> > ans;
    solve(ans,marked,temp,nums);
    for(auto vec: ans) {
    	for(auto x: vec) {
    		cout << x << ",";
    	}
    	cout << endl;
    }
	return 0;

}

// This is approach 1
//I am generating n! permuations and looping from 0 - n each time

//TC: n! * n

// space : O(n) for the temp data strucure and another O(n) for the extra map

//SC = O(n) + O(n)
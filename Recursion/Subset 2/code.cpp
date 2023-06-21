//1,2,2,2,3,3
//here for the first choice we can pic any number to give the subset of size 1
//so we have 1 , 2, 3 as the subsets of size 1, we cant pick the 1,2,3 again as we have aready used them for this size
//in size 2 we can have 1,2 as well as 2,2 but we can't pick the two at the index 3
//as we have already picked tthe two for size 2 subsets



#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
 void solve(int index, vector<int> &temp, vector<vector<int>> &ans, vector<int> nums) {
       
            ans.push_back(temp);
       
        for(int i = index; i < nums.size(); i++) {
            if(i != index && nums[i] == nums[i-1]) continue; // here we are handling the base condition here
            temp.push_back(nums[i]);
            solve(i+1,temp,ans,nums);
            temp.pop_back();
        }
    }
int main() {
	init_code();
	vector<int> nums ={1,2,2};
	vector<vector<int> > ans;
	vector<int> temp;
	solve(0,temp,ans,nums);
	for(auto vec: ans){
		for(auto x: vec){
			cout << x << ",";
		}
		cout << endl;
	}
	return 0;
}
/*
Subsets (Subset 1):
In the first solution, the base condition for recursion is if (index == n),
 where n represents the size of the array nums. This condition is met when the 
 index reaches the end of the array, indicating that all elements have been
  considered. At this point, the current subset is complete, and it is added 
  to the ans vector.

Subsets with Duplicates (Subset 2):
In the second solution, the base condition for recursion is not explicitly
 stated within the solve function. Instead, the base case is implicitly 
 handled in the for-loop condition. The loop iterates from index to nums.size(),
  indicating that when the loop reaches the end of the array, the recursion 
  will stop. This is because the function is called recursively with an increasing
   index, and when it reaches the size of the array, no more elements are left to
    consider.

To summarize, the base condition in the first solution explicitly checks 
if the index is equal to the size of the array, while in the second solution, 
	it is implicitly handled by the loop condition that stops when the index 
reaches the end of the array. */
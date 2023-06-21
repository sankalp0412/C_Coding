//in this question one may think that we can just updat the recursion call to the next index
//insted of the same index as now we are NOT allowed to pick a value more than once
//but that method will not guarantee the removal of duplicates as that is what i did
//one must also try to use a set instead of a vector to avoid duplicates.
//but that will increase the time complexity to 
// (2power n) *k * log of something taht will be set size, we havbe to remove this extra time

// approach:
//arr = [1,1,1,2,2]

//initally we can start with any index as our first element of the combinations
// in this case it wont matter wheather we are choosing the 0 or 1 or the 2 index 
// as the first element of the combination as it will be choosing '1' .
//this is where is the trick to avoid the duplicates
//since we require ll the combinations in sorted order ie 1,1,2 not 2,1,1
//so whatever array is given to us we will sort it first


//if there are consecutive elements which are same like 2,2 , we just decide 
//to pick the first element and ignore the rest on the right .

//after optimization the tc will be (2power n) * k no extra log value
// k is due to the add opeation to the anser in base case
// SC -> k * x  (x -> number of combinations)
// k -> Average length


#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

 void solve(int index,int target,vector<int>& nums,vector<vector<int>> &ans,vector<int> temp) {
      if(target == 0) {
          ans.push_back(temp);
          return;
      }
      for(int i = index ; i < nums.size(); i++) {
        if(i > index && nums[i] == nums[i-1]) continue; // i > index as we will check for rest index on the right of curr index the current will be part of the combination
        if(nums[i] > target) break; //as all other indexis will obviously be more since array is sorted
        temp.push_back(nums[i]);
        solve(i+1,target - nums[i], nums,ans,temp);
        temp.pop_back();
      }
    }

int main() {
    init_code();
    vector<int> nums = {1,1,1,2,2};
    vector<int> temp;
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    int target = 4;
    solve(0,target,nums,ans, temp);

    for(auto vec: ans) {
        for(auto x: vec){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
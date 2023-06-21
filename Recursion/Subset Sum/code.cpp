#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

void solve(int index, int sum, vector<int> &ans, vector<int> arr) {
	if(index == arr.size()) {
		ans.push_back(sum);
		return;
	}
	//pick the index
	solve(index+1,sum + arr[index],ans,arr);
	solve(index+1,sum,ans,arr);
}
int main() {
	init_code();
	vector<int> arr = {2,3};
	vector<int> ans;
	solve(0,0,ans,arr);
	sort(ans.begin(),ans.end());
	for(auto x: ans)
			cout << x << ",";
	return 0;
}


// MISTAKES
// HERE AT LINE 13 MY BASE CONDITION WAS IF(INDE < ARR.SIZE()
//WHICH IS BAHUT JAADA WRONG i was getting wrong ouput 0,0,2
// 0 two times as it will also get satisfied first time with 0 sum

// WHY CURRENT APPROACH IS RIGHT?

// IF WE CONINUE TO NOT PICK THEN IN THE EXTREME RIGHT OF THE RECURSION TREE WE WILL HAVE A CONDITION WHERE
// THE SUM WILL BE ZERO AND WE ALSO HAVENT PICKED ANY INDEX THAT IS THE ZERO
// THE ANSWER SHOULD PICK

//TIME AND SPACE COMPLEXIYT:

// THE TC will be (2powern) + 2powern log 2powern
// the first 2powern is because we have two choices for n elements ie pick and not pick
// extra logarihtmic is becasue we are sorting the array
//SC : 2powern

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

void fn(vector<int> &vec, int n,int curr, int sum, int index,vector<int> &temp) {
	if(index == n) {
		if(curr == sum) {
			for(auto it: temp){
				cout << it << " ";
			}
				cout << endl;
		}
		return;
	}
	temp.push_back(vec[index]);
	curr += vec[index];
	//take
	fn(vec,n,curr,sum,index+1,temp);
	curr -= vec[index];
	temp.pop_back();
	//not take
	fn(vec,n,curr,sum,index+1,temp);
}
int main (){
	init_code();
	vector<int> vec = {1,2,1}, temp;
	int sum = 2, index = 0;
	int n = vec.size();
	fn(vec,n,0,sum,index,temp);
	return 0;

}
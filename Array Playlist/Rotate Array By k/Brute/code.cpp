// /APPROACH
//here if lets say k = n
//k = 7
// then after 7 rotations it will back to its original config
//so lets say if k = 8
// we can say 7 rotations + 1
//ie only one rotations because after 7 rotations it will be back to original
//k = k % n;


//the brute can be done by taking a temp array
//for k = 3
// the temp array can be like[1,2,3]
//now the i index will move back to the i-d index
/// soo loopp for(int i = d; i < n; i++) {
// 	a[i-dd = a[i]
// }
//put back the temp



#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
void solve(vector<int> & vec, int k) {
	int n = vec.size();
	vector<int> temp (k);
	for(int i = 0; i < k; i++)
		temp[i]= vec[i];
	//shifting
	for(int i = k; i<n; i++) {
		vec[i-k] = vec[i];
	}
	//put back temp
	for(int i = n-k; i<n; i++) {
		vec[i] = temp[i - (n-k)];
	}
}
int main() {
	init_code();
	int k;
	cin >> k;
	vector<int> vec = {1,2,3,4,5,6,7};
	int n = vec.size();
	k = k % n;
	solve(vec,k);
	for(auto x: vec)
			cout << x <<",";
	return 0;
}

//TC:
//STEP 1: O(k) to add in temp

//for shifting
// O(n-k)

//for put back

//O(k)

//== O(n+k)

//extra Space: O(k) for the temp array
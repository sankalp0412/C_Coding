#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
vector<int> findMissingAndRepeating(vector<int> a) {
	long long n = a.size();
	int xr = 0;
	for(int i = 0; i < n; i++) {
		xr = xr ^ a[i];
		xr = xr ^ (i+1);
	}
	//find right most bit which is different (set)
	int bitNo = 0;
	while(1) {
		if(xr & (1 << bitNo))
			break;
	bitNo++;
	}
	int zero = 0;
	int one = 0;

	for(int i = 0; i < n; i++) {
		//part of 1
		if(a[i] & (1 << bitNo)) {
			one ^= a[i];
		}
		//part of zeroth club
		else{
			zero ^= a[i];
		}
	}
	for(int i = 1; i <= n; i++) {
		//part of 1
		if(i & (1 << bitNo)) {
			one ^= i;
		}
		//part of zeroth club
		else{
			zero ^= i;
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == zero) cnt++;
	}
	if(cnt == 2)
		return {zero,one};
	else 
		return {one,zero};

}

int main() {
	init_code();
	vector<int> a = {1,2,3,2};
	vector<int> ans = findMissingAndRepeating(a);
	cout << ans[0] << "," << ans[1];
	return 0;
}
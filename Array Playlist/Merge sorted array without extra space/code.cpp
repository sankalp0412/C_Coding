#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
//TC: O(min(m,n));
void optimal1(vector<int> &a, vector<int> &b) {
	int i = a.size()-1, j = 0;
	while(a[i] > b[j]) {
		swap(a[i],b[j]);
		i--;
		j++;
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
}
void swapIfGreater(vector<int> &a, vector<int> &b , int i, int j) {
	if(a[i] > b[j])
		swap(a[i],b[j]);
}

// TC: log base 2 (n+m)
void optimal2GapMethod(vector<int> &a, vector<int> &b) {
	int n = a.size(),m = b.size();
	int len = n + m;
	int gap = (len / 2) + (len % 2)  ;
	while(gap > 0) {
		int left = 0;
		int right = left + gap;
		while(right < len) {
			if(left < n && right >= n){
				swapIfGreater(a,b,left,right-n);
			}
			else if(left >= n) { //both on the right array
				swapIfGreater(b,b,left-n,right-n);
			}
			//arr a and arr a
			else {
				swapIfGreater(a,a,left,right);
			}
			left++,right++;
		}
		if(gap == 1) break;
		gap = (gap/2) + (gap%2);
	}
}
int main() {
	init_code();
	vector<int> a = {1,4,5,7};
	vector<int> b = {2,3,6};
	optimal2GapMethod(a,b);
	for(auto x: a) cout << x << ",";
		cout << endl;
	for(auto x: b) cout << x << ",";
	return 0;
}
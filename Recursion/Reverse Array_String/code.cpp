#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}

void reverseArray(int beg, int end, vector<int> &vec) {
	if(beg >= end) return;
	swap(vec[beg],vec[end]);
	reverseArray(beg++,end--,vec);
}
int main() {
	init_code();
	vector<int> vec = {1,2,3,4,5};
	int n = vec.size();
	cout<<"Hi";
	reverseArray(0,n-1,vec);
	cout<<"reversed Array-" << endl;
	for(auto x: vec)
			cout<< x << "," ;
	return 0;
}
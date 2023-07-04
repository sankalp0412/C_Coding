//Reversing array approach
#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
void leftRotate(vector<int> &vec, int k) {
	reverse(vec.begin(),vec.begin()+k);
	reverse(vec.begin()+k+1, vec.end());
	reverse(vec.begin(),vec.end());
}
int main() {
	init_code();
	vector<int> vec = {1,2,3,4,5,6,7};
	int k;
	cin >> k;
	leftRotate(vec,k);
	for(auto it: vec)
		cout << it << ",";
	return 0;
}

//Tim com:

// O(d) + o(n-d) + O(n)
// = O(2n);

///Spcae
//O(1);
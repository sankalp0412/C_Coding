#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
bool possible(vector<int> &vec, int day, int k, int m){
	int numOfBouquets = 0;
	int cnt = 0;
	for(int i = 0; i < vec.size(); i++) {
		if(vec[i] <= day)
			cnt++;
		else {
			numOfBouquets += cnt / k;
			cnt = 0;
		}
	}
	numOfBouquets += cnt / k;

	return numOfBouquets >= m;
}
int minDays(vector<int> &vec, int m, int k) {
	if(m * 1ll * k * 1ll> vec.size()) return -1; //important thing to take care , we have to muliply with 1ll to avoid overflow
	int minD = *min_element(vec.begin(),vec.end());
	int maxD = *max_element(vec.begin(),vec.end());

	int low = minD, high = maxD;
	int mid;
	while(low <= high) {
		int mid = (low + high)/2;
		if(possible(vec,mid,k,m))
			high = mid -1;
		else
			low = mid + 1;
	}
	return low;
}
int main() {
	init_code();
	int n,m,k;
	cin >> n;
	vector<int> vec(n);
	for(int i = 0;i < n ; i++)
		 cin >> vec[i];
	
	cin >> m >> k;
	cout << minDays(vec,m,k);
	return 0;
}
#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
long double minimiseMaxDistanceBrute(vector<int> &arr, int &k) {
	int n = arr.size();
	vector<int> howManyPlaced (n-1,0);//this array will tell how many 
	//gas stations are placed at each section, like howManyPlaced[0]
	//will tell gas stations placed b/w 1 & 2 i.e the first section
	for(int gasStation = 1; gasStation <= k; gasStation++) {
		long double maxSection = -1;// we will find the section with max difference
		int maxInd  = -1 ;// this will keep track of the index of that max diff
		for(int i = 0; i < n-1; i++) {
			long double diff = arr[i+1] - arr[i];
			long double sectionLength =  diff/(long double)(howManyPlaced[i] + 1);

			if(sectionLength > maxSection){
				maxSection = sectionLength;
				maxInd = i;
			}
		}
		howManyPlaced[maxInd]++; // now we have placed the current gasstation at the current maxIndex
	}
	long double maxAns = -1;
	for(int i = 0; i < n-1; i++) {
		long double diff = arr[i+1] - arr[i];
		long double secLen = diff/(long double)(howManyPlaced[i] + 1);
		maxAns = max(maxAns,secLen);
	}
	return maxAns;
}

long double minimiseMaxDistanceBetter(vector<int> &arr, int &k) {
	int n = arr.size();
	vector<int> howManyPlaced (n-1,0);
	priority_queue<pair<long double,int> > pq;
	for(int i = 0; i < n-1; i++) {
			pq.push({arr[i+1]- arr[i], i}); //initially we will add all 
			//the section length and its index
	}
	for(int gasStation = 1; gasStation <= k; gasStation++) {
		auto tp = pq.top();
		int secInd = tp.second;
		howManyPlaced[secInd]++;//place the current gasStation at the ind with max diff
		long double iniDiff = arr[secInd+1] - arr[secInd];
		long double newSecLen = iniDiff / (long double)(howManyPlaced[secInd] + 1);
		pq.push({newSecLen,secInd});	
	}
	return pq.top().first;
}

long double minimiseMaxDistanceOptimal(vector<int> &arr, int &k) {
	
}
int main() {
	init_code();
	vector<int> arr = {1,2,3,4,5};
	int k =	4;
	cout << minimiseMaxDistanceBetter(arr,k);
	return 0;
}
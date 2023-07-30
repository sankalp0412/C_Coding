#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

vector<vector<int>> mergeBrute(vector<vector<int>>& intervals) {
	sort(intervals.begin(),intervals.end());
	vector<vector<int>> ans;
	int n = intervals.size();
	for(int i  = 0; i < n; i++) {
		int start = intervals[i][0];
		int end = intervals[i][1];
		if(!ans.empty() && end <= ans.back()[1]){
			//already lying in the prev interval
			continue; 
		}

		for(int j = i+1; j < n; j++) {
			if(intervals[j][0] <= end) {
				end = max(end, intervals[j][1]);
			}
			else break;
		}
		ans.push_back({start,end});
	}
	return ans;
}

vector<vector<int>> mergeOptimal(vector<vector<int>>& intervals) {
	sort(intervals.begin(),intervals.end());
	vector<vector<int>> ans;
	int n = intervals.size();
	for(int i  = 0; i < n; i++) {
		if(ans.empty() || intervals[i][0] > ans.back()[1]) {
			ans.push_back(intervals[i]);
		}
		//lying inside
		else{
			ans.back()[1] = max(ans.back()[1], intervals[i][1]);
		}
	}
	return ans;
}
int main() {
	init_code();
	vector<vector<int>> nums = {{1,3},{2,6},{8,10},{15,18}};
	mergeOptimal(nums);
	for(auto vec: nums) {
		cout << vec[0] << "," << vec[1] << endl;
	}
	return 0;
}
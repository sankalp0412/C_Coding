#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> pii;
void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

class Solution {
public:
	int bloomStarted(vector<vector<int>> &flowers, int time) {
		int n =flowers.size();
		int low = 0, high = n-1;
		while(low <= high) {
			int mid = (low + high) /2;
			if(flowers[mid][0] <= time)
				low = mid + 1;
			else 
				high = mid - 1;
		}
		return low;
	}
	int bloomFinished(vector<vector<int>> &flowers, int time) {
		int n =flowers.size();
		int low = 0, high = n-1;
		while(low <= high) {
			int mid = (low + high) /2;
			if(flowers[mid][1] < time)
				low = mid + 1;
			else 
				high = mid - 1;
		}
		return low;
	}
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        auto endTime = flowers;
        vector<int> ans;
        sort(flowers.begin(),flowers.end(),[](auto &a, auto &b) {
        	return a[0] < b[0];
        });

        sort(endTime.begin(),endTime.end(),[](auto &a, auto &b) {
        	return a[1] < b[1];
        });

        for(int i = 0 ; i < people.size(); i++) {
        	int visitTime = people[i];
        	int startedBlooming = bloomStarted(flowers,visitTime);
        	int finishedBloomin = bloomFinished(endTime,visitTime);
        	ans.push_back(startedBlooming - finishedBloomin);
        }
        return ans;
    }
};
int main() {
	init_code();
	vector<vector<int>> arr = {{1,4}, {3,5}, {3,6}, {3,10}, {4,13}, {5,7}, {2,10}, {11,14}};
	vector<int> people = {1,5,6,3,4};
	Solution solution;
	auto ans = solution.fullBloomFlowers(arr,people);
	for(auto x: ans) cout << x << endl;
	return 0;
}
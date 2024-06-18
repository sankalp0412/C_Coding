#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
class Solution {
public:
    #define pii pair<int,int>
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pii> tasks;
        int n = profit.size();
        for(int i = 0; i < n; i++) tasks.push_back({difficulty[i],profit[i]});
        sort(tasks.begin(),tasks.end());

        //the max profit a worker who can do till the ith task is actually the
        //the max profit of all tasks from 0 to i, as he can do all the task 
        //before that as well.
        for (int i = 0; i < tasks.size() - 1; i++) {
            tasks[i + 1].second =
                max(tasks[i].second, tasks[i + 1].second);
        }
       
         int netProfit = 0;
        for (int i = 0; i < worker.size(); i++) {
            int ability = worker[i];

            // Find the job with just smaller or equal difficulty than ability.
            int l = 0, r = tasks.size() - 1, jobProfit = 0;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (tasks[mid].first <= ability) {
                    jobProfit = max(jobProfit, tasks[mid].second);
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            // Increment profit of current worker to total profit.
            netProfit += jobProfit;
        }
        return netProfit;
    }
};
int main() {
	init_code();
	Solution sol;
	//profit does not increase with difficulty
	vector<int>  difficulty = {68,35,52,47,86}, profit = {67,17,1,81,3}, worker = {92,10,85,84,82};
	cout << sol.maxProfitAssignment(difficulty,profit,worker);
	return 0;
}
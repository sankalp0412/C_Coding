#include "bits/stdc++.h"
using namespace std;

// #define for(i,n) for(int i = 0; i < n; i++)

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
class Solution {
public:
    vector<int> topo(int sz, vector<int> adj[]) {
        // cout << "-----" << endl;
        vector<int> indegree(sz,0);
        for(int i = 0; i < sz; i++){
            for(auto x: adj[i])
            indegree[x]++;
        }
        queue<int> q;
        for(int i = 0; i < sz; i++){
            // cout << i << "-"<< indegree[i] << endl;
            if(!indegree[i]) q.push(i);
        }

        vector<int> res;

        while(!q.empty()) {
            int item = q.front();
            res.push_back(item);
            q.pop();
            for(auto befItem: adj[item]) {
                indegree[befItem]--;
                if(!indegree[befItem])
                q.push(befItem);
            }
        }
        return res;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<int> ans;
        unordered_map<int,vector<int>> grps; //group -> items;
        int groupId = m;
        for(int i = 0; i < n; i++) {
            if(group[i] == -1){
                grps[groupId].push_back(i);
                group[i] = groupId;
                groupId++;
            }
            else  
                grps[group[i]].push_back(i);
        }
        vector<int> depGroups[groupId];
        vector<int> depItems[n];

        for(int i = 0; i < n; i++){
            for(auto befItem: beforeItems[i]) {
                depItems[befItem].push_back(i);
                int grp1 = group[i];
                int grp2 = group[befItem];  
                if(grp1 == grp2) continue;             
                depGroups[grp2].push_back(grp1); 
            }
        }
        //tposort
        // for(auto vec: depGroups) {
        //     // for(auto x: vec ) cout << x << ",";
        //     cout << endl;
        // }
        vector<int> sortingGroups = topo(groupId,depGroups);
        vector<int> sortingItems = topo(n,depItems);
        // cout << "yes";

        if(sortingGroups.size() != groupId || sortingItems.size() != n) return {};

        unordered_map<int,int> mp;
        for(int i =0; i < n; i++){
            mp[sortingItems[i]] = i;
        }
        for(auto grp:sortingGroups) {
            auto vec = grps[grp];
            sort(vec.begin(),vec.end(),[&](auto &a, auto &b) {
                return mp[a] < mp[b];
            });
            for(auto x: vec) ans.push_back(x);
        }
        return ans;
    }
};
int main() {
	init_code();
	Solution solution;
	int n,m;
	n = 3;
	m = 1;
	vector<int> group = {-1,0,-1};
	vector<vector<int>> beforeItems = {{},{0},{1}};
	vector<int> ans = solution.sortItems(n,m,group,beforeItems);
	for(auto x: ans) cout << x << ",";
	return 0;
}

//here the mistake i was making earlier was that I was considering 
// all the items with no group into a single group 'm'
//hence was failing for this above case as it was giving a cycle in the groups
//now we are handling all the items with no groups [-1] into separate group 
// using groupId starting from m;
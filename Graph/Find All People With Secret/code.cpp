// https://leetcode.com/problems/find-all-people-with-secret/

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
class DSU{
    vector<int> parent,size;
    public:
        DSU(int n) {
            parent.resize(n);
            size.resize(n,1);
            for(int i = 0; i < n; i++) 
                parent[i] = i;
        }

        int findPar(int x) {
            if(parent[x] == x) return x;
            return parent[x] = findPar(parent[x]);
        }

        void unionFn(int x, int y) {
            int ux = findPar(x);
            int uy = findPar(y);
            if(ux == uy)
                return;
            
            else if(size[ux] > size[uy]) {
                parent[uy] = ux;
                size[ux] += size[uy];
            } 
            else {
                parent[ux] = uy;
                size[uy] += size[ux];
            }
            
        }

        bool connected(int x, int y) {
            return findPar(x) == findPar(y);
        }

        void reset(int x) {parent[x] = x;}
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(),meetings.end(),[&](vector<int> &a, vector<int> &b) {
            return a[2] < b[2];
        });

        map<int,vector<pair<int,int>> > sameTimeMeetings;

        for(auto & meeting: meetings) {
            int x = meeting[0], y = meeting[1], t = meeting[2];
            sameTimeMeetings[t].push_back({x,y});
        }
        DSU ds(n);
        ds.unionFn(firstPerson, 0);
        
        
        for(auto& [t,meet]: sameTimeMeetings) {
            for(auto &[x,y]: meet) 
                ds.unionFn(x,y);
        //For meetings taking place at the same time If any one knows the secret, both will be connected to 0.
            // If no one knows the secret, then reset.
        //basically once the meetings at the same time has taken place 
        //we can then check if ultimately they get connected to 0
        //if they don't then even following the right order they won't get connected i.e. know the secret
        //hence we rest them
           for(auto& [x,y]: meet) {
               if(!ds.connected(x,0)){
                   ds.reset(x);
                   ds.reset(y);
               }
           } 
        }
        
        vector<int> ans;
        
        for(int i = 0; i <n ; i++){
            if(ds.connected(0,i))
                ans.push_back(i);
        }

        return ans;
        
    }
};
int main() {
	init_code();
	int n = 6;
	vector<vector<int>> meetings = {{3,4,2},{1,2,1},{2,3,1}};
	int firstPerson = 1;
	Solution sol;
	vector<int> ans =  sol.findAllPeople(n,meetings,firstPerson);

	for(auto x: ans) cout << x << ",";
	return 0;
}


//here two meetings are happending at time 1/
// but if we do the meeting between 2,3 first
// then both of them will not learn the secret
//hence 1,2,1 should happen first
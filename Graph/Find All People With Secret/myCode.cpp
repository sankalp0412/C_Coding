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
    vector<int> parent;
    public:
        DSU(int n, int firstPerson) {
            parent.resize(n);
            for(int i = 0; i < n; i++) 
                parent[i] = i;
            
            parent[firstPerson] = 0;
        }

        int findPar(int x) {
            if(parent[x] == x) return x;
            return parent[x] = findPar(parent[x]);
        }

        void unionFn(int x, int y) {
            int ux = findPar(x);
            int uy = findPar(y);
            if(ux == 0 && uy == 0)
                return;
            
            else if(ux == 0) 
                parent[y] = 0;

            else if(uy == 0) 
                parent[x] = 0;
        }

};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(),meetings.end(),[&](vector<int> &a, vector<int> &b) {
            int x1 = a[0], y1 = a[1], t1 = a[2];
            int x2 = b[0], y2 = b[1], t2 = b[2];

            if(t1 == t2) {
                if(x1 == firstPerson || x1 == 0 || y1 == firstPerson || y1 == 0) 
                    return true;
                if(x2 == firstPerson || x2 == 0 || y2 == firstPerson || y2 == 0)
                    return false;
            }
             
            return t1 < t2;
            
        });

        DSU ds(n,firstPerson);

        for(auto meet: meetings) 
            ds.unionFn(meet[0],meet[1]);
        
        vector<int> ans;
        
        for(int i = 0; i <n ; i++){
            if(ds.findPar(i) == 0)
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
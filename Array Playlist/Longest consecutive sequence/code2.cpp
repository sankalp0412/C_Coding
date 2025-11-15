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
    
    public:
    vector<int> parent, size;
        DSU(int n ) {
            parent.resize(n+1);
            size.resize(n+1,1);

            for(int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }

    int findPar(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findPar(x);
    }

    void unionFn (int x, int y ) {

        int ux = findPar(x);
        int uy = findPar(y);
        if(ux == uy) return ;
        if(size[ux] > size[uy]) {
            size[ux] += size[uy];
            parent[uy] = ux;
        }
        else {
            size[uy] += size[ux];
            parent[ux] = uy;
        }
        
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        DSU ds(1e5 + 1);
        int ans = 0;
        unordered_map<int,int> mp;
        for(auto x: nums) mp[nums]++;
        for(auto &x: nums) {
            int before = x - 1;
            int after = x + 1;
            int ux = ds.findPar(x);
            if (x > 0 && mp.count(before)) {
                int ub = ds.findPar(before);
                ds.unionFn(ub,ux);
            }
            if (x < 1e5 && mp.count(after)){
                int ua = ds.findPar(after);
                ds.unionFn(ux,ua);
            }

            ans = max(ans, ds.size[ds.findPar(x)]);

            
        }

        return ans;
    }
};
int main() {
	init_code();
	return 0;
}
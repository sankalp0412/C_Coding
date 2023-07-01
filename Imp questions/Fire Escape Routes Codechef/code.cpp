#include <bits/stdc++.h>
using namespace std;
void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
const int MOD = 1e9 + 7;
class DSU {
public:
    vector<int> size, parent;

    DSU(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findPar(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findPar(parent[x]);
    }

    void unionFn(int x, int y) {
        int ux = findPar(x);
        int uy = findPar(y);
        if (ux == uy) return;
        if (size[ux] < size[uy]) {
            parent[ux] = uy;
            size[uy] += size[ux];
        }
        else {
            parent[uy] = ux;
            size[ux] += size[uy];
        }
    }
};

int main() {
	init_code();
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        int fireEscapes = 0, ways = 1;
        cin >> n >> m;
        DSU ds(n);
        for (int i = 0; i < m; i++) {
            int friendI, friendJ;
            cin >> friendI >> friendJ;
            ds.unionFn(friendI, friendJ);
        }
        for (int i = 1; i <= n; i++) {
            if (ds.findPar(i) == i)
                fireEscapes++;
        }
         int maxGroup = *max_element(ds.parent.begin(),ds.parent.end());

        // Create three arrays for each group
        vector<vector<int>> groups(maxGroup + 1);
        for (int i = 1; i <= n; i++) {
            groups[ds.parent[i]].push_back(i);
        }
        for(auto group: groups) {
            if(group.size()) {
                ways = (ways * group.size()) % MOD;
            }
        }
        cout << fireEscapes << " " << ways << endl; 
    }
    return 0;
}

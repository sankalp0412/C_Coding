#include <bits/stdc++.h>
using namespace std;


class DSU{
  public:
	vector<int> maxScores,owners;
    DSU(int n) {
        maxScores.resize(n+1); //this will store maxScore dish of the ith chef
        owners.resize(n+1);
        for(int i = 1; i<= n; i++)
            owners[i] = i;
    }
    int findOwner(int dish) {
        if(owners[dish] == dish)
            return dish;
        else 
            return owners[dish] = findOwner(owners[dish]);//path compression
    }
    
    void compete(int x, int y) {
        int chefX = findOwner(x);
        int chefY = findOwner(y);
        if(maxScores[chefX] == maxScores[chefY]) return;
        if(maxScores[chefX] < maxScores[chefY]) //Y chef won
            owners[x] = chefY;
        else 
            owners[y] = chefX;
    }
};
int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    DSU ds(n);
	    for(int i = 1; i <= n; i++) 
	        cin >> ds.maxScores[i];
	    int Q;
	    cin >> Q;
	    for(int i = 0; i < Q; i++) {
	       int type;
	       cin >> type;
	       if(type == 1) {
	       	int dish;
	           cin >> dish;
	           cout << ds.findOwner(dish) << endl;
	       }
	       else {
	       		int x,y;
	           cin >> x >> y;
	           if(ds.findOwner(x) == ds.findOwner(y))
	            cout << "Invalid query!" << endl;
	          else 
	            ds.compete(x,y);
	       }
	   }
	}
	return 0;
}

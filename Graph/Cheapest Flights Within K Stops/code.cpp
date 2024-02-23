#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

 int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int> > adj[n];
        for(auto vec: flights) {
            int u = vec[0];
            int v = vec[1];
            int price = vec[2];
            adj[u].push_back({v,price});
        }
        queue<pair<int, pair<int,int> > > q;
        //{stops,{node,dist}}
        q.push({0,{src,0}});
        vector<int> dij(n,INT_MAX);

        while(!q.empty()) {
            int stops = q.front().first;
            int node = q.front().second.first;
            int price = q.front().second.second;
            q.pop();

            if(stops > k) continue;
            for(auto itr: adj[node]) {
                int city = itr.first;
                int cost = itr.second;
                if(cost+price < dij[city] && stops <= k) {
                    dij[city] = cost+price;
                    q.push({stops+1, {city,cost + price}});
                }
            }
        }


        if(dij[dst] == INT_MAX) return -1;
        else return dij[dst];
    }
 int findCheapestPriceMyCodeWithSet(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> g[n];
        vector<int> dij(n, INT_MAX);

        for (auto f : flights) {
            int s = f[0];
            int d = f[1];
            int p = f[2];
            g[s].push_back({d, p});
        }

        set<pair<int, pair<int, int>>> s;  // {city,{price,stops}}
        dij[src] = 0;
        s.insert({src, {0, 0}});

        while (!s.empty()) {
            auto it = *(s.begin());
            int currCity = it.first;
            int currFair = it.second.first;
            int currStops = it.second.second;

            s.erase(it);

            if(currStops > k) continue;
            for (auto [nextCity, fair] : g[currCity]) {
                if(nextCity == 3) 
                    // cout << currCity << "," << currStops << "," << nextCity << endl;
                if (currFair + fair < dij[nextCity] && currStops <= k) {
                    dij[nextCity] = currFair + fair;
                    s.insert({nextCity, {currFair + fair, currStops + 1}});
                }
            }
        }
        return dij[dst] == INT_MAX ? -1 : dij[dst];
    }
int main() {
	init_code();
	int n = 5;
	vector<vector<int>> flights = {{0,1,1},{0,2,5},{1,2,1},{2,3,1},{3,4,1}};
	int src = 0;
	int dst = 4;
	int k = 2;

	cout << findCheapestPrice(n,flights,src,dst,k);

	return 0;
}

//here in the test case the cheapest way to go is
//0 -> 1 -> 2- > 3 -> 4
// but here the number of stops are more that k = 2
// hence if we use traditional dijkstra it wont get updated
// as the answer is to go from 0 -> 2 -> 3-> 4 with a cost of 7
// but dijsktra wont work here as it's a higher cost

//hence we can;t solve this using set 
//if we have to solve it using pq we need to sort on the basis of 
//number of stops

//else solve it using queue
//since the increase in number of stops is constant
//ie. one stop at a time 
//hence we can simply use a queue, as it will make sure 
// the shorted one is before 

//hence the path where we will reach 2 with the cost of 5 in 
// 1 stop will be addressed first 

//as we will have two values 
//1 - > {2,{5,1}}
//2 ->  {2,{2,2}}

//since set automatically stores in increasing order 
// hence 2 one will be addressed first which will
//then put value in the city 3, which will not change as it
//will be less than (3) the one coming in future (6) via the 1 path
#include "bits/stdc++.h"
using namespace std;


//The person with the highest ration will decide what
// the rate will be for each person, and that ratio will
// decide the wage ratio

//Q :    20 , 5, 10
//Ratio: 2.5, 6, 7

//Here again we will try to be greedy and pick the fist
//k element, as that could be our answer (maybe not)

// now when we will go further and check for ratio 7
// we will remove the guy with the highest quality yet
// as if our rate now is 7 will be paying the previous people
// also 7 so either we can remove 5 (7 * 5) or 20 (20 *7)
// so obviously we will remove 20;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = wage.size();
        vector<pair<double,int> > wqRatio(n);
        for(int i = 0; i < n; i++) {
            wqRatio[i] = {(double)wage[i]/quality[i] , quality[i]};
        }

        sort(wqRatio.begin(),wqRatio.end()); //sort on the basis of ratio first

        int total_quality = 0; //to keep track of the quality as we move, as the quality into currrate will be the total amount
        priority_queue<int> pq; // max heap to keep track of the current highest quality

        double ans = DBL_MAX;


        for(auto& [rate,q]: wqRatio){
            pq.push(q);
            total_quality += q;

            //if we have more than k element we are going to remove the one with the highest quality
            if(pq.size() > k){
                total_quality -= pq.top();
                pq.pop();
            }
            if(pq.size() == k)
                ans = min(ans, rate * total_quality);
            
         }
        
        
        return ans;
}
int main() {
	init_code();
	vector<int> quality = {10,20,5}, wage = {70,50,30};
	int k = 2;
	cout << mincostToHireWorkers(quality,wage,k);
	return 0;
}
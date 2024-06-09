#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

int maxProfit(vector<int>& prices) {
	int mini = prices[0], profit = 0;
	for(int i = 1; i < prices.size(); i++) {
		int cost = prices[i] - mini;
		profit = max(profit,cost);

		mini = min(mini,prices[i]);
	}
	return profit;
}
int main() {
	init_code();
	vector<int> prices = {7,1,5,3,6,4};
	cout << maxProfit(prices);
	return 0;
}
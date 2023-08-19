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
int fn(int mid, int n, int m) {
  long long ans = 1;
  for(int i = 1; i <= n; i++){
    ans *= mid;
    if(ans > m) return 2;
  }
  if(ans == m) return 1;
  else return 0;
}
int NthRoot(int n, int m) {
  int low = 1,high = m;
  while(low <= high) {
    int mid = low + (high - low)/2;
    int temp = fn(mid,n,m);
    if(temp == 1) return mid;
    else if(temp == 0)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}
int main() {
	init_code();
	int n=3,m=27;
	cout << NthRoot(n,m);
	return 0;
}
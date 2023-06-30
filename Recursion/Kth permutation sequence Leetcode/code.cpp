//first approcah is the brute force approcah
//where we will calculate all the permutaions and store in a daata strucure
//and sort it the k sequence will be at k-1 index
//TC of brute force: (n!) * N * O(n!logn!)  to store into ds


// in interiew alwas approach with the naive approach first

//this is important please watch video:
//https://www.youtube.com/watch?v=wT7gcXLYoao&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=21

//time complexity after optimization:
//TC: O(N) (as we are looking for 4 numbers) * O(n) (for removing each time)
//::: O(NSquare)
//SC: O(n)



#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

int main() {
	init_code();
	return 0;
}
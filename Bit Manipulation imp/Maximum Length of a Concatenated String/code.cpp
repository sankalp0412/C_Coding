#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> vec = {0};
        int ans = 0;
        for(auto &str: arr) {
            int dup = 0, bitVal = 0;
            for(auto ch: str) {
                dup |= bitVal & (1 << (ch - 'a')); 
                bitVal |=  1 << (ch - 'a');
            }

            if(dup > 0)
                continue;

            for(int i = vec.size() - 1; i >= 0; i--) {
                if((vec[i] & bitVal) > 0)
                    continue;
                vec.push_back(vec[i] | bitVal);
                ans = max(ans,__builtin_popcount(vec[i] | bitVal));
            }
        }
        return ans ;
    }
};
int main() {
	init_code();
	vector<string> arr ={"un","iq","ue"};
	Solution sol;
	cout << sol.maxLength(arr);
	return 0;
}

//line number 19
//we are using the dup variable to check if the current string of the array
//itself has any duplicates alphabets
//and the bitVal variable to find the value of the string in terms of bits
//here i will first do AND with my current value in bits 
//(so in case if i have duplcates i will get one set bit, and then 
// do an OR with dup so it won't be 0)

//lets say my strin is "abc" bitval will be 0111
//and now a new char comes as 'a'
//if i and it with bitval it will become 0001
// and now if i OR this with dup , dup will also become 0001


//Why are we traversing the vec array from back?

//in summary, traversing vec from back to front ensures that you 
// can dynamically add new substrings without affecting the elements
// you're currently iterating over, and it helps in avoiding conflicts
// when updating the vec array.

// so that we don't consider the element we just pushed



//he size of the dp array can grow as new elements are added during the 
// iteration. The worst-case scenario is that each string contributes a new 
// element to the dp array in each iteration of the outer loop. In this case,
 // the overall time complexity would be 
// O(N) where N is the total number of characters in all strings

// the overall space complexity is O(N).
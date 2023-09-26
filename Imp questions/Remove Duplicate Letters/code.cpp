//https://www.youtube.com/watch?v=rU5p0MRm5zU

// Using monotonic stack
// Increasin monotonic stack means the top is lexicographically lower than the element in the
//bottom


#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
string removeDuplicateLetters(string s) {
        vector<bool> taken(26,false); //to check if the element is already taken or not
        vector<int> lastIndex(26); // to keep track of the last index of the character
        for(int i = 0; i < s.size(); i++)
            lastIndex[s[i] - 'a'] = i;

        string res ="";
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            int idx = ch - 'a';
            
            if(taken[idx])
                continue;
            
            while(res.size() > 0 && res.back() > ch && lastIndex[res.back() - 'a'] > i){ // here we are checking if the element wil be available to be picked in the future so we can pop it now and pick later for lexicographical smallest
                taken[res.back() - 'a'] = false;
                res.pop_back();
            }
            res += ch;
            taken[ch - 'a'] = true;
        }
        return res;
    }
int main() {
	init_code();
	string s = "bcabc";
	// string s = "bcab"; this is to confirm that the taken array will be required as c can't be popped this time as it will not come again, and for b we will check the taken array to not take it again at the index 3
	cout << removeDuplicateLetters(s);
	return 0;
}
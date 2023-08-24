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
    void addLine(string currLine, vector<string> &ans, bool isLast, int &maxWidth) {
        if(currLine.size() == maxWidth){
            ans.push_back(currLine);
            return;
        }
        //Operations
        int n = currLine.size();
          int numWords = count(currLine.begin(), currLine.end(), ' ') + 1;
    int spacesToAdd = maxWidth - n;
    int spacesBetweenWords = (numWords == 1) ? spacesToAdd : spacesToAdd / (numWords - 1);
    int extraSpaces = (numWords == 1) ? 0 : spacesToAdd % (numWords - 1);
    
    string lineWithSpaces;
    stringstream ss(currLine);
    string word;
    ss >> word;
    lineWithSpaces += word;
    
    while (ss >> word) {
        lineWithSpaces += string(spacesBetweenWords + (extraSpaces > 0), ' ');
        extraSpaces = max(0, extraSpaces - 1);
        lineWithSpaces += word;
    }
    
    if (isLast) {
        lineWithSpaces += string(maxWidth - lineWithSpaces.size(), ' ');
    }
    
    ans.push_back(lineWithSpaces);
}

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        string currLine = "";
        int n = words.size();
        for(int i = 0; i < n; i++) {
            string currWord = words[i];
            if(currLine.size() + currWord.size() + 1 <= maxWidth) {
                if(currLine.size())
                    currLine += ' ';
                currLine += currWord;
            }
            else {
                // cout << currLine << endl;
                addLine(currLine,ans,false,maxWidth);
                currLine = currWord;
            }
        }
        addLine(currLine,ans,true,maxWidth);
    return ans;
    }
};
int main() {
    init_code();
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    Solution solution;
    auto ans = solution.fullJustify(words,maxWidth);
    for(auto str: ans){
        for(auto x: str) {
            if(x == ' ') cout << "_";
            else cout << x; 
        }
        cout << endl;
    }
    return 0;
}



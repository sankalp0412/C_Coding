#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
	int getDecimalValue2(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while(temp) {
            n++;
            temp = temp -> next;
        }
        int ans =0 ;
        temp = head;
        while(temp) {
            ans += pow(2,--n) * temp -> val;
            temp = temp -> next;
        }
        return ans;
    }
    int getDecimalValue(ListNode* head) {
        int ans = 0;

        while(head) {   
           ans = (ans << 1) | head -> val;
           head = head -> next;
        }

        return (int)ans;
    }
};

int main() {
	init_code();
	ListNode* node3 = new ListNode(1);
    ListNode* node2 = new ListNode(0, node3);
    ListNode* head = new ListNode(1, node2);

	Solution sol;
	cout << sol.getDecimalValue(head);


	return 0;
}
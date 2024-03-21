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

 void display(ListNode *head) {
	while(head) {
		cout << head -> val << "->";
		head = head -> next;
	}
	cout << endl;
}

ListNode *solve(ListNode *prev, ListNode *curr) {
    if(!curr)
        return prev;

    ListNode *temp = curr -> next; //the future curr 1 -> 2 -> 3 -> 4 (if curr = 2) then temp = 3
    curr -> next = prev; //Break the bond to the next node and assign it to previous i.e. break the bond 2 -> 3 and make it 2 -> 1

    return solve(curr, temp); // now the previous for the next one will be current in this call so solve(2,3)
}
ListNode* reverseListRecursion(ListNode* head) {
    ListNode *prev = NULL;
    ListNode *curr = head;
    head = solve(prev,curr);
    return head;
}

 ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        while(curr) {
            ListNode *temp = curr -> next;//keep track of the next node
            curr -> next = prev; //break the current bond and make it to the previous node
            prev = curr;//make the prev node to the current node
            curr = temp;//continue with the current which we made earlier
        }
        return prev;
}
int main() {
	init_code();
	ListNode *head = new ListNode(1);
	head -> next = new ListNode(2);
	head -> next -> next = new ListNode(3);
	head -> next -> next -> next = new ListNode(4);
	head -> next -> next -> next -> next = new ListNode(5);
	display(head);
	display(reverseListRecursion(head));
	return 0;
}

	

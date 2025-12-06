#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
class Node {
    public: 
        int value,key;
        Node *prev, *next;

        Node(int value, int key) : value(value), key(key), prev(nullptr), next(nullptr) {}
        Node(){
            this -> prev = NULL;
            this -> next = NULL;
        } 
};


class LRUCache {
public:
    Node *head = NULL;
    Node *tail = NULL;
    int capacity = -1;
    unordered_map<int, Node*> mp;
    void moveToFront(Node* ptr) {
        Node *prevNode = ptr -> prev;
        ptr -> next -> prev = prevNode;
        prevNode -> next = ptr -> next;
        

        Node * newNext = this -> head -> next;
        this -> head -> next = ptr;
        ptr -> next = newNext;
        ptr -> prev = head;
        newNext -> prev = ptr;
    }

    void deleteFromList() {
        Node *toDelete  = this -> tail -> prev;

        tail -> prev = toDelete -> prev;
        toDelete -> prev -> next = tail;

        delete toDelete;
    }

    Node* insertToList(int value, int key) {
        Node *temp = new Node(value,key);

        auto currTop = head -> next;
        head -> next = temp;
        temp -> prev = head;

        temp -> next = currTop;
        currTop -> prev = temp;

        return temp;
    }

    LRUCache(int capacity) {
        this -> capacity = capacity;
        this -> head = new Node(-1,-1);
        this -> tail = new Node(-1,-1);

        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(mp.count(key)){
            moveToFront(mp[key]);
            return mp[key] -> value;

        }

        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)) {
            mp[key] -> value= value;
            moveToFront(mp[key]);
        }
        else {
            if(mp.size() == capacity) {
                mp.erase(tail -> prev -> key);
                deleteFromList();
            }
            Node *inserted = insertToList(value,key);
            mp[key] = inserted;
        }
    }
};
int main() {
    init_code();
    return 0;
}
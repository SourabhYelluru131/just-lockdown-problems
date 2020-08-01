//https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    int flag;
    void helper(Node* head){
        Node* current = head;
        Node* lastparent;
        while(current->next || current->child){
            if(!current->child) current = current->next;
            else{
                flag = 1;
                lastparent = current;
                current = current->child;
            }
        }
        if(flag){
            current->next = lastparent->next;
            lastparent->next = lastparent->child;
            lastparent->child->prev = lastparent;
            lastparent->child = nullptr;
            if(current->next) current->next->prev = current;
            flag = 0;
            helper(head);
        }
    }
    Node* flatten(Node* head) {
        if(!head) return head;
        helper(head);
        return head;
    }
};

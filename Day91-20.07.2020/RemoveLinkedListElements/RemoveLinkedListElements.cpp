//https://leetcode.com/problems/remove-linked-list-elements/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;
        ListNode* current = head;
        while(current->val==val){
            head = current->next;
            current = head;
            if(!head) return nullptr;
        }
        while(current->next){
            if(!current) break;
            if(current->next->val==val) current->next = current->next->next;
            else if(current->next) current = current->next;
        }
        return head;
    }
};

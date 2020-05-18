//https://leetcode.com/problems/odd-even-linked-list/
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return nullptr;
        if(head->next == nullptr || head->next->next == nullptr) return head;
        queue<ListNode*> even;
        ListNode* current = head;
        ListNode* forward = current->next;
        ListNode* twof = forward->next;
        while(forward && twof){
            even.push(forward);
            current->next = twof;
            current = twof;
            forward = current->next;
            if(forward) twof = forward->next;
            else break;
        }
        if(current->next) even.push(current->next);
        while(!even.empty()){
            current->next = even.front();
            even.pop();
            current = current->next;
        }
        current->next = nullptr;
        return head;
    }
};

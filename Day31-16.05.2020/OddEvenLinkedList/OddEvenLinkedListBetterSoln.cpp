// Uses less space and runs faster
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
        ListNode* evenhead = nullptr;
        ListNode* evencurrent;
        ListNode* current = head;
        ListNode* forward = current->next;
        ListNode* twof = forward->next;
        while(forward && twof){
            if(!evenhead){
                evenhead = forward;
                evencurrent = forward;
            }
            else{
                evencurrent->next = forward;
                evencurrent = forward;
            }
            current->next = twof;
            current = twof;
            forward = current->next;
            if(forward) twof = forward->next;
            else{
                evencurrent->next = nullptr;
                break;
            }
        }
        if(forward) evencurrent->next = forward;
        evencurrent = evencurrent->next;
        current->next = evenhead;
        return head;
    }
};

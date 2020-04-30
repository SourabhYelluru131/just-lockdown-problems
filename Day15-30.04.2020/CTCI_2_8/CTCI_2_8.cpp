//  CTCI Linked Lists Problem 2.8
//  https://leetcode.com/problems/linked-list-cycle/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#pragma GCC optimize ("Ofast")
static auto _ = [] { std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0); std::cerr.tie(0); return 0; } ();            // 2 magical lines to speed up code :wink:
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *ptr1, *ptr2;
        if(!head) return false;
        ptr1 = head;
        if(!ptr1->next) return false;
        ptr2 = ptr1->next;
        while(ptr1->next && ptr2->next && ptr2->next->next){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
            if(ptr1==ptr2) return true;
        }
        return false;
    }
};

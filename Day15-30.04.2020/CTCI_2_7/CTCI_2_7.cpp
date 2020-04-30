//  Leetcode Linked List Problem 2.7
//  https://leetcode.com/problems/intersection-of-two-linked-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    struct TailStruct{
        ListNode *tail;
        int size;
    };
public:
    ListNode *Truncate(ListNode *head, int a, int b){
        ListNode *curr = head;
        for(;a>b;a--){
            curr = curr->next;
        }
        return curr;
    }
    TailStruct *getTail(ListNode *head){
        struct TailStruct *temp = (struct TailStruct*)malloc(sizeof(struct TailStruct));
        int ind = 1;
        ListNode *current = head;
        ListNode *after = current->next;
        while(after!=nullptr){
            current = after;
            after = after->next;
            ind++;
        }
        temp->tail = current;
        temp->size = ind;
        return temp;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return nullptr;  //Returns null if either head is NULL
        TailStruct *a = getTail(headA);    //Gets Tail Address of A
        TailStruct *b = getTail(headB);    //Gets Tail Address of B
        int size_A = a->size;
        int size_B = b->size;
        if(a->tail != b->tail) return nullptr;   //If tail address does not match, return null
	// If tail matches, if the lengths are unequal, truncate the longer linked list until both lengths are equal
        if(size_A>size_B) headA = Truncate(headA,size_A,size_B);
        else if(size_B>size_A) headB = Truncate(headB,size_B,size_A);
        ListNode *currA = headA;
        ListNode *currB = headB;
        while(currA && currB && currA != currB){    //Check when are the two lists intersecting
            currA = currA->next;
            currB = currB->next;
        }
        return currA;
    }
};

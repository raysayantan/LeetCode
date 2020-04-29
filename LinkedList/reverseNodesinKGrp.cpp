/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
*/
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
    ListNode* revList(ListNode* start, ListNode* end){
        ListNode *c = NULL, *p = NULL, *n = NULL;
        if(start == NULL) return NULL;
        if(start->next == NULL) return start;
        c = start;
        
        while(c != end){
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        return p;
        
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *start = NULL;
        ListNode *prevEnd = NULL;
        ListNode *newEnd = NULL;
        ListNode *newBegin = NULL;
        ListNode* p = head;
        ListNode* s = NULL;
        int count = 0;
        while(true){
            count = 0;
            newEnd = p;
            s = p;
            while(p){
                p = p->next;
                count++;
                if(count == k) break;
            }
            
            if(count == k){
                newBegin = revList(s, p);
                if(start == NULL){
                    start = newBegin;
                } else {
                    prevEnd->next = newBegin;
                }
                prevEnd = newEnd;
            } else {
                //need to check left over nodes
                prevEnd->next = s;
                break;
            }
        }
        
        return start;
    }
};

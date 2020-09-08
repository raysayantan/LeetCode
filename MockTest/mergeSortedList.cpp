/*
Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
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
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL){
            return NULL;
        }        
        if(l1 == NULL){
            return l2;
        }        
        if(l2 == NULL){
            return l1;
        }
        
        ListNode* start = NULL;
        ListNode* p = NULL;
        ListNode* q = NULL;
        
        p = (l1->val < l2->val) ? l1 : l2;
        q = (l1->val < l2->val) ? l2 : l1;
        ListNode* c = NULL;
        if(start == NULL){
            start = p;
            c = p;
            p = p->next;
        }
        
        while(p && q){
            if(p->val < q->val){
                c->next = p;
                p = p->next;
            } else {
                c->next = q;
                q = q->next;
            }
            
            c = c->next;
        }
        
        while(p){
            c->next = p;
            p = p->next;
            c = c->next;
        }
        
        while(q){
            c->next = q;
            q = q->next;
            c = c->next;
        }
        
        return start;
    }
};

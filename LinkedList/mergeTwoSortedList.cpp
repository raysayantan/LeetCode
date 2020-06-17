/*
Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes 
of the first two lists.
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
        ListNode* start = NULL;
        ListNode* p = NULL;
        ListNode* q = NULL;
        ListNode* c = NULL;
        
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        //assign the smaller value to p and other one to q
        if(l1->val < l2->val){
            p = l1;
            q = l2;
        } else {
            p = l2;
            q = l1;
        }
        
        //Assign the start node with p
        if(start == NULL){
            start = p;
            p = p->next;
            c = start;
        }
        
        //loop while both are not null
        while( p && q){
            if(p->val < q->val){
                c->next = p;
                p = p->next;
            } else {
                c->next = q;
                q = q->next;
            }
            c = c->next;
        }
        
        if(p){
            c->next = p;
        } else {
            c->next = q;
        }
        
        return start;
    }
};

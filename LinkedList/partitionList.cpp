/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
Example:
Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
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
    ListNode* partition(ListNode* head, int x) {
        //If a NULL list return it
        if(head == NULL)
            return NULL;
        ListNode* first = NULL;
        ListNode* second = NULL;
        ListNode* fStart = NULL;
        ListNode* sStart = NULL;
        ListNode* start = NULL;
        ListNode* p = head;
        
        //Idea is to split the list in 2 part
        //fFirst - will point to the list containing all smmaler than x
        //sFirst - Point to all the element greater or equal x
        if(p->val >= x){
            sStart = p;
            second = p;
        } else {
            fStart = p;
            first = p;
        }
        p = p->next;
        while(p){
            if(p->val >= x){
                if(sStart == NULL){
                    sStart = p;
                    second = p;
                } else {
                    second->next = p;
                    second = second->next;
                }
            } else {
                if(fStart == NULL){
                    fStart = p;
                    first = p;
                } else {
                    first->next = p;
                    first = first->next;
                }
            }
            p = p->next;
        }
        
        if(fStart){
            start = fStart;
            first->next = sStart;
        } else {
            //if there are no smaller element than x
            start = sStart;
        }
        
        //If there atleast one element greater than or equal to x
        if(second)
            second->next = NULL;
        
        return start;
    }
};

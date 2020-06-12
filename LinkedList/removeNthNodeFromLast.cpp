/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;
        ListNode* forward = head;
        ListNode* backward = NULL;
        //first move till n nodes and then move two pointer simulteneously 
        //untill the first one move to last node
        for(int i = 0; i < n; i++){
            forward = forward->next;
        }
        if(forward){
            backward = head;
        }
        //Move till the forward moved to last node
        while(forward && forward->next != NULL){
            forward = forward->next;
            backward = backward->next;
        }
        
        //When we have to remove the head node
        if(backward == NULL){
            ListNode* t = head;
            head = head->next;
            delete t;
            t = NULL;
        } else {
            ListNode* t = backward->next;
            backward->next = t->next;
            delete t;
            t = NULL;
        }
        
        return head;
    }
};

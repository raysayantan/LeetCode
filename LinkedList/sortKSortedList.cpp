/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    class ListNodeComp{
      public:
        bool operator()(ListNode* p1, ListNode *p2){
            return p1->val > p2->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, ListNodeComp> pQueue;
        for(int i = 0; i < lists.size(); i++){
            ListNode* list = lists[i];
            while(list != NULL){
                pQueue.push(list);
                list = list->next;
            }
        }
        ListNode* start = NULL;
        ListNode* p = NULL;
        while(!pQueue.empty()){
            ListNode* list = pQueue.top();
            list->next = NULL;
            pQueue.pop();
            
            if(start == NULL){
                start = list;
                p = start;
            } else {
                p->next = list;
                p = p->next;
            }
        }
        
        return start;
    }
};

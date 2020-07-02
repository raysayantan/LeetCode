/*
Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

 

(Note that in the examples below, all sequences are serializations of ListNode objects.)

Example 1:

Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.
Example 2:

Input: head = [1,2,3,-3,4]
Output: [1,2,4]
Example 3:

Input: head = [1,2,3,-3,-2]
Output: [1]
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* p = head;
        ListNode* q = NULL;
        ListNode* prev = NULL;
        
        //map to store the sum and corresponding node to make that sum
        map<int, ListNode*> tracker;
        int sum = 0;
        
        while(p){
            sum += p->val;
            if(p->val == 0)
            {
                //node value itself 0 and remove that
                if(prev == NULL){
                    //we are head node so head need to be adjusted
                    ListNode* temp = head;
                    head = p->next;
                    p = p->next;
                    temp->next = NULL;
                    continue;
                } else {
                    ListNode* temp = p;
                    prev->next = p->next;
                    p = p->next;
                    temp->next = NULL;
                    continue;
                }
                continue;
            }
            if(sum == 0){
                //all nodes since begining sums to zero, delete all
                head = p->next;
                prev = NULL;
                p = head;
                tracker.clear();
                continue;
            } else if(tracker.find(sum) != tracker.end()){
                auto it = tracker.find(sum);
                q = tracker[sum];                
                sum = it->first;
                ListNode* temp = q->next;
                int t = sum;
                //need to erase all the nodes from map from temp till the end
                while(temp != p){
                    t += temp->val;
                    tracker.erase(t);
                    temp = temp->next;
                }
                q->next = p->next;
                p = p->next;
                prev = q;
                continue;
            } else {
                tracker.insert({sum,p});
            }           
            prev = p;
            p = p->next;
        }
        return head;
    }
};

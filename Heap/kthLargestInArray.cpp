/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
Example 1:
Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //Idea is to put the element in a max heap and extract
        //element one after another untill reach the kth one.
        priority_queue<int, vector<int>, less<>> pq;
        for(int idx = 0; idx < nums.size(); idx++){
            pq.push(nums[idx]);
        }
        
        //now keep a counter and pop element one after another till we get the kth one
        int counter = 0;
        int res = -1;
        while(!pq.empty()){
            counter++;
            res = pq.top();
            pq.pop();
            if(counter == k)
                break;
        }
        return res;
    }
};

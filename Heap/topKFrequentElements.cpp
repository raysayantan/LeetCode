/*
Given a non-empty array of integers, return the k most frequent elements.
Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:
Input: nums = [1], k = 1
Output: [1]
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.
Accepted
*/
class Solution {
    //funtor for Max heap i.e. for the priority queue to have higher value at the top
    //and in the pair first value is the number and the second is the frequency. Priority
    //queue will be sorted on the frequency in decending order
    struct comparator{
        public:
        bool operator()(pair<int,int> &first, pair<int,int> &second){
            return first.second < second.second;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //map to contain the frequency of each number occurances
        unordered_map<int, int> container;
        for(int i = 0; i < nums.size(); i++){
            if(container.find(nums[i]) != container.end()){
                container[nums[i]]++;
            } else {
                container.insert({nums[i], 1});
            }
        }
        
        //put each element in the priority queue and will extract the top k elements
        priority_queue<pair<int,int>, vector<pair<int,int>>, comparator> pq; 
        for(auto it = container.begin(); it != container.end(); it++){
            pq.push(make_pair(it->first, it->second));
        }
        
        vector<int> result;
        for(int i = 0; i < k; i++){
            result.push_back(pq.top().first);
            pq.pop();
        }
        
        return result;
    }
};

/*
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:

Input: nums = [1, -1, 5, -2, 3], k = 3
Output: 4 
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
Example 2:

Input: nums = [-2, -1, 2, 1], k = 1
Output: 2 
Explanation: The subarray [-1, 2] sums to 1 and is the longest.
Follow Up:
Can you do it in O(n) time?
*/
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int maxlen = 0;
        if(nums.size() == 0){
            return 0;
        }
        
        for(int idx = 1; idx < nums.size(); idx++){
            nums[idx] += nums[idx - 1];
        }
        
        unordered_map<int, int> mapper;
        mapper.insert({0, -1});
        
        for(int idx = 0; idx < nums.size(); idx++){
            int target = nums[idx] - k;
            auto it = mapper.find(target);
            if(it != mapper.end()){
                maxlen = max(maxlen, idx - it->second);
            }
            
            if(mapper.find(nums[idx]) == mapper.end()){
                mapper[nums[idx]] = idx;
            }
        }
        
        return maxlen;
    }
};

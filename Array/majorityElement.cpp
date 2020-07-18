/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> counter;
        for(int idx = 0; idx < nums.size(); idx++){
            counter[nums[idx]]++;
        }
        
        int target = INT_MIN;
        for(auto it = counter.begin(); it != counter.end(); it++){
            if(it->second > nums.size()/2){
                target = it->first;
                break;
            }
        }
        
        return target;
    }
};

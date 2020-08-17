/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back({});
        for(int idx = 0; idx < nums.size(); idx++){
            int size = result.size();
            for(int setIdx = 0; setIdx < size; setIdx++){
                vector<int> tempSet = result[setIdx];
                tempSet.push_back(nums[idx]);
                result.push_back(tempSet);
            }
        }
        
        return result;
    }
};

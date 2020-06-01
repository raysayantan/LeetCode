/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
*/
class Solution {
    int combinationSumUtil(map<int, int> &combinationSum,vector<int>& nums, int target){
        if(target == 0) return 1;
        int counter = 0;
        if(combinationSum.find(target) != combinationSum.end()){
            return combinationSum[target];
        }
        for(int i = 0; i < nums.size(); i++){
            if(target - nums[i] >= 0){
                counter += combinationSumUtil(combinationSum, nums, target - nums[i]);
            }
        }
        combinationSum.insert({target,counter});
        return counter;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        map<int, int> combinationSum;
        return combinationSumUtil(combinationSum, nums, target);
    }
};

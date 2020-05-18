/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int maxSum = INT_MIN;
        bool allNegative = true;
        for(int i = 0; i < len; i++){
            if(nums[i] >= 0) {
                allNegative = false;
                break;
            }
            if(nums[i] < 0 && maxSum < nums[i]){
                maxSum = nums[i];
            }
        }
        
        if(allNegative) return maxSum;
        maxSum = 0;
        int currSum = 0;
        for(int i = 0; i < len; i++){
            currSum += nums[i];
            if(currSum < 0){
                currSum = 0;
                continue;
            }
            if(currSum > maxSum){
                maxSum = currSum;
            }
        }
        
        return maxSum;
    }
};

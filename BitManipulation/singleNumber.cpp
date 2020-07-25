/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int target = nums[0];
        //if we do XOR of two same number it will be zero. Using this strategy
        //we are going to XOR of all the numbers. So the final output will be 
        //the number appearing once
        for(int idx= 1; idx < nums.size(); idx++){
            target ^= nums[idx];
        }
        
        return target;
    }
};

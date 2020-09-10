/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] result = new int[nums.length];
        
        int prod = nums[0];
        result[0] = 1;
        for(int idx = 1; idx < nums.length; idx++){
            result[idx] = prod;
            prod *= nums[idx];
        }
        
        prod = 1;
        for(int idx = nums.length - 1; idx >= 0; idx--){
            result[idx] = prod * result[idx];
            prod *= nums[idx];
        }
        
        return result;
    }
}

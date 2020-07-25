/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //we will the formula of AP series sum to find out
        //the missing number as the numbers are in AP but one
        //is missing. The fomula is n(n+1)/2
        int l = nums.size();
        int sum = (l * (l + 1))/2;
        
        //now will loop through the array and subtract each number
        //and finally we will get the missing one
        for(int i = 0; i < l; i++){
            sum -= nums[i];
        }
        
        //remaining number is the one we are looking for
        return sum;
    }
};

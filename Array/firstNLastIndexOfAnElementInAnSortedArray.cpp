/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
class Solution {
    int firstOccurance(vector<int> nums, int target){
        int len = nums.size();
        int first = len;
        int low = 0;
        int high = len -1;
        
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] >= target){
                first = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return first;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccurance(nums, target);
        int last = firstOccurance(nums, target + 1) - 1;
        
        if(first <= last){
            return {first, last};
        } else{
            return {-1, -1};
        }
    }
};

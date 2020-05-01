/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?
*/
class Solution {
    bool binarySearch(vector<int> &nums, int low, int high, int target){
        if(low > high) return false;
        bool status = false;
        int mid = (low + high)/2;
        if(nums[mid] == target) return true;
        bool leftSorted = false;
        bool rightSorted = false;
        
        if(low <= mid -1 && nums[low] <= nums[mid-1]) leftSorted = true;
        if(mid + 1 <= high && nums[high] >= nums[mid+1]) rightSorted = true;
        
        if(leftSorted && rightSorted){
            if(target >= nums[mid+1] && target <= nums[high]){
                status |= binarySearch(nums, mid+1, high, target);
            } else {
                status |= binarySearch(nums, low, mid-1, target);
                if(!status)
                    status |= binarySearch(nums, mid+1, high, target);
            }
        } else if(leftSorted){
            if(target >= nums[low] && target <= nums[mid-1]){
                status |= binarySearch(nums, low, mid-1, target);
            } else {
                status |= binarySearch(nums, mid+1, high, target);
            } 
        } else if(rightSorted){
            if(target >= nums[mid+1] && target <= nums[high]){
                status |= binarySearch(nums, mid+1, high, target);
            } else {
                status |= binarySearch(nums, low, mid-1, target);
            }
        }
        
        return status;
    }
public:
    bool search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};

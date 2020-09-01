/*
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if(nums1.size() == 0 || nums2.size() == 0){
            return result;
        }
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int idx1 = 0; 
        int idx2 = 0;
               
        while(idx1 < nums1.size() && idx2 < nums2.size()){
            if(nums1[idx1] == nums2[idx2]){
                result.push_back(nums1[idx1]);
                idx1++;
                idx2++;
            } else if(nums1[idx1] < nums2[idx2]){
                idx1++;
            } else if(nums1[idx1] > nums2[idx2]){
                idx2++;
            }
        }
        
        return result;
    }
};

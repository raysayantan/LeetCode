/*
You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in 
the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if(nums1.size() == 0 || nums2.size() == 0){
            return result;
        }
        unordered_map<int, int> indexer;
        for(int idx = 0; idx < nums2.size(); idx++){
            indexer[nums2[idx]] = idx; 
        }
        
        for(int idx1 = 0; idx1 < nums1.size(); idx1++){
            int start = indexer[nums1[idx1]];
            int num = nums1[idx1];
            int greater = -1;
            for(int idx2 = start + 1; idx2 < nums2.size(); idx2++){
                if(nums2[idx2] > num){
                    greater = nums2[idx2];
                    break;
                }
            }
            
            result.push_back(greater);
        }
        
        return result;
    }
};

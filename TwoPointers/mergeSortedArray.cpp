/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
 

Constraints:

-10^9 <= nums1[i], nums2[i] <= 10^9
nums1.length == m + n
nums2.length == n
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nEnd = n - 1;
        int mEnd = m - 1;
        int pos = m + n -1;
        //We will start from the end so that the bigger value will be at the end position.
        //Whichever value is bigger will put that at the end at nums1 and decrement that pos
        //pointer and decreament the bigger pointer as well
        while(nEnd >= 0 && mEnd >= 0){
            if(nums1[mEnd] > nums2[nEnd]){
                nums1[pos--] = nums1[mEnd--]; 
            } else {
                nums1[pos--] = nums2[nEnd--];
            }
        }
        
        while(mEnd >= 0){
            nums1[pos--] = nums1[mEnd--];
        }
        
        while(nEnd >= 0){
            nums1[pos--] = nums2[nEnd--];
        }
    }
};

/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.
Example 1:
nums1 = [1, 3]
nums2 = [2]
The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int k = 0;
        int l1 = nums1.size();
        int l2 = nums2.size();
        int mid = (l1 + l2)/2;
        
        //Idea is to move in the arrays in sorted order and
        //position i and k at the location which will include
        //all the lements till the median position
        while(i + k < mid && i < l1 && k < l2){
            (nums1[i] < nums2[k]) ? i++ : k++; 
        }
        
        //If we reached end of second array but still to reach the median
        if(i + k < mid && i < l1){
            i = i + (mid - (i + k));
        }
        
        //If we reached the 1st array last element but still to reach the median
        if(i + k < mid && k < l2){
            k = k + (mid - (i + k));
        }
        
        //when we traversed one whole array it will point to the next to the last
        //so we need to decrement that index, so that i and k should be in the index 
        //less or equal meadian position
        if(i == l1) i--;
        if(k == l2) k--;
        
        //if we are just next to the median index
        if(i + k == mid){
            (nums1[i] > nums2[k]) ? i-- : k--;
        }
        
        //if both i and k are valid index in the arrays
        //idex till median includes elements from both arrays
        if(i >= 0 && k >= 0){
            //even num of elements
            if((l1 + l2) % 2 == 0){
                int v1 = max(nums1[i], nums2[k]);   
                int v2;
                if(nums1[i] < nums2[k]){
                    v2 = (k - 1 >= 0) ? max(nums2[k-1], nums1[i]) : nums1[i];
                } else {
                    v2 = (i - 1 >= 0) ? max(nums2[k], nums1[i - 1]) : nums2[k];
                }
                return (double)(v1 + v2)/2;
            } else {
                //odd num of elements
                return (double)max(nums1[i], nums2[k]);
            }
        } else {
            //all the elements till the median index are from one of the arrays
            if(i < 0){
                //even number of elements
                if((l1 + l2)%2 == 0){
                    return (double)(nums2[k] + nums2[k - 1])/2;
                } else {
                    //odd number of elements
                    return (double)nums2[k];
                }
            } else {
                //Even number of elemnts
                if((l1 + l2)%2 == 0){
                    return (double)(nums1[i] + nums1[i - 1])/2;
                } else {
                    //odd number of elements
                    return (double)nums1[i];
                }
            }
        }
    }
};

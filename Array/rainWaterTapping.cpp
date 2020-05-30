/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.
Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax = 0;
        int rightMax = 0;
        int capacity = 0;
        int l = height.size();
        if(l <= 2) return 0;
        int start = 0;
        int end = l - 1;
        /*
        Idea is to get the min of left and right, so that in a particular index we do
        have water leftMax/rightMax - value at index i;
        */
        while(start <= end){
            if(height[start] < height[end]){
                if(height[start] > leftMax){
                    leftMax = height[start];
                } else {
                    capacity += leftMax - height[start];
                }
                start++;
            } else {
                if(height[end] > rightMax){
                    rightMax = height[end];
                } else {
                    capacity += rightMax - height[end];
                }
                end--;
            }
        }
        
        return capacity;
    }
};

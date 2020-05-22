/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn 
such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, 
such that the container contains the most water.
Note: You may not slant the container and n is at least 2.
Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int forward = 0;
        int backward = height.size() - 1;
        int maxCapacity = 0;
        while(forward < backward){
            int temp = min(height[forward], height[backward])*(backward - forward);
            if(temp > maxCapacity){
                maxCapacity = temp;
            }
            
            if(height[forward] < height[backward]){
                forward++;
            } else {
                backward--;
            }
        }
        
        return maxCapacity;
    }
};

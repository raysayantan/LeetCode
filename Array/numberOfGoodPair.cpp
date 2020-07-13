/*
Given an array of integers nums.

A pair (i,j) is called good if nums[i] == nums[j] and i < j.

Return the number of good pairs.

 

Example 1:

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
Example 2:

Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.
Example 3:

Input: nums = [1,2,3]
Output: 0
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
*/
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> v(101,0);
        int len = nums.size();
        int total = 0;
        
        //first store the number of occurances of each number in a vector.
        //in index 1, it will store the occurances of number 1's at index 1
        for(int i = 0; i < len; i++){
            v[nums[i]]++;
        }
        
        //pick the one with value more than 1, i.e. that is occuring multiple times
        //then calculate the pairing, if num occuring n times then it will be n*(n-1)/2
        for(int i = 0; i < v.size(); i++){
            if(v[i] > 1){
                total += (v[i]*(v[i] - 1))/2;
            }
        }
        
        return total;
    }
};

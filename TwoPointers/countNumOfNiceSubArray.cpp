/*
Given an array of integers nums and an integer k. A subarray is called nice if there are k odd numbers on it.
Return the number of nice sub-arrays. 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
 

Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length
*/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l = nums.size();
        vector<int> indexer;
        //first get all the indexes having odd numbers;
        for(int i = 0; i < l; i++){
            if(nums[i] %2 != 0){
                indexer.push_back(i);
            }
        }
        
        //if the indexer size less than k, then there is no such subarray
        if(indexer.size() < k)
            return 0;
        int total = 0;
        int s = 0;
        int e = k - 1;
        //loop through the indexer array, will keep a window of size k. Will calculate the number of
        //elements to the left of the start of the window where all are even and the number of elements
        //to the right of the windows that are all even. Total number of subarrays possible for this window
        //will be (1 + num of elements to the right(m) + number of elements to the left(n) + (m*n))
        while(e < indexer.size()){
            int start = indexer[s];
            int end = indexer[e];
            int num_of_left_ele = 0, num_of_right_ele = 0;
            if(s > 0){
                num_of_left_ele = start - indexer[s -1] - 1;
            } else {
                num_of_left_ele = start;
            }
            
            if(e < indexer.size() - 1){
                num_of_right_ele = indexer[e + 1] - indexer[e] - 1;
            } else {
                num_of_right_ele = l - indexer[e] - 1;
            }
            
            total += (num_of_right_ele + num_of_left_ele + num_of_left_ele*num_of_right_ele + 1);
            s++;
            e++;
        }
        return total;
    }
};

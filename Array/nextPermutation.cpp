/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int smallerIdx = -1;
        //first element that is less than its next
        for(int i = nums.size() - 1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                smallerIdx = i -1;
                break;
            }
        }
        
        if(smallerIdx == -1){
            //list already is sorted (desc)
            reverse(nums.begin(), nums.end());
            return;
        }
        
        //find the first element from right to smallerIdx greater than smallerIdx value
        int greaterIdx = -1;
        for(int i = nums.size() - 1; i > smallerIdx; i--){
            if(nums[i] > nums[smallerIdx]){
                greaterIdx = i;
                break;
            }
        }
        int t = nums[smallerIdx];
        nums[smallerIdx] = nums[greaterIdx];
        nums[greaterIdx] = t;
        
        //sort from smallerIdx + 1 till end
        sort(nums.begin() + smallerIdx + 1, nums.end());
    }
};

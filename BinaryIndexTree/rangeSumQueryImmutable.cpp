/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/
class NumArray {
    vector<int> bit;
    void createBinaryIndexTree(vector<int> nums){
        for(int i = 0; i < nums.size(); i++){
            int index = i + 1;
            while(index < bit.size()){
                bit[index] += nums[i];
                index += index & (-index);
            }
        }
    }
    
    int sum(int index){
        index = index + 1;
        int res = 0;
        while(index > 0){
            res += bit[index];
            index -= index & (-index);
        }
        
        return res;
    }
public:
    NumArray(vector<int>& nums) {
        bit.resize(nums.size() +  1, 0);
        createBinaryIndexTree(nums);
    }
    
    int sumRange(int i, int j) {
        return (sum(j) - sum(i - 1));
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

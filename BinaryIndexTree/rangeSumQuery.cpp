/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.

Example:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:

The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
*/
class NumArray {
    vector<int> data;
    vector<int> nums;
    int size;
    void createBIT(vector<int> nums){
        for(int i = 0; i < size; i++){
            updateInternal(i, nums[i]);
        }
    }
    
    int sumFirstN(int i){
        int sum = 0;
        while(i > 0){
            sum += data[i];
            i -= (i & (-i));
        }
        
        return sum;
    }
    void updateInternal(int i, int val) {
        i = i + 1;
        while(i <= size){
            data[i] += val;
            i += (i & (-i));
        }
    }
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        data.resize(nums.size() + 1);
        size = nums.size();
        for(int i = 0; i <= size; i++){
            data[i] = 0;
        }
        createBIT(nums);
    }
    
    void update(int i, int val) {
        int temp = nums[i];
        nums[i] = val;
        i = i + 1;
        while(i <= size){
            data[i] = data[i] - temp + val;
            i += (i & (-i));
        }
    }
    
    int sumRange(int i, int j) {
        return sumFirstN(j+1) - sumFirstN(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

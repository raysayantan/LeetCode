/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //We will XOR all the numbers then we will get the two numbers xor that
        //are occuring only once. The XOR of these two elements must have atleast
        //one bit set as these two elements are distinct. So we will get the right
        //most set bit of these two numbers' xor. Now in second pass we will create
        //two set of numbers - One with the numbers which are all having the bit set
        //on the particular position of the XOR elements(right most) and the other set
        //having that bit unset(0). With this these two number will fall in two 
        //different group and the rest will be zeroed out with XOR
        int xor_of_all = 0;
        for(int numIdx = 0; numIdx < nums.size(); numIdx++){
            xor_of_all ^= nums[numIdx];
        }
        
        //Will get the rightmost set bit of XOR-ed one
        xor_of_all &= (-xor_of_all);
        
        //loop again to form the two seperate group as mentioned in the above comment
        vector<int> result(2,0);
        for(int numIdx = 0; numIdx < nums.size(); numIdx++){
            if(xor_of_all & nums[numIdx]){
                result[1] ^= nums[numIdx];
            } else {
                result[0] ^= nums[numIdx];
            }
        }
        return result;
    }
};

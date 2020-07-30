/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/
class Solution {
public:
    //ones - At any point of time, this variable holds XOR of all the elements which have
    //appeared "only" once. 
    //twos - At any point of time, this variable holds XOR of all the elements which have
    //appeared "only" twice.

    //So if at any point time,
    //1. A new number appears - It gets XOR'd to the variable "ones".
    //2. A number gets repeated(appears twice) - It is removed from "ones" and XOR'd to the
    //variable "twice".
    //3. A number appears for the third time - It gets removed from both "ones" and "twice".

    //The final answer we want is the value present in "ones" - coz, it holds the unique element.

    //So if we explain how steps 1 to 3 happens in the code, we are done.
    //Before explaining above 3 steps, lets look at last three lines of the code,

    //not_threes = ~(ones & twos)
    //ones & = not_threes
    //twos & = not_threes

    //All it does is, common 1's between "ones" and "twos" are converted to zero.

    //For simplicity, in all the below explanations - consider we have got only 4 elements in the array (one unique     //element and 3 repeated elements - in any order).

    //Explanation for step 1
    //------------------------
    //Lets say a new element(x) appears.
    //CURRENT SITUATION - Both variables - "ones" and "twos" has not recorded "x".

    //Observe the statement "twos| = ones & x".
    //Since bit representation of "x" is not present in "ones", AND condition yields nothing. So "twos" does not get     //bit representation of "x".
    //But, in next step "ones ^= x" - "ones" ends up adding bits of "x". Thus new element gets recorded in "ones"       //but not in "twos".

    //The last 3 lines of code as explained already, converts common 1's b/w "ones" and "twos" to zeros.
    //Since as of now, only "ones" has "x" and not "twos" - last 3 lines does nothing.

    //Explanation for step 2.
    //------------------------
    //Lets say an element(x) appears twice.
    //CURRENT SITUATION - "ones" has recorded "x" but not "twos".

    //Now due to the statement, "twos| = ones & x" - "twos" ends up getting bits of x.
    //But due to the statement, "ones ^ = x" - "ones" removes "x" from its binary representation.

    //Again, last 3 lines of code does nothing.
    //So ultimately, "twos" ends up getting bits of "x" and "ones" ends up losing bits of "x".

    //Explanation for step 3.
    //-------------------------
    //Lets say an element(x) appears for the third time.
    //CURRENT SITUATION - "ones" does not have bit representation of "x" but "twos" has.

    //Though "ones & x" does not yield nothing .. "twos" by itself has bit representation of "x". So after this         //statement, "two" has bit representation of "x".
    //Due to "ones^=x", after this step, "one" also ends up getting bit representation of "x".

    //Now last 3 lines of code removes common 1's of "ones" and "twos" - which is the bit representation of "x".
    //Thus both "ones" and "twos" ends up losing bit representation of "x".

    //1st example
    //------------
    //2, 2, 2, 4

    //After first iteration,
    //ones = 2, twos = 0
    //After second iteration,
    //ones = 0, twos = 2
    //After third iteration,
    //ones = 0, twos = 0
    //After fourth iteration,
    //ones = 4, twos = 0

    //2nd example
    //------------
    //4, 2, 2, 2

    //After first iteration,
    //ones = 4, twos = 0
    //After second iteration,
    //ones = 6, twos = 0
    //After third iteration,
    //ones = 4, twos = 2
    //After fourth iteration,
    //ones = 4, twos = 0
    //Explanation copied from : https://www.careercup.com/question?id=7902674
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        int non_threes = 0;
        
        for(int digIdx = 0; digIdx < nums.size(); digIdx++){
            twos |= (ones & nums[digIdx]);
            ones ^= nums[digIdx];
            
            non_threes = ~(ones & twos);
            ones &= non_threes;
            twos &= non_threes;
        }
        
        return ones;
    }
};

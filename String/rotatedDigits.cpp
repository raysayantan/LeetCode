/*
X is a good number if after rotating each digit individually by 180 degrees, we get a valid number that is different from X.  Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other (on this case they are rotated in a different direction, in other words 2 or 5 gets mirrored); 6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.

Now given a positive number N, how many numbers X from 1 to N are good?

Example:
Input: 10
Output: 4
Explanation: 
There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
Note:

N  will be in range [1, 10000].
*/
class Solution {
    bool isGood(int num){
        int rotated = 0;
        int decimal = 1;
        int org = num;
        while(num){
            int rem = num % 10;
            num = num / 10;
            int digit;
            if(rem == 1){
                digit = 1;
            } else if(rem == 2){
                digit = 5;
            } else if(rem == 5){
                digit = 2;
            } else if(rem == 6){
                digit = 9;
            } else if(rem == 8){
                digit = 8;
            } else if(rem == 9){
                digit = 6;
            } else if(rem == 0){
                digit = 0;
            } else 
                return false;
            
            rotated = digit*decimal + rotated;
            decimal *= 10;
        }
        
        return (org != rotated);
    }
public:
    int rotatedDigits(int N) { 
        int counter = 0;
        for(int n = 1; n <= N; n++){
            if(isGood(n)){
                counter++;
            }
        }
    
        return counter;
    }
};

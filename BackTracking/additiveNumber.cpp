/*
Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

 

Example 1:

Input: "112358"
Output: true
Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
             1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
Example 2:

Input: "199100199"
Output: true
Explanation: The additive sequence is: 1, 99, 100, 199. 
             1 + 99 = 100, 99 + 100 = 199
 

Constraints:

num consists only of digits '0'-'9'.
1 <= num.length <= 35
*/
class Solution {
    bool isValid(string a){
        if(a.length() > 1 && a[0] == '0')
            return false;
        return true;
    }
    
    bool checkAdditive(string a, string b, string c){
        if(!isValid(a) || !isValid(b) || !isValid(c))
            return false;
        
        long sum = stol(a) + stol(b);
        string sumStr = to_string(sum);
        
        if(sumStr == c)
            return true;
        
        if(sumStr.length() > c.length() || (sumStr != c.substr(0, sumStr.length())))
            return false;
        else
            return checkAdditive(b,sumStr, c.substr(sumStr.length()));
    }
public:
    bool isAdditiveNumber(string num) {
        int len = num.length();
        bool status = false;
        
        for(int i = 1; i <= len/2; i++){
            for(int j = 1; j <= len/2; j++){
                status |= checkAdditive(num.substr(0,i),
                                        num.substr(i,j),
                                        num.substr(i+j));
                
                if(status == true) {
                    return true;
                }
            }
        }
        return status;
    }
};

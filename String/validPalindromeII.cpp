/*
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/
class Solution {
public:
    bool validPalindrome(string s) {
        if(s.length() < 2){
            return true;
        }
        bool mismatch = false;
        bool status = true;
        int start = 0;
        int end = s.length() - 1;
        while(start <= end){
            if(s[start] != s[end]){
                mismatch = true;
                break;
            }
            
            start++;
            end--;
        }
        
        if(mismatch){
            int prevStart = start;
            int prevEnd = end;
            start++;
            
            while(start <= end){
                if(s[start] != s[end]){
                    status = false;
                    break;
                }
                start++;
                end--;
            }
            
            
            if(status){
                return status;
            }
            
            start = prevStart;
            end = prevEnd - 1;
            status = true;
            
            while(start <= end){
                if(s[start] != s[end]){
                    status = false;
                    break;
                }
                start++;
                end--;
            }
        } 
        
        return status;
    }
};

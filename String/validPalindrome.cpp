/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/
class Solution {
    bool isAlphaNumeric(char ch){
        return ((ch >= 'a' && ch <= 'z') || 
                (ch >= 'A' && ch <= 'Z') ||
                (ch >= '0' && ch <= '9'));
    }
public:
    bool isPalindrome(string s) {
        int len = s.length();
        int start = 0;
        int end = len - 1;
        
        while(start <= end){
            if(!isAlphaNumeric(s[start])){
                start++;
                continue;
            }
            if(!isAlphaNumeric(s[end])){
                end--;
                continue;
            }
            if(tolower(s[start]) != tolower(s[end]))
                return false;
            start++;
            end--;
        }
        return true;
    }
};

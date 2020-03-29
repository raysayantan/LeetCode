/*
Given a palindromic string palindrome, replace exactly one character by any lowercase English letter so that the string becomes the lexicographically smallest possible string that isn't a palindrome.

After doing so, return the final string.  If there is no way to do so, return the empty string.

 

Example 1:

Input: palindrome = "abccba"
Output: "aaccba"
Example 2:

Input: palindrome = "a"
Output: ""
 

Constraints:

1 <= palindrome.length <= 1000
palindrome consists of only lowercase English letters.
*/
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int len = palindrome.length();
        if(len <= 1) return "";
        bool isOdd = (len%2);
        bool found = false;
        int mid = len/2;
        
        for(int i = 0; i < len; i++){
            if(isOdd && i == mid){
                continue;
            }
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                found = true;
                break;
            }
        }
        if(!found){
            palindrome[len-1] = 'b';
        }
        
        return palindrome;
    }
};

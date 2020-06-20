/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Note:

The input string length won't exceed 1000.
*/
class Solution {
public:
    int countSubstrings(string s) {
        int counter = 0;
        if(s.length() < 1)
            return 0;
        
        for(int i = 0; i < s.length(); i++){
            //The idea is we will consider each character as middle of the palindrome
            //and expand both ways. For the palindrom of odd length we have a middle 
            //character and it will expand and for even length we have two same character
            //at the middle and then expand on both ways. If we sum it up we will get total count
            counter += (findPalindromeSubString(s, i, i) + 
                        findPalindromeSubString(s, i, i + 1));
        }
        
        return counter;
    }
    int findPalindromeSubString(string s, int start, int end){
        int counter = 0;
        while(start >= 0 && end < s.length()){
            if(s[start] == s[end]){
                counter++;
            } else {
                return counter;
            }
            start--;
            end++;
        }
        return counter;
    }
};

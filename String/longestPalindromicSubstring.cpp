/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:
Input: "cbbd"
Output: "bb"
*/
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() < 1)
            return "";
        int start = 0;
        int end = 0;
        for(int i = 0; i < s.length(); i++){
            //we can have palindrome in two scenarios
            //1 - middle character is not maching but 
            //rest of the chars of both side of middle 
            //character are matching i.e. abbcbba
            int l1 = findLongestRange(s, i, i);
            //2 - string exactly can be splitted in two part
            //and both part are equal from middle i.e. abbccbbaa
            int l2 = findLongestRange(s, i, i+1);
            int l = max(l1, l2);
            
            if(l > end - start + 1){
                start = i - (l - 1)/2;
                end = i + l/2;
            }
        }
        
        return s.substr(start, end - start + 1);
    }
    
    int findLongestRange(string s, int start, int end){
        while(start >= 0 && end < s.length()){
            if(s[start] != s[end])
                break;
            start--;
            end++;
        }
        return end - start - 1;
    }
};

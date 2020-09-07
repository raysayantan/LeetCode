/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"
Note:
The vowels does not include the letter "y".
*/
class Solution {
    bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ||
            (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
public:
    string reverseVowels(string s) {
        int l = s.length();
        int start = 0;
        int end = l - 1;
        
        while(start <= end){
            if(isVowel(s[start]) && isVowel(s[end])){
                char t = s[start];
                s[start] = s[end];
                s[end] = t;
                start++;
                end--;
            } else {
                if(!isVowel(s[start])){
                    start++;
                } 
                if(!isVowel(s[end])){
                    end--;
                }
            }
        }
        
        return s;
    }
};

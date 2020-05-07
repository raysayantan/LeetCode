/*
Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Follow up:

For C programmers, try to solve it in-place in O(1) extra space.
*/
class Solution {
public:
    string reverseWords(string s) {
        bool need = false;
        bool first = true;
        string res = "";
        string temp = "";
        int len = s.length();
        for(int i = len - 1; i >= 0; i--){
            if(s[i] != ' '){
                need = true;
                temp = s[i] + temp;
            } else {
                if(need){
                    need = false;
                    if(!first){
                        res += " ";
                    } else {
                        first = false;
                    }
                    res += temp;
                    temp.clear();
                }
            }
        }
        
        if(temp.length() >= 1){
            if(first)
                res += temp;
            else
                res += (" " + temp);
        }
        
        return res;
    }
};

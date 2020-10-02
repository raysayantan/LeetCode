/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
Example 4:

Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"
*/
class Solution {
    public String decodeString(String s) {
        Stack<String> st;
        int len = s.length();
        string res = "";
        int idx = len - 1;
        while(idx >= 0){
            if(s[idx] == '['){
                //pop the stack till we get closing ']'
                string str = "";
                while(!st.empty() && st.top() != "]"){
                    str += st.top();
                    st.pop();
                }
                st.pop();
                int freq = 0;
                string number = "";
                idx--;
                while(idx >= 0 && s[idx] >= '0' && s[idx] <= '9'){
                    number = s[idx] + number;
                    idx--;
                }
                
                if(number != ""){
                    freq = stoi(number);
                }
                string word = "";
                for(int count = 0; count < freq; count++){
                    word += str;
                }
                st.push(word);
            } else {
                st.push(string(1,s[idx]));
                idx--;
            }
        }
        
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        
        return res;
    }
}

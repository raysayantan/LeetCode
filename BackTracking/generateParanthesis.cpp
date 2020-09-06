/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
class Solution {
    void validparanthesis(vector<string> &result, string s, int open, int close, int n){
        if(s.length() == n * 2){
            result.push_back(s);
            return;
        }
        
        if(open < n){
            validparanthesis(result, s + "(", open + 1, close, n);
        }
        
        if(close < open){
            validparanthesis(result, s + ")", open, close + 1, n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s = "";
        validparanthesis(result, s, 0, 0, n);
        return result;
    }
};

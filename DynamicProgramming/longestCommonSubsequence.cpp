/*
Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

 

If there is no common subsequence, return 0.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length <= 1000
1 <= text2.length <= 1000
The input strings consist of lowercase English characters only.
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.length();
        int l2 = text2.length();
        
        vector<vector<int>> counter(l1 + 1, vector<int>(l2 + 1, 0));
        if(l1 == 0 || l2 == 0) return 0;
        for(int i = 1; i <= l1; i++){
            for(int k = 1; k <= l2; k++ ){
                if(text1[i-1] == text2[k-1]){
                    counter[i][k] = counter[i-1][k-1] + 1;
                } else {
                    counter[i][k] = max(max(counter[i-1][k], counter[i-1][k-1]), counter[i][k-1]);
                }
            }
        }
        
        return counter[l1][l2];
    }
};

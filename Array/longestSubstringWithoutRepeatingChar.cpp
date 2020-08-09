/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //Track the occurance of the alphabet
        vector<int> alphabet(256, -1);
        int currLen = 0;
        int maxLen = INT_MIN;
        int start = 0;
        
        for(int idx = 0; idx < s.length(); idx++){
            int alphabetIdx = s[idx];
            if(alphabet[alphabetIdx] < start){
                currLen++;
                //update the index of the curr alphabet in the array
                alphabet[alphabetIdx] = idx;              
            } else {
                //check if curr len greater than max
                if(currLen > maxLen){
                    maxLen = currLen;
                }
                //update start to the next character of the index of 
                //the last occurance of the current character
                start = alphabet[alphabetIdx] + 1;
                //adjust currLen so that it started just after the 
                //last occurance of the curr char
                currLen = idx - alphabet[alphabetIdx];
                alphabet[alphabetIdx] = idx;
            }
        }
        
        if(currLen > maxLen)
            maxLen = currLen;
        
        return maxLen;
    }
};

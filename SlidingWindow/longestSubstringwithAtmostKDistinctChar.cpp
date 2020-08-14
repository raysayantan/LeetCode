/*
Given a string, find the length of the longest substring T that contains at most k distinct characters.

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: T is "ece" which its length is 3.
Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: T is "aa" which its length is 2.
*/
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int len = s.length();
        int start = 0;
        int end = 0;
        int maxLen = INT_MIN;
        int currLen = 0;
        int charFreq = 0;
        if(len == 0 || k == 0)
            return 0;
        unordered_map<char, int> tracker;
        
        for(int idx = 0; idx < len; idx++){
            if(tracker.find(s[idx]) != tracker.end() && tracker[s[idx]] != 0){
                tracker[s[idx]]++;
            } else {
                tracker[s[idx]] = 1;
                charFreq++;
                if(charFreq > k){
                    int i = start;
                    while(charFreq > k && i < idx){
                        if(tracker[s[i]] > 0){
                            tracker[s[i]]--;
                            if(tracker[s[i]] == 0){
                                charFreq--;
                            }
                        }
                        i++;
                    }
                    start = i;
                }
            }
            
            currLen = idx - start + 1;
            if(currLen > maxLen){
                maxLen = currLen;
            }
        }
        
        return maxLen;
    }
};

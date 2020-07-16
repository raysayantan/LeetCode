/*
You are given two strings s and t of the same length. You want to change s to t. Changing the i-th character of s to i-th character of t costs |s[i] - t[i]| that is, 
the absolute difference between the ASCII values of the characters. You are also given an integer maxCost.
Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of twith a cost less than or equal to maxCost.
If there is no substring from s that can be changed to its corresponding substring from t, return 0.
Example 1:
Input: s = "abcd", t = "bcdf", maxCost = 3
Output: 3
Explanation: "abc" of s can change to "bcd". That costs 3, so the maximum length is 3.
Example 2:
Input: s = "abcd", t = "cdef", maxCost = 3
Output: 1
Explanation: Each character in s costs 2 to change to charactor in t, so the maximum length is 1.
Example 3:
Input: s = "abcd", t = "acde", maxCost = 0
Output: 1
Explanation: You can't make any change, so the maximum length is 1.
Constraints:
1 <= s.length, t.length <= 10^5
0 <= maxCost <= 10^6
s and t only contain lower case English letters.
*/
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len_s = s.length();        
        int currCount = 0;
        int maxCount = 0;
        int start = 0;
        int end = 0;
        int cost = 0;
        //Idea is to have a window which starting at start and ending at end.
        //we will calculate the sum of the abs diff of values of the chars at
        //each index in s and t within this window. if the sum of diff exceeds
        //maxCost, we will keep on deducting from it the diff at index start and
        //increament start still it is less or equal maxCost. There will be 
        //counters currCounter and a maxCounter. currCounter will be increamented
        //when a new element added in the window. If currCounter > maxCounter 
        //we will reaasign it to maxCounter.
        while(end < len_s){
            cost += abs((s[end] - 'a') - (t[end] - 'a'));
            currCount++;
            if(cost > maxCost){
                while(start <= end && cost > maxCost){
                    cost -= abs((s[start] - 'a') - (t[start] - 'a'));
                    start++;
                    currCount--;
                }
            }
            if(start > end){
                end = start;
            } else{
                end++;
            }
                
            if(currCount > maxCount)
                maxCount = currCount;
        }
        
        return maxCount;
    }
};

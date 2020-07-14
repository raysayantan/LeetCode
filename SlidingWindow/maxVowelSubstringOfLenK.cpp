/*
Given a string s and an integer k. Return the maximum number of vowel letters in any substring of s with length k. Vowel letters in English are (a, e, i, o, u).

Example 1:
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:
Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:
Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
Example 4:
Input: s = "rhythms", k = 4
Output: 0
Explanation: We can see that s doesn't have any vowel letters.
Example 5:
Input: s = "tryhard", k = 4
Output: 1
 
Constraints:
1 <= s.length <= 10^5
s consists of lowercase English letters.
1 <= k <= s.length
*/
class Solution {
    bool isVowel(char c){
        //This function will identify a character is vowel or not, as we are having
        //only english lower case letters so checking with 'a', 'e', 'i', 'o' and 'u'
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
public:
    int maxVowels(string s, int k) {
        int l = s.length(); 
        int maxCount = INT_MIN;
        int currCnt = 0;
        //first counting the vowels in first window of size k
        for(int idx = 0; idx < k; idx++){
            if(isVowel(s[idx])){
                currCnt++;
            }
        }
        
        maxCount = currCnt;
        //next window will start from 1 and end at (start + k -1)
        int start = 1;
        int end = start + k - 1;
        while(end < l){
            //we have window starts from start and ending at end, we have pre computed the 
            //first window from 0 to k. every time we move to next window by increamenting start
            //and end by one position. So, if s[start] is a vowel will decrement the vowel count
            //and if s[end] is a vowel will increament the count. Then assign the max of MaxCount 
            //and currCnt to the maxCount.
            if(isVowel(s[start - 1])){
                currCnt--;
            }
            if(isVowel(s[end])){
                currCnt++;
            }         
            
            if(currCnt > maxCount)
                maxCount = currCnt;
            start++;
            end++;
        }
        
        return maxCount;
    }
};

/*
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation 
of each word in words exactly once and without any intervening characters.
Example 1:
Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
Example 2:
Input:
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
Output: []
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int slen = s.length();
        //total number of words
        int len = words.size();
        //if either of the length is 0 return from here
        if(slen == 0 || len == 0)
            return result;
        
        int wordLen = words[0].length();
        if(slen < wordLen*len)
            return result;
        
        //this will keep track of the words and its count, 
        //we will use it while traversing the string
        unordered_map<string, int> counter;
        
        //calculate the freq of each word and keep it in the map
        for(int i = 0; i < len; i++){
            counter[words[i]]++;
        }        
        //counter keep track the total finds
        int cnt;              
        for(int i = 0; i < slen - wordLen*len + 1; i++){
            if(counter[s.substr(i, wordLen)] > 0){
                //temporarily copy the counter to loop through the string
                unordered_map<string, int> temp = counter;
                cnt = 0;
                int currPos = i;
                while(temp[s.substr(currPos, wordLen)] > 0 && cnt < len){
                    temp[s.substr(currPos, wordLen)]--;
                    cnt++;
                    currPos += wordLen;
                }
                
                if(cnt == len){
                    result.push_back(i);
                }
            }
        }
        return result;
    }
};

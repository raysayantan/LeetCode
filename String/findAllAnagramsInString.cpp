/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slen = s.length();
        int plen = p.length();
        vector<int> result;
        
        if(slen == 0 || slen < plen){
            result;
        }
        
        int start = 0;
        int end = plen - 1;
        unordered_map<char, int> countTracker;
        
        //fill the map with char count in the pattern
        for(int idx = 0; idx < plen; idx++){
            countTracker[p[idx]]++;
        }
        
        //get a temporary tracker to track a substring o len plen
        unordered_map<char, int> temp = countTracker;
        int counter = 0;
        int newStart = start + 1;
        bool found = false;
        while(start <= slen - plen){
            if(!found){
                for(int i = start; i <= end; i++){
                    //there will be two scenario - either the char will
                    //appear in the pattern or not. If it appears then we
                    //will decrement the tracker matching key value if it is
                    //greater than 0 and if all char in this substring match with 
                    //appears in pattern then we awill have a anagram and make an
                    //entry to result and move to the next substring starting at
                    //start + 1 location. Else we don't have match so need to
                    //adjust the next search start just after the non matching
                    //character.
                    if(temp.find(s[i]) != temp.end()){
                        //we have matching
                        if(temp[s[i]] > 0){
                            temp[s[i]]--;
                            counter++;
                        } else {
                           newStart = start + 1; 
                        }
                    } else {
                        //do don't have match
                        newStart = i + 1;
                        break;
                    }
                }
            } else {
                if(temp.find(s[end]) != temp.end()){
                    if(temp[s[end]] > 0){
                        temp[s[end]]--;
                        counter++;
                    } else {
                        newStart = start + 1;
                    }
                } else {
                    newStart = end + 1;
                    counter = 0;
                }
            }
            
            if(counter == plen ){
                //anagram found
                result.push_back(start);
                //temp = countTracker;
                temp[s[start]]++;
                counter--;
                start++;
                end++;
                found = true;
            } else {
                //not found
                temp.clear();
                temp = countTracker;
                start = newStart;
                counter = 0;
                end = start + plen - 1;
                found = false;
            }
        }
        
        return result;
    }
};

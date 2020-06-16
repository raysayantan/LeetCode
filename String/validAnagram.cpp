/*
Given two strings s and t , write a function to determine if t is an anagram of s.
Example 1:
Input: s = "anagram", t = "nagaram"
Output: true
Example 2
Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.
Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> counter(26,0);
        int len_s = s.length();
        int len_t = t.length();
        
        if(len_s != len_t) return false;
        
        //While we are encountering a char in s we are incrementing the character counter
        // and when we are getting acharacter in t we are decrementing that counter
        for(int idx = 0; idx < len_s; idx++){
            counter[s[idx] - 'a']++;
            counter[t[idx] - 'a']--;
        }
        
        //if both the string have same character with same number of occurances then at the end 
        //all entries in the counter vector will be zero else we should return false
        for(int i = 0; i < 26; i++){
            if(counter[i] > 0) return false;
        }
        return true;
    }
};

//For unicode we can use map as shown in the following solution
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> counter;
        int len_s = s.length();
        int len_t = t.length();
        
        if(len_s != len_t) return false;
        
        //While we are encountering a char in s we are incrementing the character counter
        // and when we are getting acharacter in t we are decrementing that counter
        for(int idx = 0; idx < len_s; idx++){
            if(counter.find(s[idx]) == counter.end()){
                counter.insert({s[idx], 1});
            } else {
                counter[s[idx]]++;
            }
            
            if(counter.find(t[idx]) == counter.end()){
                counter.insert({t[idx], -1});
            } else {
                counter[t[idx]]--;
            }
        }
        
        //if both the string have same character with same number of occurances then at the end 
        //all entries in the counter vector will be zero else we should return false
        for(auto it = counter.begin(); it != counter.end(); it++){
            if(it->second > 0) return false;
        }
        return true;
    }
};

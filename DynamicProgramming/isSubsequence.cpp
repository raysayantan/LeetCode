/*
Given a string s and a string t, check if s is subsequence of t. A subsequence of a string is a new string which is formed from the original string by deleting some 
(can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, 
how would you change your code?

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 10^4
Both strings consists only of lowercase characters.
*/
/*************************Using Binary Serach and HashMap*************************************/
class Solution {
    int binarySearch(vector<int> v, int pivot){
        int start = 0;
        int end = v.size() - 1;
        
        while(start <= end){
            int mid = (start + end)/2;
            if(mid > start && v[mid] > pivot && v[mid - 1] <= pivot){
                return v[mid];
            }
            if(mid == start && v[mid] > pivot){
                return v[mid];
            }
            
            if(mid < end && v[mid] <= pivot && v[mid + 1] > pivot){
                return v[mid + 1];
            }
            
            if(v[mid] > pivot){
                end = mid - 1;
            } else{
                start = mid + 1;
            }
        }
        
        return -1;
    }
public:
    bool isSubsequence(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        if(slen > tlen){
            return false;
        }
        
        if(slen == 0){
            return true;
        }
        
        unordered_map<char, vector<int>>indexer;
        for(int idx = 0; idx < tlen; idx++){
            indexer[t[idx]].push_back(idx);
        }
        
        int pivot = -1;
        for(int idx = 0; idx < slen; idx++){
            if(indexer.find(s[idx]) == indexer.end()){
                return false;
            }
            
            auto v = indexer[s[idx]];
            int index = binarySearch(v, pivot);
            if(index == -1){
                return false;
            }
            pivot = index;            
        }
        
        return true;
    }
};

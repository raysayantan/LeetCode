/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/
class Solution {
public:
    string minWindow(string s, string t) {
        int len_t = t.length();
        int len_s = s.length();
        string res = "";
        //when strings are empty;
        if(len_s == 0 || len_t == 0) return res;
        if(len_s == 1 && s == t) return s;
        
        map<char, int> tracker;
        map<char, int> counter;
        //Tracker will track that char present in pattern and 
        //counter will count the character in pattern
        for(int i = 0; i < len_t; i++){
            tracker.insert({t[i],0});
            if(counter.find(t[i]) == counter.end()){
                counter.insert({t[i], 1});
            } else {
                counter[t[i]] += 1;
            }
        }
        //first is start of the window and second is the end
        int first = 0;
        int second = 0;
        int count = 0;
        int windowStart = -1;
        int windowLen = INT_MAX;
        bool flag1 = true;
        bool flag2 = false;
        while(second < len_s){
            if(tracker.find(s[first]) != tracker.end()){
                if(flag1){
                    flag1 = false;
                    tracker[s[first]] += 1;
                    if(tracker[s[first]] <= counter[s[first]]){
                        count++;
                    }
                }
            }
            if(tracker.find(s[second]) != tracker.end()){
                if(flag2){
                    flag2 = false;
                    tracker[s[second]] += 1;
                    if(tracker[s[second]] <= counter[s[second]]){
                        count++;
                    }
                }
            }
            //We have all the char in pattern encountered
            if(count == len_t){
                if(second - first + 1 < windowLen){
                    windowStart = first;
                    windowLen = second - first + 1;
                }
                
                //to move the start of the windows need to discard it from tracker and 
                //decrement the count if this is a patter character
                if(tracker.find(s[first]) != tracker.end()){
                    tracker[s[first]] -= 1;
                    if(tracker[s[first]] < counter[s[first]]){
                        count--;
                    }
                }
                first++;
                flag1 = false;
            } else {
                second++;
                flag2 = true;
            }
        }
        
        if(windowStart != -1){
            res = s.substr(windowStart, windowLen);
        }
        return res;
    }
};

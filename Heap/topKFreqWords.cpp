/*
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.
*/
class Solution {
    class comparator {
        public:
        bool operator()(pair<string, int> p1, pair<string, int> p2){
            int second1 = p1.second;
            int second2 = p2.second;
            if(second1 == second2){
                string first1 = p1.first;
                string first2 = p2.first;
                return first1 > first2;
            } else {
                return second1 < second2;
            }
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordFreq;
        for(int idx =0; idx < words.size(); idx++){
            wordFreq[words[idx]]++;
        }
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, comparator> pq;
        for(auto it = wordFreq.begin(); it != wordFreq.end(); it++){
            pq.push({it->first, it->second});
        }
        
        vector<string> res(k, "");
        for(int idx = 0; idx < k; idx++){
            res[idx] = pq.top().first;
            pq.pop();
        }
        
        return res;
    }
};

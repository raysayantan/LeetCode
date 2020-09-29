/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1
*/
class Solution {
    class comparator{
      public:
        bool operator()(vector<int> v1, vector<int> v2){
            return v1[1] > v2[1];
        }
    };
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int rooms = 0;
        sort(intervals.begin(), intervals.end());
        priority_queue<vector<int>, vector<vector<int>>, comparator> pq;
        
        for(int idx = 0; idx < intervals.size(); idx++){
            if(!pq.empty() && (pq.top())[1] <= intervals[idx][0]){
                pq.pop();
                pq.push(intervals[idx]);
                continue;
            }
            
            pq.push(intervals[idx]);
            rooms++;
        }
        
        return rooms;
    }
};

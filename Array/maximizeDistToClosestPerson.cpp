/*
You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 
represents that the ith seat is empty (0-indexed). There is at least one empty seat, and at least one person sitting.
Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to the closest person.
Example 1:
Input: seats = [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
Example 2:

Input: seats = [1,0,0,0]
Output: 3
Explanation: 
If Alex sits in the last seat (i.e. seats[3]), the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.
Example 3:

Input: seats = [0,1]
Output: 1
 

Constraints:

2 <= seats.length <= 2 * 104
seats[i] is 0 or 1.
At least one seat is empty.
At least one seat is occupied.
*/
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int len = seats.size();
        vector<int> dist(len, INT_MAX);
        vector<int> right(len, INT_MAX);
        
        for(int idx = 0; idx < len; idx++){
            if(seats[idx] == 0){
                if(idx == 0){
                    dist[idx] = 1;
                } else {
                    dist[idx] = (dist[idx - 1] == INT_MAX) ? 1 : dist[idx - 1] + 1;
                }
            }
        }
        
        
        for(int idx = len - 1; idx >= 0; idx--){
            if(seats[idx] == 0){
                if(idx == len - 1){
                    right[idx] = 1;
                } else {
                    right[idx] = (right[idx + 1] == INT_MAX) ? 1 : right[idx + 1] + 1;
                }
            }
        }
        
        dist[0] = max(dist[0], right[0]);
        right[len - 1] = max(dist[len - 1], right[len - 1]);
        
        int maxDist = 1;
        for(int idx = 0; idx < len; idx++){
            if(dist[idx] != INT_MAX && right[idx] != INT_MAX){
                maxDist = max(maxDist, min(dist[idx], right[idx]));
            }
        }
        
        return maxDist;
    }
};

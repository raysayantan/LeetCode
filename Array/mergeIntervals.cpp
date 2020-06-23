/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        //sort the interval on the start value of the range
        sort(intervals.begin(), intervals.end(), 
             [] (const std::vector<int> &a, const std::vector<int> &b)
          {
              return a[0] < b[0];
          });
        int l = intervals.size();
        if(l <= 1)
            return intervals;
        int start = intervals[0][0];
        int end = intervals[0][1];
        int counter = 0;
        for(int i = 1; i < l; i++){
            if(intervals[i][0] <= end){
                if(intervals[i][1] > end){
                    end = intervals[i][1];
                }
            } else {
                //put the start and end pair to the result and assign the ith value 
                result.push_back({start,end});
                counter++;
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        //now we need to check, is the last value entered into the result?
        if(result.size() == 0 ||(result[counter-1][0] != start && result[counter - 1][1] != end)){
            result.push_back({start, end});
        }
        return result;
    }
};

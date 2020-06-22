/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.
Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int v1 = newInterval[0];
        int v2 = newInterval[1];
        int l = intervals.size();
        if(l == 0){
            result.push_back(newInterval);
            return result;
        }
        
        int start = 0;
        int end = l - 1;
        int startRange = 0;
        int endRange = l - 1;
        
        //if the new range end value is lesser than intervals's first value at index 0
        if(v2 <= intervals[0][0]){
            endRange = 0;
        }
        
        //if the new range start value is greater than the intervals's last value at index l-1
        if(v1 >= intervals[l-1][1]){
            startRange = l - 1;
        }
        
        //find the starting new Range
        while(start <= end){
            //mid in the intervals range
            int mid = (start + end)/2;
            //p1 is the value of the start range at mid and the p2 is the end one
            int p1 = intervals[mid][0];
            int p2 = intervals[mid][1];
            //if v1 is in between p1 and p2 or v1 is bewteen end range of the prev and start range of the next
            // or mid is at 0 and v1 is less that p1 we have the startRange
            if((v1 >= p1 && v1 <= p2) || (v1 < p1 && (mid - 1 >= 0 && v1 > intervals[mid-1][1]))
              || (mid == 0 && v1 < p1) ){
                startRange = mid;
                break;
            }
            
            if(v1 < p1){
                end = mid - 1;
            } else if(v1 > p2){
                start = mid + 1;
            }
        }
        
        start = 0;
        end = l - 1;
        //now find the end range
        while(start <= end){
            //mid in the intervals range
            int mid = (start + end)/2;
            //p1 is the value of the start range at mid and the p2 is the end one
            int p1 = intervals[mid][0];
            int p2 = intervals[mid][1];
            //if v2 is in between p1 and p2 or it is in between two range or it is greated thatn the last index range
            //we have the endRange
            if((v2 >= p1 && v2 <= p2) || (v2 > p2 && (mid+1 <= l - 1 && v2 < intervals[mid+1][0])) || 
               ((mid == l - 1) && v2 > p2)){
                endRange = mid;
                break;
            }
            
            if(v2 < p1){
                end = mid - 1;
            } else if(v2 > p2){
                start = mid + 1;
            }
        }
        for(int i = 0; i < startRange; i++){
            result.push_back(intervals[i]);
        }
        vector<int> newRange;
        //when we have start and end range same
        if(startRange == endRange){
            if(v1 >= intervals[startRange][0] && v1 <= intervals[startRange][1]){
                newRange.push_back(intervals[startRange][0]);
                if(v2 > intervals[startRange][1]){
                    newRange.push_back(v2);
                } else {
                    newRange.push_back(intervals[startRange][1]);
                }
                result.push_back(newRange);
            } else if(v1 < intervals[startRange][0]){
                newRange.push_back(v1);
                if(v2 >= intervals[startRange][0]){
                    if(v2 <= intervals[startRange][1]){
                        newRange.push_back(intervals[startRange][1]);
                    } else if(v2 > intervals[startRange][1]){
                        newRange.push_back(v2);
                    }
                    result.push_back(newRange);
                } else {
                    newRange.push_back(v2);
                    result.push_back(newRange);
                    result.push_back(intervals[startRange]);
                }
            } else if(v1 > intervals[startRange][1]){
                result.push_back(intervals[startRange]);
                result.push_back(newInterval);
            }
        } else {            
            if(v1 < intervals[startRange][0]){
                newRange.push_back(v1);
            } else {
                newRange.push_back(intervals[startRange][0]);
            }
            if(v2 > intervals[endRange][1]){
                newRange.push_back(v2);
            } else {
                newRange.push_back(intervals[endRange][1]);
            }
            result.push_back(newRange);
        }
        for(int i = endRange + 1; i < l; i++){
            result.push_back(intervals[i]);
        }
    
        return result;
    }
};

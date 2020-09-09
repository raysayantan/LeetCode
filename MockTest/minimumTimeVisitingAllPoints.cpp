/*
On a plane there are n points with integer coordinates points[i] = [xi, yi]. Your task is to find the minimum time in seconds to visit all points.

You can move according to the next rules:

In one second always you can either move vertically, horizontally by one unit or diagonally (it means to move one unit vertically and one unit horizontally in one second).
You have to visit the points in the same order as they appear in the array.
Input: points = [[1,1],[3,4],[-1,0]]
Output: 7
Explanation: One optimal path is [1,1] -> [2,2] -> [3,3] -> [3,4] -> [2,3] -> [1,2] -> [0,1] -> [-1,0]   
Time from [1,1] to [3,4] = 3 seconds 
Time from [3,4] to [-1,0] = 4 seconds
Total time = 7 seconds
Example 2:

Input: points = [[3,2],[-2,2]]
Output: 5
 

Constraints:

points.length == n
1 <= n <= 100
points[i].length == 2
-1000 <= points[i][0], points[i][1] <= 1000
*/
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int counter = 0;
        int l = points.size();
        if(l == 0){
            return counter;
        }
        
        vector<int> curr = points[0];
        vector<int> des;
        for(int idx = 1; idx < l; idx++){
            des = points[idx];
            bool xdir = (curr[0] <= des[0]) ? true : false;
            bool ydir = (curr[1] <= des[1]) ? true : false;
            //cout<<"curr "<<curr[0]<<":"<<curr[1]<<" and des "<<des[0]<<":"<<des[1]<<endl;
            //cout<<counter<<endl;
            while(curr[0] != des[0] || curr[1] != des[1]){
                if(curr[0] == des[0]){
                    //move vertical
                    while(curr[1] != des[1]){
                        curr[1] = (ydir) ? curr[1] + 1 : curr[1] - 1;
                        counter++;
                    }
                } else if(curr[1] == des[1]){
                //move horizontal
                    while(curr[0] != des[0]){
                        curr[0] = (xdir) ? curr[0] + 1 : curr[0] - 1;
                        counter++;
                    }
                } else {
                    //diagonal
                    while(curr[0] != des[0] && curr[1] != des[1]){
                        //cout<<"diagonal"<<endl;
                        curr[0] = (xdir) ? curr[0] + 1 : curr[0] - 1;
                        curr[1] = (ydir) ? curr[1] + 1 : curr[1] - 1;
                        //cout<<"curr "<<curr[0]<<":"<<curr[1]<<" and des "<<des[0]<<":"<<des[1]<<endl;
                        counter++;
                    }
                }
            }
        }
        
        return counter;
    }
};

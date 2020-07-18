/*
We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
(Here, the distance between two points on a plane is the Euclidean distance.)
You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)
 

Note:

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000
*/
class Solution {
public:
    class comparator{
        public:
        bool operator()(pair<double, int> p1, pair<double, int> p2){
            return p1.first > p2.first;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        //Priority queue to keep the points based on the distance from the point (0,0) - min heap
        priority_queue<pair<double, int>, vector<pair<double, int>>, comparator> pq;
        vector<vector<int>> res;
        //records keeping in priority queue;
        for(int idx = 0; idx < points.size(); idx++){
            int p1 = points[idx][0];
            int p2 = points[idx][1];
            double dist = sqrt(p1*p1 + p2*p2);
            pq.push(make_pair(dist, idx));
        }
        
        //take first K points from the priority queue - min heap
        while(!pq.empty()){
            pair p = pq.top();
            pq.pop();
            int index = p.second;
            res.push_back({points[index][0], points[index][1]});
            K--;
            if(K <= 0)
                break;
        }
        
        return res;
    }
};

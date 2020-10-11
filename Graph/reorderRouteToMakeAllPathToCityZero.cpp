/*
There are n cities numbered from 0 to n-1 and n-1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [a, b] represents a road from city a to b.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach the city 0 after reorder.

 

Example 1:



Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).
Example 2:



Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).
Example 3:

Input: n = 3, connections = [[1,0],[2,0]]
Output: 0
 

Constraints:

2 <= n <= 5 * 10^4
connections.length == n-1
connections[i].length == 2
0 <= connections[i][0], connections[i][1] <= n-1
connections[i][0] != connections[i][1]
*/
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> in;
        unordered_map<int, vector<int>> out;
        queue<int> q;
        vector<int> visit(n, 0);
        
        //create map for inwards edge and outwards edge
        for(int idx = 0; idx < connections.size(); idx++){
            int first = connections[idx][0];
            int second = connections[idx][1];
            in[second].push_back(first);
            out[first].push_back(second);
        }
        
        int count = 0;
        //traverse through the in and out map from '0' till end. Every time we have
        //int to zero will add to the visit, every time we have out from 0 will add to
        //visit and increment the counter. now next level we iterate through the nodes
        //adjacent to 0 and then next the adjacent nodes of these nodes which were 
        //adjacent to 0 and so on
        q.push(0);
        while(!q.empty()){
            int front = q.front();
            q.pop();
            visit[front] = 1;
            
            for(int idx = 0; idx < in[front].size(); idx++){
                int node = in[front][idx];
                if(visit[node] == 0){
                    q.push(node);
                }
            }
            
            for(int idx = 0; idx < out[front].size(); idx++){
                int node = out[front][idx];
                if(visit[node] == 0){
                    q.push(node);
                    count++;
                }
            }
        }
        
        return count;
    }
};

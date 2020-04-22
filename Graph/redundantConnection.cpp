/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given undirected graph will be like this:
  1
 / \
2 - 3
Example 2:
Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
Explanation: The given undirected graph will be like this:
5 - 1 - 2
    |   |
    4 - 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.

Update (2017-09-26):
We have overhauled the problem description + test cases and specified clearly the graph is an undirected graph. For the directed graph follow up please see Redundant Connection II). We apologize for any inconvenience caused.
*/
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int numOfEdges = edges.size();
        vector<int> degree(numOfEdges+1);
        queue<int> q;
        vector<int> m(numOfEdges+1);
        vector<vector<int>> adj(numOfEdges+1);
        /*for(int i = 1; i <= numOfEdges; i++){
            m.insert({i, false});
        }*/
        for(int i = 0; i < numOfEdges; i++){
            int v1 = edges[i][0];
            int v2 = edges[i][1];
            degree[v1]++;
            degree[v2]++;
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }
        for(int i = 1; i <= numOfEdges; i++){
            if(degree[i] == 1){
                q.push(i);
            }
        }
        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i < len; i++){
                int top = q.front();
                q.pop();
                m[top] = 1;
                for(int i = 0; i < adj[top].size(); i++){
                    if(degree[adj[top][i]] > 0){
                        degree[adj[top][i]]--;
                        if(degree[adj[top][i]] == 1){
                            q.push(adj[top][i]);
                        }
                    }
                }
            }
        }
        vector<int> res;
        for(int i = numOfEdges - 1; i >= 0; i--){
            if(m[edges[i][0]] != 1 && m[edges[i][1]] != 1){
                res.push_back(edges[i][0]);
                res.push_back(edges[i][1]);
                break;
            }
        }
        
        return res;
    }
};

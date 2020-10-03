/*
Given a directed acyclic graph of N nodes. Find all possible paths from node 0 to node N-1, and return them in any order.
The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists. 

Example 1:

Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Example 2:


Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
Example 3:

Input: graph = [[1],[]]
Output: [[0,1]]
Example 4:

Input: graph = [[1,2,3],[2],[3],[]]
Output: [[0,1,2,3],[0,2,3],[0,3]]
Example 5:

Input: graph = [[1,3],[2],[3],[]]
Output: [[0,1,2,3],[0,3]]
 

Constraints:

The number of nodes in the graph will be in the range [2, 15].
You can print different paths in any order, but you should keep the order of nodes inside one path.
*/
class Solution {
    void dfs(unordered_map<int, set<int>> adj, vector<vector<int>> &paths, vector<bool> &visit, int s, int e, vector<int> path){
        if(s == e){
            path.push_back(s);
            paths.push_back(path);
            return;
        }
        
        if(visit[s] == false){
            visit[s] = true;
            path.push_back(s);
            auto v = adj[s];
            for(auto it = v.begin(); it != v.end(); it++){
                dfs(adj, paths, visit, *it, e, path);
            }
        }
        visit[s] = false;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        unordered_map<int, set<int>> adj;
        int len = graph.size();
        for(int i = 0; i < len; i++){
            for(int k = 0; k < graph[i].size(); k++){
                int u = i;
                int v = graph[i][k];
                adj[u].insert(v);
            }
        }
        vector<vector<int>> paths;
        vector<bool> visit(len, false);
        dfs(adj, paths, visit, 0, len -1,{});
        return paths;
    }
};

/*
In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with N nodes (with distinct values 1, 2, ..., N), with one additional directed edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] that represents a directed edge connecting nodes u and v, where u is a parent of child v.

Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given directed graph will be like this:
  1
 / \
v   v
2-->3
Example 2:
Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
Output: [4,1]
Explanation: The given directed graph will be like this:
5 <- 1 -> 2
     ^    |
     |    v
     4 <- 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.
*/
class Solution {
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &parent,
             vector<bool> &inLoop, map<int, bool> &cycle, int i, bool &c){
        
        if(c == false){
            if(visited[i] == false){
                visited[i] = true;
                inLoop[i] = true;
                for(int k = 0; k < adj[i].size(); k++){
                    parent[adj[i][k]] = i;
                    dfs(adj, visited, parent, inLoop, cycle, adj[i][k], c);
                }
            } else {
                if(inLoop[i] == true){
                    c = true;
                    cycle[i] = true;;
                    int node = parent[i];
                    while(node != i){
                        cycle[node] = true;
                        node = parent[node];
                    }
                    return;
                }
            }
            inLoop[i] = false;
        }
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size()+1);
        vector<int> inDegree(edges.size()+1);
        int root = -1;
        int nodeToFind = -1;
        bool found = false;
        vector<int> res;
        
        //create Adj list
        for(int i = 0; i < edges.size(); i++){
            int v1 = edges[i][0];
            int v2 = edges[i][1];
            
            adj[v1].push_back(v2);
            inDegree[v2]++;
        }
        
        bool isCycle = false;
        vector<bool> visited(edges.size() + 1);
        map<int, bool> cycle;
        vector<bool> inLoop(edges.size());
        vector<int> parent(edges.size()+1);
        for(int i = 0; i <= edges.size(); i++) {
            cycle.insert({i, false});
            parent[i] = -1;
        }
        for(int i = 1; i <= edges.size(); i++){
            if(visited[i] == false){
                dfs(adj, visited, parent, inLoop, cycle, i, isCycle);
            }
        }
        
        for(int i = 1; i <= edges.size(); i++){
            if(inDegree[i] == 0){
                found = true;
                root = i;
            }
            
            if(inDegree[i] == 2){
                nodeToFind = i;
            }
            
            if(found && nodeToFind != -1) break;
        }
        if(found){
            for(int i = edges.size() - 1; i >= 0; i--){
                if(!isCycle){
                    if(edges[i][1] == nodeToFind){
                        res.push_back(edges[i][0]);
                        res.push_back(edges[i][1]);
                        break;
                    }
                } else {
                    if(edges[i][1] == nodeToFind && cycle[edges[i][0]] == true){
                        res.push_back(edges[i][0]);
                        res.push_back(edges[i][1]);
                        break;
                    }
                }
            }
        } else {
            //This is the scenario when the extra edge is connecting to root node
            if(isCycle){
                for(int i = edges.size() - 1; i >= 0; i--){
                    if(cycle[edges[i][0]] == true && cycle[edges[i][1]] == true){
                        res.push_back(edges[i][0]);
                        res.push_back(edges[i][1]);
                        break;
                    }
                }
            }
        }
        
        return res;
    }
};

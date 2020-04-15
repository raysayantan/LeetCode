/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5
*/
/* This solution not passing few 4 test cases out of 46 and giving time limit exceed, trying for better solution*/
class Solution {
    bool isCycleUtil(unordered_map<int, set<int>> edges, vector<bool> &visited, vector<bool> &rs, int i){
        if(visited[i] == false){
            visited[i] = true;
            rs[i] = true;
            auto s = edges[i];
            for(auto it = s.begin(); it != s.end(); it++){
                if(rs[*it] == true) return true;
                if(visited[*it] == false && isCycleUtil(edges, visited, rs, *it)){
                    return true;
                }
            }   
        }
        rs[i] = false;
        return false;
    }
    
    bool isCycle(unordered_map<int, set<int>> &edges, int nodes){
        vector<bool> visited(nodes);
        vector<bool> rs(nodes);
        for(int i = 0; i < nodes; i++){
            if(isCycleUtil(edges, visited, rs, i)){
                return true;
                
            }
        }   
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, set<int>> edges(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            int v1 = prerequisites[i][0];
            int v2 = prerequisites[i][1];
            auto it = edges.find(v2);
            if(it == edges.end()){
                set<int> temp = {v1};
                edges.insert({v2,temp});
            } else {
                auto s = it->second;
                s.insert(v1);
                edges[v2] = s;
            }
        }
        
        if(isCycle(edges, numCourses)) {
            return false;
        }
        
        return true;
    }
};
/* Below solution is based on topological sort in graph and working for all uses cases*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<set<int>> adj(numCourses);
        vector<int> inDegree(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            int v1 = prerequisites[i][0];
            int v2 = prerequisites[i][1];
            adj[v2].insert(v1);
            inDegree[v1]++;
        }
        
        for(int i = 0; i < numCourses; i++){
            int j;
            for(j = 0; j < numCourses && inDegree[j] != 0; j++);
            
            if(j == numCourses) return false;
            
            inDegree[j] = -1;
            
            for(auto it = adj[j].begin(); it != adj[j].end(); it++){
                inDegree[*it]--;
            }
        }
        
        return true;
    }
};
/* topological sort with better runtime complexity */
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<set<int>> adj(numCourses);
        vector<int> inDegree(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            int v1 = prerequisites[i][0];
            int v2 = prerequisites[i][1];
            adj[v2].insert(v1);
            inDegree[v1]++;
        }
        
        queue<int> q;
        int count = 0;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();   
            count++;
            for(auto it = adj[top].begin(); it != adj[top].end(); it++){
                inDegree[*it]--;
                if(inDegree[*it] == 0){
                    q.push(*it);
                }
            }
        }
        
        if(count == numCourses) return true;
        return false;
    }
};

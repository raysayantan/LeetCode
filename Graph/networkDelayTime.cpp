/*
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

 

Example 1:



Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2
 

Note:

N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.
*/
class Solution {
    queue<int> q;
    void bfs(vector<vector<vector<int>>> &adj, vector<int> &cost, int k){
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(int i = 0; i < adj[top].size(); i++){
                int node = adj[top][i][0];
                if(cost[node] > cost[top] + adj[top][i][1]){
                    cost[node] = cost[top] + adj[top][i][1];
                    q.push(node);
                }
            }
        }
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        if(N == 1) return 0;
        vector<vector<vector<int>>> adj(N + 1);
        vector<int> cost(N + 1, INT_MAX);
        int totalCost = 0;
        
        for(int i = 0; i < times.size(); i++){
            int v1 = times[i][0];
            int v2 = times[i][1];
            int w = times[i][2];   
            adj[v1].push_back({v2,w});
        }
        q.push(K);
        cost[K] = 0;
        bfs(adj, cost, K);
        
        for(int i = 1; i <= N; i++){
            if(cost[i] == INT_MAX) return -1;
            if(cost[i] > totalCost) totalCost = cost[i];
        }
        
        return totalCost;
    }
};
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 using Priority Quehe Disktra Algorithm
 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 class Solution {
    class compareweight{
        public:
        bool operator()(vector<int> &v1, vector<int> &v2){
            return v1[1] > v2[1];
        }
    };
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        if(N == 1) return 0;
        vector<vector<vector<int>>> adj(N + 1);
        vector<int> cost(N + 1, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>,compareweight> pq;
        int totalCost = 0;
        
        for(int i = 0; i < times.size(); i++){
            int v1 = times[i][0];
            int v2 = times[i][1];
            int w = times[i][2];   
            adj[v1].push_back({v2,w});
        }
        pq.push({K,0});
        cost[K] = 0;
        while(!pq.empty()){
            vector<int> top = pq.top();
            pq.pop();
            int v = top[0];
            int w = top[1];
            for(int i = 0; i < adj[v].size(); i++){
                vector<int> node = adj[v][i];
                int v1 = node[0];
                int w1 = node[1];
                if(cost[v1] > w1 + w){
                    cost[v1] = w1 + w;
                    pq.push({v1, cost[v1]});
                }
            }
        }
        
        for(int i = 1; i <= N; i++){
            if(cost[i] == INT_MAX) return -1;
            if(cost[i] > totalCost) totalCost = cost[i];
        }
        
        return totalCost;
    }
};

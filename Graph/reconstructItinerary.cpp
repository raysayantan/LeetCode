/*
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.
*/
class Solution {
    void traverse(map<string, priority_queue<string,vector<string>,greater<string>>> &itinerary, vector<string> &st, string start){
        while(!(itinerary[start]).empty()){
            string front = (itinerary[start]).top();
            (itinerary[start]).pop();
            traverse(itinerary, st, front);
        }
        st.push_back(start);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, priority_queue<string, vector<string>,greater<string>>> itinerary;
        vector<string> result;
        for(int i = 0; i < tickets.size(); i++){
            string from = tickets[i][0];
            string to = tickets[i][1];
            if(itinerary.find(from) == itinerary.end()){
                priority_queue<string, vector<string>, greater<string>> q;
                q.push(to);
                itinerary.insert({from,q});
            } else {
                auto it = itinerary.find(from);
                auto s = it->second;
                s.push(to);
                itinerary[from] = s;
            }
        }
        traverse(itinerary, result, "JFK");
        reverse(result.begin(), result.end());
        return result;
    }
};

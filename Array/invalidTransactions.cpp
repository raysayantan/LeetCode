/*
A transaction is possibly invalid if:

the amount exceeds $1000, or;
if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.
Each transaction string transactions[i] consists of comma separated values representing the name, time (in minutes), amount, and city of the transaction.

Given a list of transactions, return a list of transactions that are possibly invalid.  You may return the answer in any order.

 

Example 1:

Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
Output: ["alice,20,800,mtv","alice,50,100,beijing"]
Explanation: The first transaction is invalid because the second transaction occurs within a difference of 60 minutes, have the same name and is in a different city. Similarly the second one is invalid too.
Example 2:

Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
Output: ["alice,50,1200,mtv"]
Example 3:

Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
Output: ["bob,50,1200,mtv"]
 

Constraints:

transactions.length <= 1000
Each transactions[i] takes the form "{name},{time},{amount},{city}"
Each {name} and {city} consist of lowercase English letters, and have lengths between 1 and 10.
Each {time} consist of digits, and represent an integer between 0 and 1000.
Each {amount} consist of digits, and represent an integer between 0 and 2000.
*/
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_map<string, vector<pair<pair<int, int>, string>>> m;
        int len = transactions.size();
        vector<string> res;
        set<int> list;
        for(int idx = 0; idx < len; idx++){
            string str = transactions[idx];
            stringstream ss(str);
            vector<string> v;
            while(ss.good()){
                string tok;
                getline(ss, tok, ',');
                v.push_back(tok);
            }
            
            string name = v[0];
            string city = v[3];
            int time = stoi(v[1]);
            int amt = stoi(v[2]);
            
            if(amt > 1000){
                list.insert(idx);
            } 
            
            auto v1 = m[name];
            for(int i = 0; i < v1.size(); i++){
                auto p1 = v1[i];
                string cityName = p1.second;
                int index = p1.first.first;
                int t = p1.first.second;
                if(city != cityName && abs(t - time) <= 60){
                    list.insert(idx);
                    list.insert(index);
                }
            }
            
            m[name].push_back({{idx, time}, city});
        }
        
        for(auto it = list.begin(); it != list.end(); it++){
            res.push_back(transactions[*it]);
        }
        
        return res;
    }
};

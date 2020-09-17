/*
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

Example:

Input: citations = [3,0,6,1,5]
Output: 3 
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had 
             received 3, 0, 6, 1, 5 citations respectively. 
             Since the researcher has 3 papers with at least 3 citations each and the remaining 
             two with no more than 3 citations each, her h-index is 3.
Note: If there are several possible values for h, the maximum one is taken as the h-index.
*/
/********************************* Solution using Sort **********************************************/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int hIndex = 0;
        map<int, int, greater<int>> order;
        for(int idx = 0; idx < len; idx++){
            if(order.find(citations[idx]) != order.end()){
                order[citations[idx]]++;
            } else {
                order[citations[idx]] = 1;
            }
        }
        int counter = 0;
        for(auto it = order.begin(); it != order.end(); it++){
            int first = it->first;
            int second = it->second;
            counter += second;
            //cout<<first<<":"<<second<<":"<<counter<<endl;
            if(first >= counter){
                hIndex = counter;
            } else {
                hIndex = max(first, hIndex);
                break;
            }
        }
        
        return hIndex;
    }
};

/********************************* Using Hash Map **************************************************/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int hIndex = 0;
        map<int, int, greater<int>> order;
        for(int idx = 0; idx < len; idx++){
            if(order.find(citations[idx]) != order.end()){
                order[citations[idx]]++;
            } else {
                order[citations[idx]] = 1;
            }
        }
        int counter = 0;
        for(auto it = order.begin(); it != order.end(); it++){
            int first = it->first;
            int second = it->second;
            counter += second;
            if(first >= counter){
                hIndex = counter;
            } else {
                hIndex = max(first, hIndex);
                break;
            }
        }
        
        return hIndex;
    }
};

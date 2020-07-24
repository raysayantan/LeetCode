/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property 
where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Input: [5,2,6,1]
Output: [2,1,1,0] 
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
*/
class Solution {
    void countSmallerUtility(vector<int>& res, vector<vector<int>>::iterator low, vector<vector<int>>::iterator high){
        //if less there are one or less element
        if(high - low <= 1)
            return;
        
        //we need to have more than one element here
        auto mid = low + (high - low)/2;
        countSmallerUtility(res, low, mid);
        countSmallerUtility(res, mid, high);
        
        //now compare the two part of the diveided array, how many (i, j)
        //pair so that element at i > element at j and i < j. Here j is moving from
        //m to high and i from low to m. So this loop complexity will be O(n), as J
        //never resets to m, it is keep on incrementing
        for(auto i = low, j = mid; i < mid; i++){            
            while(j < high && (*i)[0] > (*j)[0])
                j++;
            res[(*i)[1]] += j - mid;
        }
        
        inplace_merge(low, mid, high);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        vector<vector<int>> arr;
        for(int i = 0; i < nums.size(); i++){
            arr.push_back((vector<int>){nums[i], i});
        }
        countSmallerUtility(res, arr.begin(), arr.end());
        
        return res;
    }
};

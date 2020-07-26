/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Input: [5,2,6,1]
Output: [2,1,1,0] 
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
*/
/*
THIS CAN BE SOLVED USING MERGE SORT AS WELL, CHECK IN ARRAY RELATED PROBLEMS TO SOLVE THIS USING MERGE SORT
*/
class Solution {
    int binarySerach(vector<int> data, int target){
        int low = 0;
        int high = data.size() - 1;
        int mid;
        while(low <= high){
            mid = low + (high - low)/2;
            if(data[mid] == target){
                return mid +  1;
            }
            
            if(data[mid] > target){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return -1;
    }
    
    int query(vector<int> bit, int index){
        int res = 0;
        while(index > 0){
            res += bit[index];
            index -= index & (-index);
        }
        
        return res;
    }
    
    void update(vector<int> &bit, int idx, int val){
        while(idx < bit.size()){
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> data = nums;
        sort(data.begin(), data.end());
        vector<int> res(nums.size(), 0);
        vector<int> bit(nums.size() + 1, 0);
        
        //we will start from high to the left, so we have all data
        //traversed at right of index i when we are at index i. So
        //from the BIT we can get the result for index i and then update
        //BIT with corresponding value related to at index i
        for(int i = nums.size() - 1; i >= 0; i--){
            //cout<<"Seraching index "<<i<<" value "<<nums[i]<<" in sorted array"<<endl;
            int idx = binarySerach(data, nums[i]);
            //cout<<"Index in sorted array : "<<idx<<endl;
            
            //when we are at index i, we are actually corresponding to index i + 1
            //int Binary Index Tree. So to find the lower values till now we need to
            //move in the indices lower than value at i in the sorted array and sum it up, 
            //quering BIT from index i till 1
            res[i] = query(bit, idx - 1);
            //cout<<"Value calculated for index "<<i<<" is "<<res[i]<<endl;
            
            //now update the BIT with the value at index i. We will update all the 
            //locations in the BIT that includes index i by adding +1
            update(bit, idx, 1);
            //cout<<"Update done"<<endl;
        }
        
        return res;
    }
};

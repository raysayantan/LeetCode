/*
Given two sparse vectors, compute their dot product.

Implement class SparseVector:

SparseVector(nums) Initializes the object with the vector nums
dotProduct(vec) Compute the dot product between the instance of SparseVector and vec
A sparse vector is a vector that has mostly zero values, you should store the sparse vector efficiently and compute the dot product between two SparseVector.

Follow up: What if only one of the vectors is sparse?

 

Example 1:

Input: nums1 = [1,0,0,2,3], nums2 = [0,3,0,4,0]
Output: 8
Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 1*0 + 0*3 + 0*0 + 2*4 + 3*0 = 8
Example 2:

Input: nums1 = [0,1,0,0,0], nums2 = [0,0,0,0,2]
Output: 0
Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 0*0 + 1*0 + 0*0 + 0*0 + 0*2 = 0
Example 3:

Input: nums1 = [0,1,0,0,2,0,0], nums2 = [1,0,0,0,3,0,4]
Output: 6
 

Constraints:

n == nums1.length == nums2.length
1 <= n <= 10^5
0 <= nums1[i], nums2[i] <= 100
*/
class SparseVector {
    vector<vector<int>> vect;
public:
    
    SparseVector(vector<int> &nums) {
        for(int idx = 0; idx < nums.size(); idx++){
            if(nums[idx] != 0){
                vect.push_back({idx, nums[idx]});
            }
        }
    }
    
    vector<vector<int>> getVector(){
        return vect;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int product = 0;
        vector<vector<int>> v = vec.getVector();
        int idx1 = 0;
        int idx2 = 0;
        while(idx1 < vect.size() && idx2 < v.size()){
            int pos1 = vect[idx1][0];
            int pos2 = v[idx2][0];
            if(pos1 == pos2){
                product += vect[idx1][1] * v[idx2][1];
                idx1++;
                idx2++;
            } else {
                if(pos1 > pos2){
                    idx2++;
                } else {
                    idx1++;
                }
            }
        }
        
        return product;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);

//Solution with Map
class SparseVector {
public:
    unordered_map<int, int> mapper;
    SparseVector(vector<int> &nums) {
        for(int idx = 0; idx < nums.size(); idx++){
            if(nums[idx] != 0){
                mapper[idx] = nums[idx];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int product = 0;
        for(auto it = mapper.begin(); it != mapper.end(); it++){
            int key = it->first;
            if(vec.mapper.find(key) != vec.mapper.end()){
                product += vec.mapper[key] * mapper[key];
            }
        }
        
        return product;
    }
};



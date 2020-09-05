/*
Given three integer arrays arr1, arr2 and arr3 sorted in strictly increasing order, return a sorted array of only the integers that appeared in all three arrays.

 

Example 1:

Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
Output: [1,5]
Explanation: Only 1 and 5 appeared in the three arrays.
 

Constraints:

1 <= arr1.length, arr2.length, arr3.length <= 1000
1 <= arr1[i], arr2[i], arr3[i] <= 2000
*/
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> result;
        int l1 = arr1.size();
        int l2 = arr2.size();
        int l3 = arr3.size();
        
        if(l1 == 0 || l2 == 0 || l3 == 0){
            return result;
        }
        
        int idx1 = 0;
        int idx2 = 0;
        int idx3 = 0;
        
        while(idx1 < l1 && idx2 < l2 && idx3 < l3){
            if(arr1[idx1] == arr2[idx2] && arr2[idx2] == arr3[idx3]){
                result.push_back(arr1[idx1]);
                idx1++;
                idx2++;
                idx3++;
            } else {
                //increment those are smaller keeping the largest intact
                int largest = max(arr1[idx1], max(arr2[idx2], arr3[idx3]));
                if(arr1[idx1] < largest){
                    idx1++;
                }
                
                if(arr2[idx2] < largest){
                    idx2++;
                }
                
                if(arr3[idx3] < largest){
                    idx3++;
                }
            }
        }
        
        return result;
    }
};

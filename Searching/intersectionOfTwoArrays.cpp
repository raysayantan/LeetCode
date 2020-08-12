/*
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.
*/
vector<int> result;
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        if(len1 == 0 || len2 == 0)
            return result;
        
        unordered_map<int, bool> tracker;
        
        //put all the elements in the map from first array
        for(int idx = 0; idx < len1; idx++){
            tracker[nums1[idx]] = false;
        }
        
        //loop through the second array to check the element in map or not
        //if the element is present in the map, insert that in the resultSet
        for(int idx = 0; idx < len2; idx++){
            if(tracker.find(nums2[idx]) != tracker.end()
                                            && tracker[nums2[idx]] == false){
                result.push_back(nums2[idx]);
                tracker[nums2[idx]] = true;
            }
        }
        
        return result;

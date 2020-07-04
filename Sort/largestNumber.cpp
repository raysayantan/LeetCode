/*
Given a list of non negative integers, arrange them such that they form the largest number.
Example 1:
Input: [10,2]
Output: "210"
Example 2:
Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.
*/
class Solution {
    static bool sortElement(string num1, string num2){
        //sort in descending order
        string str1 = num1 + num2;
        string str2 = num2 + num1;
        return str1 > str2;
    }
public:
    string largestNumber(vector<int>& nums) {
        int l = nums.size();
        string result = "";
        vector<string> container;
        for(int i = 0; i < l; i++){
            container.push_back(to_string(nums[i]));
        }
        
        //sort the vector desc order lexiographically
        sort(container.begin(), container.end(), sortElement);
        //take every element and append to the previous as this is already
        //sorted in descending order
        for(int i = 0; i < l; i++){
            result += container[i];
        }
        
        //if the starting element is '0' then the result can be only "0"
        if(result.length() > 0 && result[0] == '0')
            return "0";
        return result;
    }
};

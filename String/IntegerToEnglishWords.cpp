/*
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

Example 1:

Input: 123
Output: "One Hundred Twenty Three"
Example 2:

Input: 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Example 4:

Input: 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
*/
class Solution {
    unordered_map<int, string> numberMap;
    void populateNumberMap(unordered_map<int, string>& numberMap){
        numberMap.insert({0, "Zero"});
        numberMap.insert({1, "One"});
        numberMap.insert({2, "Two"});
        numberMap.insert({3, "Three"});
        numberMap.insert({4, "Four"});
        numberMap.insert({5, "Five"});
        numberMap.insert({6, "Six"});
        numberMap.insert({7, "Seven"});
        numberMap.insert({8, "Eight"});
        numberMap.insert({9, "Nine"});
        numberMap.insert({10, "Ten"});
        numberMap.insert({11, "Eleven"});
        numberMap.insert({12, "Twelve"});
        numberMap.insert({13, "Thirteen"});
        numberMap.insert({14, "Fourteen"});
        numberMap.insert({15, "Fifteen"});
        numberMap.insert({16, "Sixteen"});
        numberMap.insert({17, "Seventeen"});
        numberMap.insert({18, "Eighteen"});
        numberMap.insert({19, "Nineteen"});
        numberMap.insert({20, "Twenty"});
        numberMap.insert({30, "Thirty"});
        numberMap.insert({40, "Forty"});
        numberMap.insert({50, "Fifty"});
        numberMap.insert({60, "Sixty"});
        numberMap.insert({70, "Seventy"});
        numberMap.insert({80, "Eighty"});
        numberMap.insert({90, "Ninety"});
    }
public:
    string numberToWords(int num) {
        vector<string> dim = {"Hundred", "Thousand", "Million", "Billion"};
        if(num == 0)
            return "Zero";
        
        string result = "";
        vector<string> resultVector(4,"");
        
        int counter = 0;
        populateNumberMap(numberMap);
        string seperator = "";
        while(num > 0){
            //we will take each time the 3 digit from right and perform the processing
            int rem = num%1000;
            num = num/1000;
            string intermediate = "";
            if(rem >= 10 && rem < 20){
                intermediate = numberMap[rem];
            } else {
                int first = rem%10;
                rem = rem/10;                
                int second = rem%10;
                string temp = "";
                if(second == 1){
                    temp = numberMap[second*10 + first];
                }
                rem = rem/10;
                int third = rem%10;
                
                if(third > 0){
                    intermediate = numberMap[third] + " " + dim[0];
                }
                if(second > 0){
                    seperator = (intermediate != "") ? " " : "";
                    if(temp == ""){
                        intermediate += seperator + numberMap[second * 10];
                    } else {
                        intermediate += seperator + temp;
                    }
                }
                
                if(temp == "" && first > 0){
                    seperator = (intermediate != "") ? " " : "";
                    intermediate += seperator + numberMap[first];
                }
            }
            
            if(counter > 0){
                seperator = (intermediate != "") ? " " : "";
                if(intermediate != "")
                    intermediate += (seperator + dim[counter]);
            }
                
            resultVector[counter] = intermediate;
            counter++;
        }
        
        result = resultVector[3];
                
        seperator = (result != "") ? " " : ""; 
        if(resultVector[2] != "")
            result += seperator + resultVector[2];
        seperator = (result != "") ? " " : "";
        if(resultVector[1] != "")
            result += seperator + resultVector[1];
        seperator = (result != "") ? " " : "";
        if(resultVector[0] != "")
            result += seperator + resultVector[0];
        
        return result;
    }
};

class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        vector<int> combination(len + 1, 1);
        
        if(s[0] == '0'){
            return 0;
        }
        
        for(int idx = 0; idx < len; idx++){
            if(idx == 0){
                combination[idx + 1] = 1;
            } else {
                if(s[idx] == '0'){
                    //current char 0 and there could be two scenario valid and invalid
                    if(s[idx - 1] > '2' || s[idx - 1] < '1'){
                        //invalid e.g 30 - 0 current char and prev is 3
                        //System.out.println("Here "+ s.charAt(idx - 1));
                        return 0;
                    } else {
                        combination[idx + 1] = combination[idx - 1];
                    }
                } else {
                    //current character non zero
                    if(s[idx - 1] == '0'){
                        //prev char is 0
                        combination[idx + 1] = combination[idx];
                    } else if(s[idx - 1] == '1'){
                        //prev char is 1
                        combination[idx + 1] = combination[idx] + combination[idx - 1];
                    } else if(s[idx - 1] == '2'){
                        //prev char is 2
                        if(s[idx] >= '1' && s[idx] <= '6'){
                            //curr char in between 1 and 6
                            combination[idx + 1] = combination[idx] + combination[idx - 1];
                        } else {
                            //curr char greater than 6
                            combination[idx + 1] = combination[idx];
                        }
                    } else {
                        //prev char greater than 2
                        combination[idx + 1] = combination[idx];
                    }
                }
            }
        }
        
        return combination[len];
    }
};

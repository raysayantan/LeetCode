/*
Validate if a given string can be interpreted as a decimal number.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. 
However, here is a list of characters that can be in a valid decimal number:

Numbers 0-9
Exponent - "e"
Positive/negative sign - "+"/"-"
Decimal point - "."
Of course, the context of these characters also matters in the input.
*/
class Solution {    
    string trimSpaces(string s){
        string result ="";
        int i = 0;
        while(s[i] == ' ' && i < s.length()){
            i++;
        }
        
        int k = s.length() - 1;
        while(k >= i && s[k] == ' '){
            k--;
        }
        if( k < i)
            return "";
        return s.substr(i, k - i + 1);
    }
    bool validStartChar(char c, bool &decimalPont, bool &isDigit){
        bool isValid = (c >= '0' && c <= '9') || (c == '+' || c == '-' || c == '.');
        if(c == '.'){
            decimalPont = true;
        }
        
        if(c >= '0' && c <= '9'){
            isDigit = true;
        }
        return isValid;
    }
    
    bool isValidChar(char c){
        bool isValid = (c >= '0' && c <= '9') || (c == '+' || c == '-') || (c == '.') || (c == 'e');
        
        return isValid;
    }
public:
    bool isNumber(string s) {
        s = trimSpaces(s);
        if(s.length() == 0) 
            return false;
        if(s.length() == 1){
            if(s[0] == '.' || s[0] == '+' || s[0] == '-')
                return false;
        }
        bool exponent = false;
        bool isDigit = false;
        bool decimalPoint = false;
        int i = 0;
        while(i < s.length()){
            //check if the first character is valid
            if(i == 0){
                if(!validStartChar(s[i], decimalPoint, isDigit))
                    return false;
                else {
                    i++;
                    continue;
                }
            }
            
            if(!isValidChar(s[i]))
                return false;
            
            //check for other characters
            if(s[i] >= '0' && s[i] <= '9'){
                isDigit = true;
                i++;
                continue;
            }
            
            if(s[i] == '.'){
                if(exponent == true || decimalPoint == true){
                    //decimal point can't come after exponent
                    //or there should not be more than one decimal point
                    return false;
                }
                
                decimalPoint = true;
                if(i + 1 < s.length()){
                    if(s[i + 1] >= '0' && s[i + 1] <= '9'){
                        isDigit = true;
                        i = i + 2;
                        continue;
                    } else {
                        //after decimal point it can be only number or e
                        if(s[i + 1] == 'e'){
                            i++;
                            continue;
                        }
                        return false;
                    }
                }
                i++;
                continue;
            }
            
            //other than first or the next to e we don't have sign anywhere in a valid number
            if(s[i] == '+' || s[i] == '-')
                return false;
            
            if(s[i] == 'e'){
                //already encountered 'e'
                if(exponent)
                    return false;
                else
                    exponent = true;
                
                //check previous should be a digit
                if(!((s[i - 1] >= '0' && s[i - 1] <= '9') || (s[i - 1] == '.' && isDigit == true))){
                    return false;
                }
                
                if(i + 1 < s.length()){
                    if(s[i+1] == '+' || s[i + 1] == '-'){
                        if(i + 2 < s.length()){
                            if(s[i + 2] >= '0' && s[i + 2] <= '9'){
                                i = i + 3;
                                continue;
                            } else {
                                return false;
                            }
                        } else {
                            return false;
                        }
                    } else {
                        if(s[i + 1] >= '0' && s[i+1] <= '9'){
                            i = i + 2;
                            continue;
                        } else {
                            return false;
                        }
                    }
                } else {
                    return false;
                }
            }
            
        }
        
        if(!isDigit)
            return false;
        return true;
    }
};

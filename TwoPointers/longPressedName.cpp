/*
Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard.  Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

 

Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.
Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.
Example 3:

Input: name = "leelee", typed = "lleeelee"
Output: true
Example 4:

Input: name = "laiden", typed = "laiden"
Output: true
Explanation: It's not necessary to long press any character.
 

Constraints:

1 <= name.length <= 1000
1 <= typed.length <= 1000
The characters of name and typed are lowercase letters.
*/
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int namelen = name.length();
        int typedlen = typed.length();
        int nidx = 0;
        int tidx = 0;
        while(nidx < namelen && tidx < typedlen){
            if(name[nidx] == typed[tidx]){
                nidx++;
                tidx++;
            } else {
                if(nidx > 0 && name[nidx - 1] == typed[tidx]){
                    tidx++;
                } else {
                    return false;
                }
            }
        }
        
        if(nidx < namelen){
            return false;
        }
        
        if(tidx < typedlen){
            while(tidx < typedlen){
                if(name[namelen - 1] != typed[tidx]){
                    return false;
                }
                
                tidx++;
            }
        }
        
        return true;
    }
};

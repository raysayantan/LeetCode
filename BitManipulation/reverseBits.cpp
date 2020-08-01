/*
Reverse bits of a given 32 bits unsigned integer.
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        int y = 0;
        for(int i = 0; i < 32; i++){
            y = n & 1;
            n = n>>1;
            res = res | (y << (31 - i));
        }
        
        return res;
    }
};

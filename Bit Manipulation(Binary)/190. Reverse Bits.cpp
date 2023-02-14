class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int d = 0;
        
        while(n > 0){
            res += (n & 1) << (31 - d);
            n >>= 1;
            d++;
        }
        return res;
    }
};

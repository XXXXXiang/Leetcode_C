/*
190. Reverse Bits

Reverse bits of a given 32 bits unsigned integer.
https://leetcode.com/problems/reverse-bits/
*/

uint32_t reverseBits(uint32_t n) {
    unsigned int ans = 0;
    for(int i = 0;i<16;i++){
        ans|= (n>>1+2*i)&(UINT32_C(1)<<15-i); //Exchange two bits per cycle.
        ans|= (n<<1+2*i)&(UINT32_C(1)<<16+i);
    }
    return ans;
};

#define mask1 0b01010101010101010101010101010101
#define mask2 0b00110011001100110011001100110011
#define mask3 0b00001111000011110000111100001111
#define mask4 0b00000000111111110000000011111111
#define mask5 0b00000000000000001111111111111111
int hammingWeight(uint32_t n) {
    n = (n&mask1) + ((n>>1)&mask1);
    n = (n&mask2) + ((n>>2)&mask2);
    n = (n&mask3) + ((n>>4)&mask3);
    n = (n&mask4) + ((n>>8)&mask4);
    n = (n&mask5) + ((n>>16)&mask5);
    return n;
}

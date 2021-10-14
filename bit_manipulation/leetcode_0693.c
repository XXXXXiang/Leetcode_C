/*
693. Binary Number with Alternating Bits

Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.
https://leetcode.com/problems/binary-number-with-alternating-bits/
*/

#define mask 0b10101010101010101010101010101010

bool hasAlternatingBits(int n){
    for(int i = 0;i<32;i++){
        if (n==(mask>>i)) //Shift mask for one bit each cycle to match inpute.
            return true;
        }
    return false;
}

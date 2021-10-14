/*
338. Counting Bits

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
https://leetcode.com/problems/counting-bits/
*/

int* countBits(int n, int* returnSize){
    *returnSize = n+1;
    int* arr = (int*)malloc(sizeof(int) * (n+1));
    arr[0] = 0;
    for(int i=1;i<n+1;i++){
        if (i&1)
            arr[i] = arr[i-1]+1; //if the last must right bit is 1, then the hamming weight is the previos one + 1.
        else
            arr[i] = arr[i>>1]; // if the last must right bit is 1, then the hamming weight is same as "if right shift 1 bit".
    }
    return arr;
}

/*
338. Counting Bits

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
https://leetcode.com/problems/counting-bits/
*/

int* countBits(int n, int* returnSize){
    *returnSize = n+1;
    int* arr = (int*)malloc(sizeof(int) * (n+1));
    arr[0] = 0;
    int r = 0; //right_first_zero
    for(int i=0;i<n;i++){
        for (r = 0;r<17;r++){
            if (((i>>r)&1)^1)
                break;
        }
        printf("%d\n",r);
        arr[i+1] = arr[i] + 1 -r;
    }
    return arr;
}

/*

need to know where is the most right 0 of the current number.
e.g.
If the current number is xxxxxx01111, then next number will loss 4 "1".

The most right 0 of current num    v.s.  next num will add how many "1".
                              0                                     +1  
                              1                                     +0
                              2                                     -1
                              3                                     -2
                              4                                     -2

*/

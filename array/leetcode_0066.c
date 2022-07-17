/*
Plus One
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int* ans = (int*)malloc(sizeof(int) * (digitsSize+1));
    bool cpl = 0;
    for(int i = digitsSize-1;i>=0;i--){
        if (cpl==1){
            ans[i+1] = digits[i];
            continue;
        }
        if (i == 0 && digits[i] == 9){
            ans[0] = 1;
            ans[i+1] = 0;
            *returnSize = digitsSize+1;
            return ans;
        }
        else if(digits[i] == 9){
            ans[i+1] = 0;
        }
        else{
            ans[i+1] = digits[i]+1;
            *returnSize = digitsSize;
            cpl = 1;
        }
    }
    return ans+1;
}

/*
Move Zeroes
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
*/
void moveZeroes(int* nums, int numsSize){
    int tail = 0;
    int nowIdx = 0;
    while(nowIdx < numsSize){
        while(nums[nowIdx] == 0){
            nowIdx++;
            if (nowIdx >= numsSize){
                return;
            }
        }
        int temp = nums[nowIdx];
        nums[nowIdx] = nums[tail];
        nums[tail] = temp;
        tail++;
        nowIdx++;
    }
}

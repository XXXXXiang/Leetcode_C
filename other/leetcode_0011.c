/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/


int maxArea(int* height, int heightSize){
    int l = 0;
    int r = heightSize - 1;
    int maxWater = 0;
    while(l != r){
        int width = r - l;
        int hight = (height[l] > height[r]? height[r]:height[l]);
        int water = width * hight;
        maxWater = (water > maxWater? water:maxWater);
        if (height[l] > height[r]) r--;
        else l++;
    }
    return maxWater;
}

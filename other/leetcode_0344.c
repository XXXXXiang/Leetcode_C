/*
344. Reverse String

Write a function that reverses a string. The input string is given as an array of characters s.
https://leetcode.com/problems/reverse-string/
*/

void reverseString(char* s, int sSize){
    char temp;
    for(int i = 0;i<sSize/2;i++){
        temp = s[i];
        s[i] = s[sSize-1-i];
        s[sSize-1-i] = temp;
    }
}

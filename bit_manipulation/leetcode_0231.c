/*
231. Power of Two
Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2^x.
*/
bool isPowerOfTwo(int long long n){
    return (((~n+1)&n)==n)&&n;
}
//Problem link - https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1
class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        return n==0? false : (ceil(log2(n))==floor(log2(n)));
    }
};

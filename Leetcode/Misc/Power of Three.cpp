//Problem link - https://leetcode.com/problems/power-of-three/

//Approach 1 -> Using recursion
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1) return true;
        if(n%3 || n==0) return false;
        return isPowerOfThree(n/3);
    }
};

//Approach 2 -> Without recursion or loop

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        int maxPwr = log(INT_MAX)/log(3);//maximum power of three which can be store in int
        int maxPwrVal = pow(3,maxPwr);//maximum power value
        return (maxPwrVal%n ==0);
    }
};

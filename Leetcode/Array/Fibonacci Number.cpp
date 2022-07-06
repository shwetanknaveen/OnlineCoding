//Problem link - https://leetcode.com/problems/fibonacci-number/

class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int lastToLast = 0,last = 1,thisNum;
        for(int i=2;i<=n;i++)
        {
            thisNum = lastToLast + last;//this is the value of F(i)
            lastToLast = last;
            last = thisNum;
        }
        return thisNum;
        
    }
};

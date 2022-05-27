//Problem link - https://leetcode.com/problems/powx-n/submissions/
//Video link - https://www.youtube.com/watch?v=l0YC3876qxg&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=16
//Time complexity -> O(log(n)) where n is the power
class Solution {
public:
    double myPow(double x, int n) {
        long long nCopy = n ;//storing n in long long as when INT_MIN is converted into positive integer, it will cause overflow
        double ans = 1.0;
        nCopy = abs(nCopy);
        
        while(nCopy)
        {
            if(nCopy&1)//power is odd
            {
                ans = ans * x;
                nCopy = nCopy-1;
            }
            else//power is even 
            {
                x = x * x;//note here that ans is not squared and x is squared and stored back into x
                nCopy =nCopy/2;
            }
        }
        if(n<0) ans = double(1.0)/ans;//if power was originally negative then we have to use
                                        //x^(-)n = 1/(x^n) 
        return ans;
    }
};

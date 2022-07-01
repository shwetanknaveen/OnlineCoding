//Problem link - https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) 
    {
        long low = 0,high = x,mid;
        while(low<=high)
        {
            mid = low+(high-low)/2;
            if(mid*mid<=x)
                low = mid+1;
            else
                high = mid-1;
        }
        return low-1;//low always pointed to right of the valid value
    }
};

//Problem link - https://leetcode.com/problems/number-of-common-factors/

class Solution {
public:
    int commonFactors(int a, int b) 
    {
        int ans = 0, high = __gcd(a,b);
        for(int i=1;i<=high;i++)
        {
            if(a%i==0 && b%i==0) ans++;
        }
        return ans;
    }
};

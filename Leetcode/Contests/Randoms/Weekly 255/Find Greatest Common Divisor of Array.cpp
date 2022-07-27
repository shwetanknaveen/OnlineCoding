//Problem link - https://leetcode.com/problems/find-greatest-common-divisor-of-array/

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = INT_MAX,maxi = INT_MIN;
        for(int i:nums)
        {
            mini = min(mini,i);
            maxi = max(maxi,i);
        }
        return __gcd(mini,maxi);
    }
};

//Problem link - https://leetcode.com/problems/maximum-xor-after-operations/
//Video link - https://www.youtube.com/watch?v=3VkRwbt_Pis&list=PLudlC33BR8eEiSWH654z2GKEF3Ckz6QWB&index=12

class Solution {
public:
    void setNonZeroBit(int &n,vector<bool> &bitAnyOne)//If any number has ith bit as 1 then set that bit as true
    {
        for(int i=0;i<32;i++)
        {
            if((1<<i)&n) bitAnyOne[32-i-1] = true;//bit at ith position has 1 from atleast one number
        }
    }
    int maximumXOR(vector<int>& nums) {
        vector<bool> bitAnyOne(32,false);
        for(int &i:nums)
            setNonZeroBit(i,bitAnyOne);
        
        int ans = 0;
        for(int i=0;i<32;i++)
            ans = (ans<<1) + bitAnyOne[i];//if any number has 1 at a bit, it will add up in ans
        return ans;
    }
};

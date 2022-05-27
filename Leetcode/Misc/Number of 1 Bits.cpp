//Problem link - https://leetcode.com/problems/number-of-1-bits/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0,nBits = 8*sizeof(n);
        for(int i=0;i<nBits;i++)
        {
            if(n & (1<<i)) ans++;
        }
        return ans;
    }
};

//Approach 2-> Without using number of bits in n

class Solution {
public:
    int hammingWeight(uint32_t n) 
	{
        int ans = 0;
        while(n)
        {
            ans += n&1;
            n >>= 1;
        }
        return ans;
    }
};

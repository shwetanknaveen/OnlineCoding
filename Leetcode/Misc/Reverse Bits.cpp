//Problem link - https://leetcode.com/problems/reverse-bits/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i=0;i<32;i++)//Evaluate the reverse of binary equivalent of input n into ans
        {
            ans = ans*2 + n%2;
            n /= 2;
        }
        return ans;
    }
};

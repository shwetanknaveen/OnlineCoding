//Problem link - https://leetcode.com/problems/minimize-xor/

class Solution {
public:
    
    int minimizeXor(int num1, int num2) 
    {
        int nSetBits = 0;
        for(int shift=0;shift<32;shift++)
        {
            if((num2>>shift)&1) nSetBits++;
        }
        vector<int> bits(32,0);
        int nTaken = 0;
        for(int shift=31;shift>=0 && nTaken<nSetBits;shift--)
        {
            if((num1)&(1<<shift))//First take those bits from left side which are set which will give zero with XOR
            {
                nTaken++;
                bits[31-shift] = 1;
            }
        }
        for(int shift=0;shift<32 && nTaken<nSetBits;shift++)
        {
            if(!((num1>>shift)&1))//Now take 0 bits as we have no other option from right side
            {
                nTaken++;
                bits[31-shift] = 1;
            }
        }
        
        int minX = 0;
        for(int i=0;i<32;i++)
            minX = minX*2 + bits[i];
        return minX;
    }
};

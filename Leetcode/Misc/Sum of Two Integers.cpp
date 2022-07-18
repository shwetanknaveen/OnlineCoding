//Problem link - https://leetcode.com/problems/sum-of-two-integers/
//Full adder logic
class Solution {
public:
    int getSum(int a, int b) {
        //bitset<32> A(a),B(b),ans(0);
        int ans = 0;
        bool carry = 0;
        for(int i=0;i<32;i++)
        {
            //ans[i] = A[i] ^ B[i] ^ carry;
            bool ai = (1<<i)&a, bi = (1<<i)&b ;
            ans |= ( ai^bi^carry) << i;
            //carry = (A[i]&B[i]) | (A[i]&carry) | (B[i]&carry);
            carry = ai & bi | ai & carry | bi & carry ;
        }
        //return int(ans.to_ulong());
        return ans;
    }
};

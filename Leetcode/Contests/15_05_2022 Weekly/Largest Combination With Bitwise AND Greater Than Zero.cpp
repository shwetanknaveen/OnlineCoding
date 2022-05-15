//Problem link - https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/

//Check for each bit that how many numbers are in candidate for which the same bit is set
class Solution {
public:
   int largestCombination(vector<int>& cs) 
   {
        int res = 0, max_e = *max_element(cs.begin(), cs.end());
        for (int b = 1; b <= max_e; b <<= 1) 
        {
            int cnt = 0;
            for (auto n : cs)//for above bit as set, how many candidates are there who have same bit set
                cnt += (n & b) > 0;
            res = max(res, cnt);
        }
        return res;
    }
};

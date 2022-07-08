//Problem link - https://leetcode.com/problems/factorial-trailing-zeroes/
//Useful link - https://brilliant.org/wiki/trailing-number-of-zeros/
//Video link - https://www.youtube.com/watch?v=SEWRqdG-cwY&list=PLudlC33BR8eEiSWH654z2GKEF3Ckz6QWB&index=13
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0,quot;
        while(n)
        {
            quot = n/5;
            ans += quot;
            n=quot;
        }
        return ans;
    }
};

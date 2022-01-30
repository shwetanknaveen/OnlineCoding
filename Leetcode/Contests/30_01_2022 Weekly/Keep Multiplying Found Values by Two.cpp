//Problem link - https://leetcode.com/problems/keep-multiplying-found-values-by-two/

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        for(int i:nums)
        {
            if(i==original)
                original <<= 1;
            if(original<i)
                break;
        }
        return original;
    }
};

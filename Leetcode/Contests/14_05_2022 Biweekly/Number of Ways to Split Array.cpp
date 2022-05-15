//Problem link - https://leetcode.com/contest/biweekly-contest-78/problems/number-of-ways-to-split-array/

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size(),ans=0;
        long long totalSum = 0;
        for(int i:nums)
            totalSum += i;
        long long leftSum=0,rightSum=totalSum;
        for(int i=0;i<n-1;i++)
        {
            leftSum += nums[i];
            rightSum -= nums[i];
            if(leftSum>=rightSum) ans++;
        }
        return ans;
    }
};

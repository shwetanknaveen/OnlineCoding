//Problem link - https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
//Average doesn't work because average can be biased but median won't be
class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
        int n = nums.size(),median,ans = 0;
        sort(nums.begin(),nums.end());
        if(n&1)
        {
            median = nums[n/2];
        }
        else//Actually in case of even number of elements, any number between two middle numbers will work hence no need to deal odd and even
        	//cases separately
        {
            median = (nums[n/2] + nums[n/2 - 1])/2;
        }
        for(int i:nums)
            ans += abs(i-median);
        
        return ans;
    }
};

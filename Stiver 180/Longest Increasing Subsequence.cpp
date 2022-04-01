//Problem link - https://leetcode.com/problems/longest-increasing-subsequence/

//If we are looking from right to left then we will have to find a strictly decreasing sequence. Initially we put INT_MAX on 
//the right most side so that it is the first picked element and while comparison for numbers on left hand side, every no.
//will be smaller than it and hence no issue in picking them.
//When we wish to take previous value taken into account then we can't make dp dimension based on exact value that is previously
//picked because it has very large range and that much space can't be alloted to dp hence rather than considering exact value
//that was picked previously we take its index.
class Solution {
public:
    int helper(vector<int> &nums,vector<vector<int>> &dp,int prevValInd,int ind)
    {
        if(ind<0) return 0;//We can't pick any number in the sequence outside the nums array
        
        if(dp[ind][prevValInd] != -1) return dp[ind][prevValInd];
        
        
        if(nums[ind]<nums[prevValInd])//We can either take this number or leave it
            dp[ind][prevValInd] = max(1+helper(nums,dp,ind,ind-1) 			, 	helper(nums,dp,prevValInd,ind-1));
            					/*If we are taking this number then				If we don't pick this number then
            					for other numbers on its left,prevValInd		prevValInd remains unchanged for 
            					will be this number's index i.e., ind			other numbers on its left
            					*/
            
        else//We can't take this number
            dp[ind][prevValInd] = helper(nums,dp,prevValInd,ind-1);
        
        return dp[ind][prevValInd];
    }
    int lengthOfLIS(vector<int>& nums) {
        nums.push_back(INT_MAX);
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        return helper(nums,dp,nums.size()-1,nums.size()-2);//Initially the prevValInd is of INT_MAX which we push ourselve
        													//and we start looking from right most number in actual nums
    }
};

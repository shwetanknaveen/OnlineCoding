//Problem link - https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool helper(vector<int> &nums,int ind,int reqSum,vector<vector<int>> &dp)
    {
        if(reqSum==0) return true;//Got the required sum
        if(reqSum<0 || ind >= nums.size()) return false;//reqSum will be <0 if we would have picked any number which can't be picked
        												//for required sum
        
        if(dp[ind][reqSum] != -1) return dp[ind][reqSum];
        
        return dp[ind][reqSum] = (helper(nums,ind+1,reqSum,dp) || helper(nums,ind+1,reqSum-nums[ind],dp));
        						/*We are not picking this number		We are picking this number hence
        																required sum further is reduced by value
        																of this number
        						
        						*/
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i:nums)
            totalSum += i;
        if(totalSum&1) return false;//if total sum is odd then we can't divide it in two equal parts
        vector<vector<int>> dp(nums.size(),vector<int>(totalSum/2+1,-1));//required sum is totalSum/2
        return helper(nums,0,totalSum/2,dp);
        
    }
};


//We can save few recursive call in the following way
class Solution {
public:
    bool helper(vector<int> &nums,int ind,int reqSum,vector<vector<int>> &dp)
    {
        if(reqSum==0) return true;
        if(ind >= nums.size()) return false;
        
        if(dp[ind][reqSum] != -1) return dp[ind][reqSum];
        
        if(nums[ind]<=reqSum)
            dp[ind][reqSum] = (helper(nums,ind+1,reqSum,dp) || helper(nums,ind+1,reqSum-nums[ind],dp));
        else
            dp[ind][reqSum] = helper(nums,ind+1,reqSum,dp);
        
        return dp[ind][reqSum];
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i:nums)
            totalSum += i;
        if(totalSum&1) return false;
        vector<vector<int>> dp(nums.size(),vector<int>(totalSum/2+1,-1));
        return helper(nums,0,totalSum/2,dp);
        
    }
};

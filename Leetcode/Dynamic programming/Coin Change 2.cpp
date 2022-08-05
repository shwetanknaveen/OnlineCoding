//Problem link - https://leetcode.com/problems/coin-change-2/
//See "Leetcode/Dynamic Programming/Combination Sum IV" for permutation concept
class Solution {
public:
    int solve(vector<int> &nums,int target,int ind,vector<vector<int>> &dp)
    {
        if(target<=0 || ind>=nums.size())
        {
            return target==0;//We can't proceed further hence if we have target = 0 then this is one combination
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int take = solve(nums,target-nums[ind],ind,dp);//When we take this coin, we can take this again like unbounded knapsack
        int skip = solve(nums,target,ind+1,dp);
        
        return dp[ind][target] = take+skip;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return solve(coins,amount,0,dp);
    }
};

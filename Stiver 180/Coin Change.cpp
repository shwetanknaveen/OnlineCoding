//Problem link - https://leetcode.com/problems/coin-change/
//See this question's solution in "Online Coding/GFG/DP/Coin change min no of coins RECURSIVE" also


class Solution {
public:
    int helper(vector<int> &coins,int ind,int amount,vector<vector<int>> &dp)
    {
        if(amount == 0)
            return 0;//no coins needed now as target has been completed
        if(ind>=coins.size()) return INT_MAX-1;//no coins can suffice the target outside the coins array
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int takeThis = INT_MAX,dontTakeThis = INT_MAX;
        
        if(coins[ind]<=amount)//this is little different than what we did in "Online Coding/GFG/DP/Coin change min no of coins RECURSIVE"
            takeThis = 1 + helper(coins,ind,amount-coins[ind],dp);//here we are making call to take this coin only when we can
            														//feasibly take this i.e., coins[ind] <= amount
        
        dontTakeThis = helper(coins,ind+1,amount,dp);
        
        return dp[ind][amount] = min(takeThis,dontTakeThis);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int coinsReq = helper(coins,0,amount,dp);
        return (coinsReq<=amount ? coinsReq : -1);
    }
};

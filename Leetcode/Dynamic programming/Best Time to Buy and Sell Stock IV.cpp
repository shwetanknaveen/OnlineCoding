//Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:
    int solve(vector<int> &prices,int k,bool canBuy,int ind,vector<vector<vector<int>>> &dp)
    {
        if(k<=0 || ind>=prices.size()) return 0;
        
        if(dp[ind][k][canBuy] != -1) return dp[ind][k][canBuy];
        
        int withTransaction,noTransaction;/*
        									withTransaction : either we buy or sell stock on this day
        									noTransaction : we don't do trasaction (neither buy nor sell) on this day
        								  */
        
        if(canBuy)//we can buy only if we don't hold any stock already and once we buy we pass canBuy as false but we don't
        		//change k because k will be reduced for one complete transaction which will be marked when stock is sold
            withTransaction = solve(prices,k,false,ind+1,dp) - prices[ind];//when we buy, we add price of stock with -ve 
            																//sign because we are expending to buy
        else//when canBuy is false it means we are allowed only to sell
            withTransaction = solve(prices,k-1,true,ind+1,dp) + prices[ind];//now we pass canBuy as true because looking further
            																//we can again buy stocks and we also reduce k because
            																//after selling we complete one transaction
        
        noTransaction = solve(prices,k,canBuy,ind+1,dp);
        
        return dp[ind][k][canBuy] = max(withTransaction,noTransaction);//as we have to maximise the profit
    }
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return solve(prices,k,true,0,dp);
    }
};

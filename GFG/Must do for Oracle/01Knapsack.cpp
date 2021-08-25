//Question Link - https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
//Aditya verma link -Recursive prog- https://www.youtube.com/watch?v=kvyShbFVaY8&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=3
//Aditya verma memoization - https://www.youtube.com/watch?v=fJbIuhs24zQ&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=4
class Solution
{
    public:
    int knapSack(int W, int wt[], int val[], int n) 
    { 
    vector<vector<int>> dp(n+1,vector<int>(W+1));
    for (int i = 0; i < n+1; i++)
        for (int j = 0; j < W + 1; j++)
            dp[i][j] = -1;
    return knapSackRec(W, wt, val, n, dp);
    }
    int knapSackRec(int W,int wt[],int val[],int n,vector<vector<int>> &dp)
    {
        if(n==0 || W==0)
        return 0;
        if(dp[n][W]!=-1) 
        return dp[n][W];//return already remembered value
        if(W>=wt[n-1])//doing n-1 for wt because wt is stored from 0 index
        {
            dp[n][W] = max(val[n-1]+knapSackRec((W-wt[n-1]),wt,val,n-1,dp),knapSackRec(W,wt,val,n-1,dp));
            return dp[n][W];
        }
        else if(W<wt[n-1])
        {
            dp[n][W] = knapSackRec(W,wt,val,n-1,dp);
            return dp[n][W];
        }
    }
};

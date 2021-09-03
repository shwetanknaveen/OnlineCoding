//Problem link - https://practice.geeksforgeeks.org/problems/ncr1019/1#
class Solution{
public:
    int recur_nCr(int n,int r,vector<vector<int>> &dp)
    {
        if(n==r || r==0)
        return 1;
        if(n<r)
        return 0;
        
        if(dp[n][r]!=-1) return dp[n][r];
        else return dp[n][r]=(recur_nCr(n-1,r-1,dp)+recur_nCr(n-1,r,dp))%1000000007;
    }
    int nCr(int n, int r){
        // code here
        vector<vector<int>> dp(n+1,vector<int>(r+1));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=r;j++)
            dp[i][j] = -1;
        }
        return recur_nCr(n,r,dp);
        
    }
};

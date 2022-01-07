//Problem link - https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1/
//Video link - https://www.youtube.com/watch?v=823Grn4_dCQ&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=24

//This is just a variation of LCS
class Solution
{
    public:
    int LCS(string &x,string &y,int ind1,int ind2,vector<vector<int>> &dp)
    {
        if(ind1>=x.length() || ind2>=y.length()) return 0;
        
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        if(x[ind1] == y[ind2])
        dp[ind1][ind2] = 1+LCS(x,y,ind1+1,ind2+1,dp);
        
        else
        dp[ind1][ind2] = max(LCS(x,y,ind1+1,ind2,dp),LCS(x,y,ind1,ind2+1,dp));
        
        return dp[ind1][ind2];
    }
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return (m+n-LCS(X,Y,0,0,dp));
    }
};

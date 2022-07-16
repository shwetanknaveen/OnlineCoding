//Problem link - https://leetcode.com/problems/out-of-boundary-paths/

class Solution {
public:
    int mod = 1e9 + 7;
    //Here it can be the condition that we can return back to the same cell in the path
    int solve(int i,int j,int maxMove,int &row,int &cols,vector<vector<vector<int>>> &dp)
    {
        if(i<0 || i>=row || j<0 || j>=cols) return maxMove>=0;//It is reaching outside boundary and we haven't exhausted our maxMove
        if(maxMove==0) return 0;//We are inside the boundary and there is no maxMove remaining
        if(dp[i][j][maxMove] != -1) return dp[i][j][maxMove];
        long left = solve(i,j-1,maxMove-1,row,cols,dp);
        long right = solve(i,j+1,maxMove-1,row,cols,dp);
        long up = solve(i-1,j,maxMove-1,row,cols,dp);
        long down = solve(i+1,j,maxMove-1,row,cols,dp);
        
        return dp[i][j][maxMove] = (left+right+up+down)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return solve(startRow,startColumn,maxMove,m,n,dp);
    }
};

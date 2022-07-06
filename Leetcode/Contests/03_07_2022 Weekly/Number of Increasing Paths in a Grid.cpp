//Problem link - https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/

class Solution {
public:
    int dfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp,int lastVal,int &mod)
    {
        if(i<0 || i>=grid.size() || j<0 || j>= grid[i].size() || grid[i][j]<=lastVal)
        {//														this is not forming strictly
        //														increasing path														
            return 0;
        }
        if(dp[i][j]) return dp[i][j];//Already remember that from this cell, how may paths will it add
        
        return dp[i][j] = (1+dfs(i+1,j,grid,dp,grid[i][j],mod)%mod + dfs(i-1,j,grid,dp,grid[i][j],mod)%mod
                          + dfs(i,j+1,grid,dp,grid[i][j],mod)%mod + dfs(i,j-1,grid,dp,grid[i][j],mod)%mod)%mod;
                          /*
                          Cleaner way to write this is (avoiding inner mods for preventing overflow)
                          return dp[i][j] = (1LL+dfs(i+1,j,grid,dp,grid[i][j],mod) + dfs(i-1,j,grid,dp,grid[i][j],mod)
                          + dfs(i,j+1,grid,dp,grid[i][j],mod) + dfs(i,j-1,grid,dp,grid[i][j],mod))%mod;
                          */
    }
    int countPaths(vector<vector<int>>& grid) {
        int row = grid.size(),cols = grid[0].size(),mod = 1e9+7;
        vector<vector<int>> dp(row,vector<int>(cols,0));
        int res = 0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<cols;j++)
            {
                res = (res%mod + dfs(i,j,grid,dp,0,mod)%mod)%mod;//pass the first lastVal as 0(least value) because first value can always be
                												//picked
            }
        }
        return res;
    }
};

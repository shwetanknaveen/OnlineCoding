//Problem link - https://leetcode.com/problems/minimum-path-sum/discuss/23457/C%2B%2B-DP


//Approach 1 -> Top down approch

//Here no need of visited grid as movement is allowed only in right and bottom direction hence if clash happens, one of dfs
//call would have already initialised dp for the clashing cell.
class Solution {
public:
    int dfs(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &dp)
    {
        if(i>=grid.size() || j>=grid[0].size())
            return INT_MAX-100;//return large value so that it don't get counted in solution but to prevent integer overflow
            					//we have to subtract the largest value of grid[i][j] from INT_MAX so that after its addition 
            					//overflow is not caused
        if(dp[i][j] != -1) return dp[i][j];
        if(i==grid.size()-1 && j==grid[0].size()-1)
        {
            dp[i][j] = grid[i][j];//reached final state hence final cell of grid is the only cost
        }
        else
        {
            dp[i][j] = grid[i][j]+min(dfs(grid,i+1,j,dp),dfs(grid,i,j+1,dp));
        }
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,-1));
        return dfs(grid,0,0,dp);
        
    }
};

//Approach 2 Bottom up approach
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(),cols = grid[0].size();
        vector<vector<int>> sum(row,vector<int>(cols,0));
        sum[0][0] = grid[0][0];
        
        //Initialising the first row
        for(int j=1;j<cols;j++)
        {
            sum[0][j] = sum[0][j-1] + grid[0][j];//this cell value added with cost of reaching cell left to it
                                                //movement is only allowed in either right or down direction
        }
        
        //Initialising the first column
        for(int i=1;i<row;i++)
        {
            sum[i][0] = sum[i-1][0] + grid[i][0];//this cell value added with cost of reaching cell up to it
        }
        
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<cols;j++)
            {
                sum[i][j] = grid[i][j] + min(sum[i-1][j],sum[i][j-1]);
            }
        }
        
        return sum[row-1][cols-1];
    }
};

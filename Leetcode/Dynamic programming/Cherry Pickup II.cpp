//Problem link - https://leetcode.com/problems/cherry-pickup-ii/


//At any time, both will be in same row
class Solution {
public:
    int solve(int i,int j1,int j2,vector<vector<int>> &grid,int &row,int &col,vector<vector<vector<int>>> &dp)
    {
        if(j1<0 || j2<0 || j1>=col || j2>=col) return 0;
        if(i==row-1) return j1==j2 ? grid[i][j1] : (grid[i][j1] + grid[i][j2]);//If they are in same cell then cell value is used one time
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        for(int x=-1;x<=1;x++)
        {
            for(int y=-1;y<=1;y++)
            {
                if(j1==j2)//if they are in same cell then cell value is used one time
                    dp[i][j1][j2] =  max(dp[i][j1][j2],grid[i][j1] + solve(i+1,j1+x,j2+y,grid,row,col,dp));
                else
                    dp[i][j1][j2] = max(dp[i][j1][j2],grid[i][j1] + grid[i][j2] + solve(i+1,j1+x,j2+y,grid,row,col,dp));
            }
        }
        return dp[i][j1][j2];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size(), cols = grid[0].size();
        vector<vector<vector<int>>> dp(row,vector<vector<int>>(cols,vector<int>(cols,-1)));
        return solve(0,0,cols-1,grid,row,cols,dp);
    }
};

//Problem link - https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
/*Here dp[i][j] gives longest increasing path length in the matrix if we start from matrix[i][j]*/

class Solution {
public:
    int helper(vector<vector<int>> &matrix,vector<vector<int>> &dp,vector<vector<bool>> &vis,int i,int j)
    {
        int rows = matrix.size(),cols = matrix[0].size(),left,right,up,down;
        if(vis[i][j]) return 0;//This recursion call is hitting its own created path hence return 0
        
        
        if(dp[i][j] != -1) return dp[i][j];
        left = right = up = down = 0;
        
        vis[i][j] = true;
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j])//left
            left = 1 + helper(matrix,dp,vis,i,j-1);
        if(j+1<cols && matrix[i][j+1]>matrix[i][j])//right
            right = 1 + helper(matrix,dp,vis,i,j+1);
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j])//up
            up = 1 + helper(matrix,dp,vis,i-1,j);
        if(i+1<rows && matrix[i+1][j]>matrix[i][j])//down
            down = 1 + helper(matrix,dp,vis,i+1,j);
        vis[i][j] = false;
        
        return dp[i][j] = max(max(left,right),max(up,down));
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,-1));
        vector<vector<bool>> vis(rows,vector<bool>(cols,false));
        int ans = 0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                ans = max(ans,helper(matrix,dp,vis,i,j));
            }
        }
        return ans+1;//We have to return number of cells in the path and not number of edges hence we do +1 in ans while returning
    }
};

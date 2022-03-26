//Problem link - https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    void dfs(int i,int j,vector<vector<char>> &grid,vector<vector<int>> &vis)
    {
        vis[i][j] = 1;
        if(i>0 && grid[i-1][j]=='1' && !vis[i-1][j])//go up and if it is part of this island
            dfs(i-1,j,grid,vis);
        if(i<grid.size()-1 && grid[i+1][j]=='1' && !vis[i+1][j])//go down and if it is part of this island
            dfs(i+1,j,grid,vis);
        if(j>0 && grid[i][j-1]=='1' && !vis[i][j-1])//go left and if it is part of this island
            dfs(i,j-1,grid,vis);
        if(j<grid[0].size()-1 && grid[i][j+1]=='1' && !vis[i][j+1])//go right and if it is part of this island
            dfs(i,j+1,grid,vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> vis(row,vector<int>(col,0));
        int ans = 0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j] == '1' && !vis[i][j])
                {
                    ans++;//this is a iland and we will mark all its parts (cells) as visited
                    dfs(i,j,grid,vis);
                }
            }
        }
        return ans;
    }
};

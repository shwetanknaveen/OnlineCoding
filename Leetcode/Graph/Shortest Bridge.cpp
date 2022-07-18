//Problem link - https://leetcode.com/problems/shortest-bridge/

class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &grid,vector<vector<bool>> &vis,queue<pair<pair<int,int>,int>> &qu)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || vis[i][j] || grid[i][j] == 0) return;
        
        vis[i][j] = true;
        qu.push(make_pair(make_pair(i,j),0));
        dfs(i,j-1,grid,vis,qu);
        dfs(i,j+1,grid,vis,qu);
        dfs(i-1,j,grid,vis,qu);
        dfs(i+1,j,grid,vis,qu);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int row = grid.size(), cols = grid[0].size();
        vector<vector<bool>> vis(row,vector<bool>(cols,false));
        queue<pair<pair<int,int>,int>> qu;//<i,j>,distance
        bool flag = false;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(i,j,grid,vis,qu);//Push all the cells of this island on queue for starting BFS
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        while(!qu.empty())
        {
            int size = qu.size();
            while(size--)
            {
                auto pOfp = qu.front();
                qu.pop();
                int i = pOfp.first.first, j = pOfp.first.second, dist = pOfp.second;
                if(j>0 && !vis[i][j-1])//for left, if the left cell exists and is unvisited
                {
                    if(grid[i][j-1] == 1) return dist;//other island found and since it's mulitsource BFS hence distance will be minimum
                    vis[i][j-1] = true;//otherwise this cell is marked visited
                    qu.push(make_pair(make_pair(i,j-1),dist+1));//it increased length 1 of the bridge to be constructed
                }
                if(j<cols-1 && !vis[i][j+1])//for right
                {
                    if(grid[i][j+1] == 1) return dist;
                    vis[i][j+1] = true;
                    qu.push(make_pair(make_pair(i,j+1),dist+1));
                }
                if(i>0 && !vis[i-1][j])//for up
                {
                    if(grid[i-1][j] == 1) return dist;
                    vis[i-1][j] = true;
                    qu.push(make_pair(make_pair(i-1,j),dist+1));
                }
                if(i<row-1 && !vis[i+1][j])//for down
                {
                    if(grid[i+1][j] == 1) return dist;
                    vis[i+1][j] = true;
                    qu.push(make_pair(make_pair(i+1,j),dist+1));
                }
                
            }
        }
        return 0;
    }
};

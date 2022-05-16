//Problem link - https://leetcode.com/problems/shortest-path-in-binary-matrix/

//Approach 1 - DFS -> Gave TLE
class Solution {
public:
    void dfs(vector<vector<int>> &grid,int i,int j,int &ans,int step)
    {
        int rows = grid.size(),cols = grid[0].size();
        if(i<0 || i>=rows || j<0 || j>=cols || grid[i][j]==1) return;
        if(i==rows-1 && j==cols-1)
        {
            ans = min(ans,step);
            return;
        }
        step++;
        grid[i][j] = 1;
        dfs(grid,i,j-1,ans,step);
        dfs(grid,i-1,j-1,ans,step);
        dfs(grid,i-1,j,ans,step);
        dfs(grid,i-1,j+1,ans,step);
        dfs(grid,i,j+1,ans,step);
        dfs(grid,i+1,j+1,ans,step);
        dfs(grid,i+1,j,ans,step);
        dfs(grid,i+1,j-1,ans,step);
        grid[i][j] = 0;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        dfs(grid,0,0,ans,1);
        if(ans==INT_MAX) return -1;//If ans hasn't been updated after exploring all the path then there is no way to reach destination
        return ans;
    }
};


//BFS will always give the shortest path
//Approach 2 -> BFS -> Putting checks before pushing on the queue gave TLE!!

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        if(grid[0][0]==1 || grid[rows-1][cols-1]) return -1;
        queue<pair<int,int>> qu;
        qu.push(make_pair(0,0));
        bool foundPath = false;
        int ans = 1;
        
        while(!qu.empty())
        {
            pair<int,int> thisPoint;
            int size = qu.size();
            while(size--)
            {
                thisPoint = qu.front();
                int i = thisPoint.first, j = thisPoint.second;
                qu.pop();
                if(i==rows-1 && j==cols-1)
                {
                    foundPath = true;
                    break;
                }
                grid[i][j] = 1;//set this cell as an obstacle
                //These condition checking force to give TLE
                if(j-1>=0 && grid[i][j-1]==0) qu.push(make_pair(i,j-1));
                if(i-1>=0 && j-1>=0 && grid[i-1][j-1]==0) qu.push(make_pair(i-1,j-1));
                if(i-1>=0 && grid[i-1][j]==0) qu.push(make_pair(i-1,j));
                if(i-1>=0 && j+1<cols && grid[i-1][j+1]==0) qu.push(make_pair(i-1,j+1));
                if(j+1<cols && grid[i][j+1]==0) qu.push(make_pair(i,j+1));
                if(i+1<rows && j+1<cols && grid[i+1][j+1]==0) qu.push(make_pair(i+1,j+1));
                if(i+1<rows && grid[i+1][j]==0) qu.push(make_pair(i+1,j));
                if(i+1<rows && j-1>=0 && grid[i+1][j-1]==0) qu.push(make_pair(i+1,j-1));
            }
            if(foundPath) break;
            ans++;
        }
        
        if(!foundPath) return -1;
        return ans;
    }
};

//Approach 3 -> Optimising BFS -> Rather than putting checks before pushing the point on queue, we check before processing the point popped
//from queue

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        if(grid[0][0]==1 || grid[rows-1][cols-1]) return -1;
        queue<pair<int,int>> qu;
        qu.push(make_pair(0,0));
        bool foundPath = false;
        int ans = 1;
        
        while(!qu.empty())
        {
            pair<int,int> thisPoint;
            int size = qu.size();
            while(size--)
            {
                thisPoint = qu.front();
                int i = thisPoint.first, j = thisPoint.second;
                qu.pop();
                if(i==rows-1 && j==cols-1)
                {
                    foundPath = true;
                    break;
                }
                if(i<0 || i>=rows || j<0 || j>=cols || grid[i][j] == 1) continue;//can't process this point as it is either out of grid
                															//or it is a obstacle point
                grid[i][j] = 1;//set this cell as an obstacle
                qu.push(make_pair(i,j-1));
                qu.push(make_pair(i-1,j-1));
                qu.push(make_pair(i-1,j));
                qu.push(make_pair(i-1,j+1));
                qu.push(make_pair(i,j+1));
                qu.push(make_pair(i+1,j+1));
                qu.push(make_pair(i+1,j));
                qu.push(make_pair(i+1,j-1));
            }
            if(foundPath) break;
            ans++;
        }
        
        if(!foundPath) return -1;
        return ans;
    }
};

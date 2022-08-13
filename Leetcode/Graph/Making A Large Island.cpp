//Problem link - https://leetcode.com/problems/making-a-large-island/

class Solution {
public:
    vector<int> dir1 = {0,0,-1,1};
    vector<int> dir2 = {-1,1,0,0};
    void getAreaAndFillId(int i,int j,vector<vector<int>> &grid,vector<vector<bool>> &vis,int &area,int &groupId)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || vis[i][j] || grid[i][j]==0) return;
        area++;//Count this cell in total area
        vis[i][j] = true;//mark this cell visited
        grid[i][j] = groupId;//fill groupId of this island in this cell
        for(int x=0;x<4;x++)//explore all cells of this island by DFS
            getAreaAndFillId(i+dir1[x],j+dir2[x],grid,vis,area,groupId);
    }
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size(),groupId = 2,maxi = 0;
        unordered_map<int,int> groupIdArea;//Group id of island -> its area
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0) continue;//this is not island then no need to process it
                int area = 0;//let's find out area of this island and fill unique group id in the cells of this island
                getAreaAndFillId(i,j,grid,vis,area,groupId);
                maxi = max(maxi,area);//save this area as maximum possible ans because it may be the case that there is no zero at all in the grid and this is the maximum possible area
                groupIdArea[groupId] = area;
                //Now area of this island has been calculated and saved and groupId has been filled in each cell
                groupId++;//change group id so that each island gets unique group id
            }
            
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)//this zero can be flipped to one and can be merged in its surrounding island
                {
                    int total = 1;//this flipped zero will add 1 to the total area
                    unordered_set<int> includedGroupIds;
                    for(int x=0;x<4;x++)
                    {
                        int adjI = i+dir1[x],adjJ = j+dir2[x];
                        if(adjI<0 || adjI>=n || adjJ<0 || adjJ>=n) continue;
                        if(includedGroupIds.find(grid[adjI][adjJ])==includedGroupIds.end())//this neighbour island hasn't been included yet
                        {
                            total = total + groupIdArea[grid[adjI][adjJ]];//add its area
                            includedGroupIds.insert(grid[adjI][adjJ]);//include this island
                        }
                    }
                    maxi = max(maxi,total);
                }
            }
        }
        return maxi;
    }
};

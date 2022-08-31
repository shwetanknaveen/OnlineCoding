//Problem link - https://leetcode.com/problems/pacific-atlantic-water-flow/
//See "Leetcode/Graph//Surrounded Regions"
class Solution {
public:
    vector<vector<bool>> pac,atlan;
    int rows,cols;
    vector<vector<int>> ans;
    void dfs(int i,int j,vector<vector<bool>> &ocean,vector<vector<int>> &heights)
    {
        if(ocean[i][j]) return;//this ocean has already touched this cell
        ocean[i][j] = true;
        
        if(pac[i][j] && atlan[i][j]) ans.push_back({i,j});//if this cell is touched by both the oceans then add in ans
        
        if(i-1>=0 && heights[i-1][j]>=heights[i][j]) dfs(i-1,j,ocean,heights);//up -> We are going from ocean to the cell hence destination cell's height should be greater
        if(i+1<rows && heights[i+1][j]>=heights[i][j]) dfs(i+1,j,ocean,heights);//down
        if(j-1>=0 && heights[i][j-1]>=heights[i][j]) dfs(i,j-1,ocean,heights);//left
        if(j+1<cols && heights[i][j+1]>=heights[i][j]) dfs(i,j+1,ocean,heights);//right
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        rows = heights.size();
        cols = heights[0].size();
        pac.resize(rows,vector<bool>(cols,false));
        atlan.resize(rows,vector<bool>(cols,false));
        for(int j=0;j<cols;j++)//first row and last row
        {
            dfs(0,j,pac,heights);//first row in contact with Pacific ocean
            dfs(rows-1,j,atlan,heights);//last row in contact with Atlantic ocean
        }
        for(int i=0;i<rows;i++)
        {
            dfs(i,0,pac,heights);//first column in contact with pacific ocean
            dfs(i,cols-1,atlan,heights);//last column in contact with atlantic ocean
        }
        return ans;
    }
};

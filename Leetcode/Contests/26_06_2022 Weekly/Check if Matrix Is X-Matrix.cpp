//Problem link - https://leetcode.com/problems/check-if-matrix-is-x-matrix/


class Solution {
public:
    
    bool checkXMatrix(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(i==j || j==cols-(i+1))//diagonal elements
                {
                    if(grid[i][j]==0) return false;//diagonal values have to be non zero
                }
                else //non diagonal elements
                {
                    if(grid[i][j]!=0) return false;//non diagonal values have to be zero
                }
            }
        }
        return true;
    }
};

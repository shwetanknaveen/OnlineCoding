//Problem link - https://leetcode.com/problems/largest-local-values-in-a-matrix/

class Solution {
public:
    vector<int> dir1 = {0,0,1,-1,1,-1,1,-1,0};
    vector<int> dir2 = {1,-1,0,0,1,-1,-1,1,0};
    int getMax(int centI,int centJ,vector<vector<int>> &grid)
    {
        int n = grid.size();
        int maxi = 1;
        for(int x=0;x<9;x++)
        {
            int newI = centI+dir1[x], newJ=centJ+dir2[x];
            if(newI<0 || newI==n || newJ<0 || newJ==n) continue;
            maxi = max(maxi,grid[newI][newJ]);
        }
        return maxi;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2,vector<int>(n-2));
        for(int i=0;i<n-2;i++)
        {
            for(int j=0;j<n-2;j++)
            {
                
                ans[i][j] = getMax(i+1,j+1,grid);//it has to be centered around i+1 and j+1
            }
        }
        return ans;
    }
};

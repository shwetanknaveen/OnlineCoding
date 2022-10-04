//Problem link - https://leetcode.com/problems/maximum-sum-of-an-hourglass/

//Or we could have simple traversed upto m-2 and n-2
class Solution {
public:
    int m,n;
    bool isPossible(int i,int j)
    {
        return ((i+2)<m && (j+2)<n);
    }
    int getSum(int i,int j,vector<vector<int>> &grid)
    {
        int sum = 0;
        sum = grid[i][j] + grid[i][j+1] + grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
        return sum;
    }
    int maxSum(vector<vector<int>>& grid) 
    {
        this->m = grid.size();
        this->n = grid[0].size();
        int ans = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isPossible(i,j))
                    ans = max(ans,getSum(i,j,grid));
            }
        }
        return ans;
    }
};

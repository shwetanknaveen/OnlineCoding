//Problem link - https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/

class Solution {
public:
    int nRow,nCol;
    int solve(int row,int sum,vector<vector<int>> &mat,int &target,vector<vector<int>> &dp)
    {
        if(row>=nRow) return abs(sum-target);
        
        if(dp[row][sum] != -1) return dp[row][sum];
        
        int ans = INT_MAX;
        for(int i=0;i<nCol;i++)
        {
            ans = min(ans,solve(row+1,sum+mat[row][i],mat,target,dp));
            if(ans==0) break;//ans can't be less than 0
        }
        return dp[row][sum] = ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        this->nRow = mat.size();
        this->nCol = mat[0].size();
        vector<vector<int>> dp(nRow,vector<int>(70*70+1,-1));//sum can be at max 70 x 70
        return solve(0,0,mat,target,dp);
    }
};

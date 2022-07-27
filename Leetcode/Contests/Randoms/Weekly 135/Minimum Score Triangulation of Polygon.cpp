//Problem link - https://leetcode.com/problems/minimum-score-triangulation-of-polygon/

//https://www.youtube.com/watch?v=h6MxKmDimhg -> From 4:35 onwards
class Solution {
public:
    int solve(int i,int j,vector<int> &vals,vector<vector<int>> &dp)
    {
        if(dp[i][j] != -1) return dp[i][j];
        int thisScore = INT_MAX;
        for(int k=i+1;k<j;k++)//choosing third vertex at k apart from i and j divides the polygon into two subproblems
        {
            thisScore = min(thisScore,solve(i,k,vals,dp)+vals[i]*vals[k]*vals[j]+solve(k,j,vals,dp));
        }
        return dp[i][j] = thisScore==INT_MAX?0:thisScore;//if thisScore is INT_MAX it means there is no more triangulation possible in this subproblem as this there is no vertex between i and j
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,n-1,values,dp);
    }
};

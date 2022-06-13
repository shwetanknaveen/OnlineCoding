//Problem link - https://leetcode.com/problems/triangle/

//Approach -1 Top down DP 2 dimenstions

class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &trian,vector<vector<int>> &dp)
    {
        if(i==trian.size()-1)
            return trian[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = trian[i][j]+min(solve(i+1,j,trian,dp),solve(i+1,j+1,trian,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int nRow = triangle.size();
        vector<vector<int>> dp(nRow,vector<int>(nRow,-1));
        return solve(0,0,triangle,dp);
    }
};

//Approach 2 -> Converting the above code into bottom up DP

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int nRow = triangle.size();
        vector<vector<int>> dp(nRow,vector<int>(nRow,0));
        
        for(int i=nRow-1;i>=0;i--)
        {
            for(int j=i;j>=0;j--)//maximum value of j(column) in any row is row number itself
            {
                if(i==nRow-1)
                {
                    dp[i][j] = triangle[i][j];
                    continue;
                }
                dp[i][j] = triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};

//Approach 3 -> DP with 1 dimension

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int nRow = triangle.size();
        vector<int> dp = triangle[nRow-1];//Initially on last level, cost to reach there is cell value itself
        for(int i=nRow-2;i>=0;i--)
        {
            for(int j=0;j<triangle[i].size();j++)//from jth column in ith row, min sum to reach the last row
            {
                dp[j] = triangle[i][j] + min(dp[j],dp[j+1]);
                		/*
                						Previous values of dp[j] and dp[j+1]
                						states the cost to reach last row from
                						jth and (j+1)th column in (i+1)th row.
                						Hence from this jth col in ith row,
                						cost to reach last row is calculated this
                						way
                		*/
            }
        }
        
        return dp[0];
        //We have to return the minimum sum starting from 0th row and 0th column and we know that the last row for which values were stored
        //in dp is 1st row only
    }
};



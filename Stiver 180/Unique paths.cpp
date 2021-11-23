//Problem link - https://leetcode.com/problems/unique-paths/submissions/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return getAns(0,0,m,n,dp);
    }
    int getAns(int currRow,int currColumn,int m,int n,vector<vector<int>> &dp)
	{
    
    if(currRow>m-1 || currColumn>n-1) return 0;
	/* Here returning 0 as this is not the way to reach bottom right.*/
    if(currRow==m-1 && currColumn == n-1)
    {
        return 1;//reached bottom right column then this is one way to reach here
    }
    
    	
    if(dp[currRow][currColumn] != -1) return dp[currRow][currColumn];
    
    int totalWays  = getAns(currRow+1,currColumn,m,n,dp)+getAns(currRow,currColumn+1,m,n,dp);//one time going right and one time going down
        return dp[currRow][currColumn] = totalWays;
}
};


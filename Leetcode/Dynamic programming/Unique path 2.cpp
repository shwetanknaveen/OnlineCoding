//Problem link - https://leetcode.com/problems/unique-paths-ii/

//Here no need of visited matrix as we are allowed to move only in right and down direction and in such case there is no possibility that
//a recursion call will come back to same cell and will fall in infinite loop
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return getAns(obstacleGrid,0,0,m,n,dp);
        //for m x n vector vect, m=vect.size() and n=vect[0].size()
    }
    
    int getAns(vector<vector<int>> &obstacleGrid,int currRow,int currColumn,int m,int n,vector<vector<int>> &dp)
	{
    
    if(currRow>m-1 || currColumn>n-1 || obstacleGrid[currRow][currColumn] == 1) return 0;
	/*found obstacle or limits exceeding. Here obstacleGrid[currRow][currColumn] == '*' won't cause out of bound exception as
	 before that currRow>m || currColumn>n would have evaluated true hence obstacleGrid[currRow][currColumn] == '*' won't be 
	 evaluated. Here returning 0 as this is not the way to reach bottom right.Here destination block also can't be 1 so put this 
	 base condition earlier*/
    if(currRow==m-1 && currColumn == n-1)
    {
        return 1;//reached bottom right column then this is one way to reach here
    }
    
    	
    if(dp[currRow][currColumn] != -1) return dp[currRow][currColumn];
    
    int totalWays  = getAns(obstacleGrid,currRow+1,currColumn,m,n,dp)+getAns(obstacleGrid,currRow,currColumn+1,m,n,dp);//one time going right and one time going down
        return dp[currRow][currColumn] = totalWays;
}
};

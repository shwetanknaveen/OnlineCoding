//Problem link - https://leetcode.com/problems/dungeon-game/

//dp[i][j] means that how much minimum life needed so that from this cell,we can reach destination and remain alive
class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &dungeon,vector<vector<int>> &dp,int &row,int &cols)
    {
        if(i<0 || i>=row || j<0 || j>=cols) return INT_MAX;//infinite life needed to reach to destination from outside dungeon
        if(i==row-1 && j==cols-1) return dungeon[i][j]<0?(-dungeon[i][j]+1):1;
        							//if reached dungeon then it should be alive. So if final cell has negative point then one more point
        							//than absoulute value of it will be needed so that it remains alive. Otherwise it should just come alive
        							//with life = 1 and it will remain alive in the destination cell
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int right = solve(i,j+1,dungeon,dp,row,cols);//minimum life required when going on right path
        int down = solve(i+1,j,dungeon,dp,row,cols);//minimum life required when going on down path
        
        //No DFS call will fall in infinite loop as movement is restricted to right and down direction only
        
        int lifeReqFromThisCell = min(right,down) - dungeon[i][j];//after getting answers from right and left path, we have to subtract value
        													//at this cell because for e.g., suppose this cell has value 4 so it will boost
        													//life by 4 hence in order to get minimum life required, we have to subtract 4
        													//similarily if this cell is -4 hence it will add (-(-4)) as this cell itself 
        													//will consume life of 4 points
        return dp[i][j] = lifeReqFromThisCell<=0 ? 1 : lifeReqFromThisCell;
        				//if lifeReqFromThisCell is somehow coming to be -ve or 0 it means there is no additional life required to boost 
        				//from this cell because all the cells in the path are positive hence in such case it is just required that we
        				//land up at this cell with minimum life of 1 point
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size(), cols = dungeon[0].size();
        vector<vector<int>> dp(row,vector<int>(cols,-1));
        return solve(0,0,dungeon,dp,row,cols);
    }
};

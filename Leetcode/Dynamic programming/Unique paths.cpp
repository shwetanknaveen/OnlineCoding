//Problem link - https://leetcode.com/problems/unique-paths/submissions/
//Video link - https://www.youtube.com/watch?v=t_f0nwwdg5o&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=18

//Time and space complexity - O(mn)
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

//MOST EFFICIENT ALGO
/*
Total turns to be taken is (m+n-2) (Down = no. of rows -1)(Right = no. of columns -1)
So ans would be (m+n-2)C(m-1) or (m+n-2)C(n-1)
*/
//Time complexity - O(min(m,n))
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N= m+n-2, R=min(m,n)-1;
        double ans = 1;
        for(int i=1;i<=R;i++)
        {
            //ans = ans * (N-i)/(R-i); DON'T USE THIS FORMULA
            ans =ans * (N-R+i)/i;   //DON'T USE COMPOUND OPERATOR HERE
        }
        return int(ans);
    }
};


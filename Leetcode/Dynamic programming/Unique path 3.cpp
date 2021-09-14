//Problem link - https://leetcode.com/problems/unique-paths-iii/submissions/

//In this question we have to reach destination 2 but after travelling through all zeroes exaclty ones
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int empty = 1;//It counts no. of zeroes.We pass it empty + 1 (i.e., intiallise empty = 1) because suppose target is
        			//adjacent to source in 2 x 1 or 1 x2 grid then in that case no 0 will be required and we go in getAns()
        			//with start location which will decrease the value of empty hence we can't go with empty = 0, with start
        			//location in the getAns() function
        int ans = 0;
        int start_i,start_j;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    start_i = i;
                    start_j = j;
                }
                else if(grid[i][j]==0)
                {
                    empty++;
                }
            }
        }
        getAns(grid,start_i,start_j,m,n,empty,ans);
        return ans;
    }
    void getAns(vector<vector<int>> &grid,int currRow,int currColumn,int m,int n,int &empty,int &ans)
	{
    
    if(currRow>m-1 || currRow<0 || currColumn>n-1 || currColumn<0 || grid[currRow][currColumn] == -1)
    {
        return;//found obstacle or travelling outside grid
    }
    if(grid[currRow][currColumn]==2)
    {
        if(empty==0)//if reached destination with no 0 left untravelled then we increase the value of ans
        ans++;
        return;
    }
    
    --empty;//while exploring this path, this zero has been used
    grid[currRow][currColumn] = -1;//exploring this path, mark this cell visited so that infinite loop won't get formed
    getAns(grid,currRow+1,currColumn,m,n,empty,ans);//go down
    getAns(grid,currRow-1,currColumn,m,n,empty,ans);//go up
    getAns(grid,currRow,currColumn+1,m,n,empty,ans);//go right
    getAns(grid,currRow,currColumn-1,m,n,empty,ans);//go left
    grid[currRow][currColumn] = 0;//this path has been explored , so now to allow other paths to get explored we remove the 
    								//mark from this cell as visited
    ++empty;//same with empty. When explored this path with this cell, the we increase back the value of empty
    
	}
};
